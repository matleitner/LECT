#include <stdio.h>
#include <signal.h>
#include <gio/gio.h>

#include "exit.h"
#include "dbus.h"
#include "subscribe.h"
#include "filter.h"
#include "discovery.h"

GMainLoop * loop = 0;

/*
 * Function to free valid (non-null) variants
 */
static void
unref_variant ( GVariant * variant )
{
    if (variant) g_variant_unref( variant );
}

/*
 * Function to provide a y/n character given a Boolean variant
 */
static char
boolean_variant_char ( GVariant * value )
{
    return g_variant_get_boolean( value ) ? 'y' : 'n';
}

/*
 * Called whenever BlueZ addeds a new device to D-Bus
 */
static void
on_interfaces_added( GDBusConnection * bus,
                     const gchar * sender_name, // The unique bus name of the sender of the signal (the name given to bluetoothd on D-Bus, check with busctl)
		     const gchar * object_path, // Should always be "/"
		     const gchar * interface_name, // The name of the interface for dealing with the event, should always be "org.freedesktop.DBus.ObjectManager"
		     const gchar * signal_name, // The name of the event, should always be "InterfacesAdded" 
		     GVariant * parameters, // A structure with the event parameters
		     gpointer user_data // Arbitrary data provided by the event subscriber
		     )
{
    const gchar * path;
    GVariant * interfaces;
    GVariant * device;

    /*
     * The structure of org.freedesktop.DBus.ObjectManager is
     *    path (reference for an object, refered as o)
     *    interfaces (a dictionary with {string, dictionary with string + value tuples} elements, referred as a{sa{sv}))
     * The & in the format string returns a copy of the object path
     * The @ in theformat string returns a GVariant value with the interfaces
     */
    g_variant_get( parameters, "(&o@a{sa{sv}})", &path, &interfaces );

    /*
     * Use the interface "org.bluez.Device1" that should be found in interfaces
     * to get a GVariant dictionary describing the device added
     */
    device = g_variant_lookup_value( interfaces, "org.bluez.Device1", G_VARIANT_TYPE_VARDICT );

    if (device) {
        GVariant * address = g_variant_lookup_value( device, "Address", G_VARIANT_TYPE_STRING );
        GVariant * name = g_variant_lookup_value( device, "Name", G_VARIANT_TYPE_STRING );
        GVariant * paired = g_variant_lookup_value( device, "Paired", G_VARIANT_TYPE_BOOLEAN );
        GVariant * bonded = g_variant_lookup_value( device, "Bonded", G_VARIANT_TYPE_BOOLEAN );
        GVariant * connected = g_variant_lookup_value( device, "Connected", G_VARIANT_TYPE_BOOLEAN );
        GVariant * trusted = g_variant_lookup_value( device, "Trusted", G_VARIANT_TYPE_BOOLEAN );

        if (address) {
            printf( "Found device (paired: %c, bonded = %c, connected = %c, trusted = %c): %s", boolean_variant_char( paired ),
                                                                                                boolean_variant_char( bonded ),
                                                                                                boolean_variant_char( connected ),
                                                                                                boolean_variant_char( trusted ),
                                                                                                g_variant_get_string( address, NULL ) );
            if (name) printf( " (%s)", g_variant_get_string( name, NULL ) );
            printf( "\n" );
        }

        unref_variant( address );
        unref_variant( name );
        unref_variant( device );
    }

    unref_variant( interfaces );
}

/*
 * Alarm callback, stop the current (scanning) loop
 */
void
timeout( int signal )
{
     g_main_loop_quit( loop );
}

/*
 * Main function, App entry point
 */
int
main()
{
    GDBusConnection * bus = 0;
    GVariant * result ;
    GError * error = 0;

    /*
     * Get D-Bus handle
     */
    bus = get_dbus_handle( &error );

    if (!bus) {
        fprintf( stderr, "Could not get a D-Bus handle: %s\n", error->message );
        exit_on_error( bus, error, 1 );
    }

    /*
     * Subcribe the service thatprovides notifications about new interfaces
     */
    (void) subscribe_new_interfaces( bus, on_interfaces_added ); 

    /*
     * Install a discover filter
     */
    result = install_filter( bus, "auto", &error );

    if (!result) {
        fprintf( stderr, "Installation of discover filter failed: %s\n", error->message );
        exit_on_error( bus, error, 1 );
    }

    unref_variant( result );

    /*
     * Start discovery.
     */
    result = start_discovery( bus, &error );

    if (!result) {
        fprintf( stderr, "Discovery failed to start: %s\n", error->message );
        exit_on_error( bus, error, 1 );
    }

    unref_variant(result);

    printf( "Scanning for devices...\n" );
    printf( "Press Ctrl+C to stop.\n");

    /*
     * GDBus is asynchronous, so we need a GLib main loop
     * to receive InterfacesAdded signals.
     */
    loop = g_main_loop_new( NULL, FALSE );
    
    /*
     * Set alarme handler and start the alarm from some seconds from now
     */
    signal( SIGALRM, timeout );
    alarm( 20 );

    /*
     * Run the main loop
     */
    g_main_loop_run( loop );

    /*
    * Stop the scanning
    */
    result = stop_discovery( bus, &error );

    if (!result) {
        fprintf( stderr, "Discovery failed to stop: %s\n", error->message );
        exit_on_error( bus, error, 1 );
    }

    g_main_loop_unref( loop );
    g_object_unref( bus );

    return 0;
}
