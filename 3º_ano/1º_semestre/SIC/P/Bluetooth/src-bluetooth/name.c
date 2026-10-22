#include <stdio.h>
#include <gio/gio.h>

#include "exit.h"
#include "dbus.h"

/*
 * Function to free valid (non-null) variants
 */
static void
unref_variant ( GVariant * variant )
{
    if (variant) g_variant_unref( variant );
}

/*
 * Main function, App entry point
 */
int
main( int argc, char* argv[])
{
    GDBusConnection * bus = 0;
    GMainLoop * loop = 0;
    GError *error = NULL;
    GVariant *result ;

    if (argc > 2) {
        fprintf( stderr, "Usage: %s [adapter_name]\n", argv[0] );
        exit( 2 );
    }

    /*
     * Get D-Bus handle
     */
    bus = get_dbus_handle( &error );

    if (!bus) {
        fprintf( stderr, "Could not get a D-Bus handle: %s\n", error->message );
        exit_on_error( bus, error, 1 );
    }

    if (argc == 1) { // Get name
        result = g_dbus_connection_call_sync( bus,
                                              "org.bluez", // Bus name
                                              "/org/bluez/hci0", // Object path
                                              "org.freedesktop.DBus.Properties", // Interface
                                              "Get", // Method
                                              g_variant_new( "(ss)", "org.bluez.Adapter1", "Alias" ), // Parameter
                                              G_VARIANT_TYPE("(v)"), // Type of the return value expected
                                              G_DBUS_CALL_FLAGS_NONE,
                                              -1, // No timeout
                                              NULL,
                                              &error
                                              );
    } else { // Set name
        result = g_dbus_connection_call_sync( bus,
                                              "org.bluez", // Bus name
                                              "/org/bluez/hci0", // Object path
                                              "org.freedesktop.DBus.Properties", // Interface
                                              "Set", // Method
                                              g_variant_new( "(ssv)", "org.bluez.Adapter1", "Alias", g_variant_new_string( argv[1] ) ), // Parameter
                                              NULL, // no return value expected
                                              G_DBUS_CALL_FLAGS_NONE,
                                              -1, // No timeout
                                              NULL,
                                              &error
                                              );
    }

    if (!result) {
        fprintf( stderr, "Failed to get/set Bluetooth adapter name: %s\n", error->message );
        exit_on_error( bus, error, 1 );
    }

    if (argc == 1) {
        GVariant * value = 0;
        const char * actual_name;

        g_variant_get( result, "(v)", &value );
        actual_name = g_variant_get_string( value, 0 );
        printf( "Bluetooth adapter name: %s\n", actual_name );

        unref_variant( value );
    }
    else {
        printf( "Bluetooth adapter name changed to: %s\n", argv[1] );

    }

    unref_variant( result );
    g_object_unref( bus );

    return 0;
}
