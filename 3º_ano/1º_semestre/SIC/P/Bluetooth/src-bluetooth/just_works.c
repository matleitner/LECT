#include <stdio.h>
#include <gio/gio.h>

#include "exit.h"
#include "dbus.h"
#include "set_adapter_property.h"
#include "just_works_agent.h"

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

    char * agent_path = "/sic/example/justworks_agent"; // The Agent object path
    
    register_just_works_agent_object( bus, agent_path, &error );

    if (error) {
        exit_on_error( bus, error, 1 );
    }

    /*
     * To implement a JustWorks pairing policy, we need to install an agent implementing it.
     * We also need to say that the agent has no input nor output capabilities ("NoInputNoOutput").
     * Other possibilities are:
     *   "DisplayOnly": works with passkey entry (this peer forces the PIN/passkey)
     *   "DisplayYesNo": works with passkey entry and numeric confirmation
     *   "KeyboardOnly": works with passkey entry (this peer forces the PIN/passkey)
     *   "KeyboardDisplay": works with passkey entry and numeric comparison
     */
    result = g_dbus_connection_call_sync( bus,
                                          "org.bluez", // Bus name
                                          "/org/bluez", // Object
                                          "org.bluez.AgentManager1", // Interface
                                          "RegisterAgent", // Method
                                          g_variant_new("(os)", agent_path, "NoInputNoOutput"),
                                          NULL,
                                          G_DBUS_CALL_FLAGS_NONE,
                                          -1,
                                          NULL,
                                          &error
                                        );

    if (!result) {
        fprintf( stderr, "Could not register a BlueZ agent %s: %s\n", agent_path, error->message );
        exit_on_error( bus, error, 1 );
    }

    unref_variant( result );

    /*
     * Set this agant the default one.
     */

    result = g_dbus_connection_call_sync( bus,
                                          "org.bluez", // Bus name
                                          "/org/bluez", // Object
                                          "org.bluez.AgentManager1", // Interface
                                          "RequestDefaultAgent", // Method
                                          g_variant_new("(o)", agent_path ),
                                          NULL,
                                          G_DBUS_CALL_FLAGS_NONE,
                                          -1,
                                          NULL,
                                          &error
                                        );
    if (!result) {
        fprintf( stderr, "Could not make BlueZ agent %s the default one: %s\n", agent_path, error->message );
        exit_on_error( bus, error, 1 );
    }

    /*
     * Make our adapter pairable and discoverable.
     */
    set_adapter_property_boolean( bus, "/org/bluez/hci0", "Pairable", TRUE, &error );

    if (error) {
        fprintf( stderr, "Warning: Could not set adapter property Pairable to True: %s\n", error->message );
        g_clear_error(&error);
    }

    set_adapter_property_boolean( bus, "/org/bluez/hci0", "Discoverable", TRUE, &error );

    if (error) {
        fprintf( stderr, "Warning: Could not set adapter property Discoverable to True: %s\n", error->message );
        g_clear_error(&error);
    }

    printf( "Waiting for devices...\n" );
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
