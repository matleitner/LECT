#include <stdio.h>
#include <gio/gio.h>

#include "exit.h"
#include "dbus.h"
#include "subscribe.h"
#include "filter.h"
#include "discovery.h"
#include "connect.h"
#include "gatt.h"

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

struct connect_device {
    GDBusConnection * bus;
    gchar * path;
};

/*
 * Device properties changed watchdog
 */
static void
on_device_properties_changed( GDBusConnection * bus,
                              const gchar * sender_name, // The unique bus name of the sender of the signal (the name given to bluetoothd on D-Bus, check with busctl)
			      const gchar * object_path, // The device with are following
			      const gchar * interface_name, // The name of the interface for dealing with the event, should always be "org.freedesktop.DBus.ObjectManager"
			      const gchar * signal_name,
			      GVariant * parameters,
			      gpointer user_data )
{
    GError * error = 0;
    GVariant * result;

    result = g_dbus_connection_call_sync( bus,
					  "org.bluez",
					  object_path,
					  "org.freedesktop.DBus.Properties",
					  "Get",
					  g_variant_new( "(ss)", "org.bluez.Device1", "ServicesResolved" ),
					  G_VARIANT_TYPE( "(v)" ),
					  G_DBUS_CALL_FLAGS_NONE,
					  -1,
					  NULL,
					  &error
					  );

    if (!result) {
	fprintf( stderr, "Failed to read ServicesResolved: %s\n", error->message );
	g_error_free( error );
	return;
    }

    /*
     * Check if all the services were resolved (listed in D-Dus)
     */
    GVariant * resolved = 0;
    g_variant_get( result, "(v)", &resolved );

    if (g_variant_get_boolean( resolved )) {
	printf( "Services resolved for %s\n", object_path );
	list_gatt_services( bus, object_path, &error );

	/*
	 * Remove subscription, free user data provided
	 */

	g_dbus_connection_signal_unsubscribe( bus, *((int *) user_data) );
	g_free( user_data );
    }
    else {
	printf( "Services not yet resolved for %s\n", object_path );
	list_gatt_services( bus, object_path, &error );
    }

    unref_variant( result );
    unref_variant( resolved );
}

/*
 * Device connected watchdog
 */
static void
on_connect_done( GObject * source_object, GAsyncResult * results, gpointer _data )
{
    GError * error = 0;

    struct connect_device * data = _data;
    printf( "Got a conection for %s, proceed with service listing\n", data->path );
    list_gatt_services( data->bus, data->path, &error );

    /*
    * Subscribe a notification service to wait for all the services being listed.
    * Add the subscrption id (the return value) to the callback arguments so that it could put an end on the notifications once not useful.
    */
    int * subscription_id = g_malloc ( sizeof(int) );
    *subscription_id = subscribe_device_properties_changed( data->bus, data->path, on_device_properties_changed, subscription_id );

    g_free( _data );
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
	    GError * error = 0;

            printf( "Found device (paired: %c, bonded = %c, connected = %c, trusted = %c): %s", boolean_variant_char( paired ),
                                                                                                boolean_variant_char( bonded ),
                                                                                                boolean_variant_char( connected ),
                                                                                                boolean_variant_char( trusted ),
                                                                                                g_variant_get_string( address, NULL ) );
            if (name) printf( " (%s)", g_variant_get_string( name, NULL ) );
            printf( ", connect to it\n" );

	    /*
	     * We shouldn't synchronously connect with the device from here in order to get its services.
	     * So, we create a proxy to handle such connection asynchronously.
	     * Upon a connection (within a given timeout), its notification callback is used for proceeding with the service listing.
	     */
	    GDBusProxy * device_proxy;
	    device_proxy = g_dbus_proxy_new_for_bus_sync( G_BUS_TYPE_SYSTEM, // BlueZ is on the system bus
							  G_DBUS_PROXY_FLAGS_NONE,
						          NULL, // GDBusInterfaceInfo, usually NULL
						          "org.bluez", // bus name
						          path, // object path
						          "org.bluez.Device1", // interface
						          NULL, 
						          &error
						          );

	    if (device_proxy) {
		struct connect_device * data = g_malloc( sizeof(struct connect_device) );
		data->bus=bus;
		data->path = g_strdup( path );
		g_dbus_proxy_call( device_proxy,
				   "Connect",
				   NULL,
				   G_DBUS_CALL_FLAGS_NONE,
				   30000, // Timeout (in miliseconds)
				   NULL,
				   on_connect_done,
				   (gpointer) data
				   );
	    }
	    else {
		fprintf( stderr, "Could not get a D-Bus proxy: %s\n", error->message );
	    }
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
    GVariant *result ;

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
     * Run the main loop
     */
    g_main_loop_run( loop );

    g_main_loop_unref( loop );

    g_object_unref( bus );

    return 0;
}
