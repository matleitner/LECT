#include <stdio.h>
#include <gio/gio.h>

#include "exit.h"
#include "dbus.h"
#include "subscribe.h"
#include "filter.h"
#include "discovery.h"

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
 * Called whenever BlueZ changes a property in a device's D-Bus information
 */
 static void
on_properties_changed( GDBusConnection * bus,
                       const gchar * sender_name, // The unique bus name of the sender of the signal (the name given to bluetoothd on D-Bus, check with busctl)
		       const gchar * object_path, // Should always be "/org/bluez/hci0/dev_" followed by the MAC address in theformat XX_XX_XX_XX_XX_XX
		       const gchar * interface_name, // The name of the interface for dealing with the event, should always be "org.freedesktop.DBus.Properties"
		       const gchar * signal_name, // The name of the event, should always be "PropertiesChanged" 
		       GVariant * parameters, // A structure with the event parameters
		       gpointer user_data // Arbitrary data provided by the event subscriber
		       )
{
    const gchar *iface;
    GVariant *changed;
    GVariant *invalidated;
    const gchar * mac = object_path + strlen( object_path ) - 17; // Get MAC address from device path

    g_variant_get( parameters, "(&s@a{sv}@as)", &iface, &changed, &invalidated );

    if (g_strcmp0(iface, "org.bluez.Device1") == 0) {
        GVariantIter iter;
        const gchar *property;
        GVariant *value;

        g_variant_iter_init( &iter, changed );

        printf( "Device %s changed:", mac );
        while (g_variant_iter_next( &iter, "{&sv}", &property, &value) ) {
            gchar * str = g_variant_print( value, TRUE );
            printf( "\n\t%s (%s)", property, str );
            g_free(str);
            unref_variant( value );
        }
        printf( "\n" );
    }

    unref_variant( changed );
    unref_variant( invalidated );
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
 * Main function, App entry point
 */
int
main()
{
    GDBusConnection * bus = 0;
    GMainLoop * loop = 0;
    GError * error = 0;
    GVariant * result ;

    /*
     * Get D-Bus handle
     */
    bus = get_dbus_handle( &error );

    if (!bus) {
        fprintf( stderr, "Could not get a D-Bus handle: %s\n", error->message );
        exit_on_error( bus, error, 1 );
    }

    /*
     * Subcribe the service that provides notifications about new interfaces
     * Subcribe the service that provides notifications about changed properties.
     * The first NULL parameter in this subscription means ALL devices, not a single one (that could be indicated here)
     * The second NULL parameter means no user data is provided in the callback
     */
    (void) subscribe_new_interfaces( bus, on_interfaces_added ); 
    (void) subscribe_device_properties_changed( bus, NULL, on_properties_changed, NULL ); 

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
     * Run the main loop
     */
    g_main_loop_run( loop );

    g_main_loop_unref( loop );
    g_object_unref( bus );

    return 0;
}
