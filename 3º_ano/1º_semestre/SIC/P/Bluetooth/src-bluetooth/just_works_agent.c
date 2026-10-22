#include <gio/gio.h>
#include <stdio.h>
#include <stdlib.h>

static const gchar introspection_xml[] =
    "<node>"
    "  <interface name='org.bluez.Agent1'>"
    "    <method name='Release'/>"

    "    <method name='RequestPinCode'>"
    "      <arg name='device' type='o' direction='in'/>"
    "      <arg name='pincode' type='s' direction='out'/>"
    "    </method>"

    "    <method name='DisplayPinCode'>"
    "      <arg name='device' type='o' direction='in'/>"
    "      <arg name='pincode' type='s' direction='in'/>"
    "    </method>"

    "    <method name='RequestPasskey'>"
    "      <arg name='device' type='o' direction='in'/>"
    "      <arg name='passkey' type='u' direction='out'/>"
    "    </method>"

    "    <method name='DisplayPasskey'>"
    "      <arg name='device' type='o' direction='in'/>"
    "      <arg name='passkey' type='u' direction='in'/>"
    "      <arg name='entered' type='q' direction='in'/>"
    "    </method>"

    "    <method name='RequestConfirmation'>"
    "      <arg name='device' type='o' direction='in'/>"
    "      <arg name='passkey' type='u' direction='in'/>"
    "    </method>"

    "    <method name='RequestAuthorization'>"
    "      <arg name='device' type='o' direction='in'/>"
    "    </method>"

    "    <method name='AuthorizeService'>"
    "      <arg name='device' type='o' direction='in'/>"
    "      <arg name='uuid' type='s' direction='in'/>"
    "    </method>"

    "    <method name='Cancel'/>"
    "  </interface>"
    "</node>";

static void handle_agent_method_call( GDBusConnection * bus,
                                      const gchar *sender,
                                      const gchar *object_path,
                                      const gchar *interface_name,
                                      const gchar *method_name,
                                      GVariant *parameters,
                                      GDBusMethodInvocation *invocation,
                                      gpointer user_data
)
{
    const gchar * device = NULL;

    printf( "JustWorks Agent called\n" );

    if (g_strcmp0( method_name, "Release" ) == 0) {
        printf( "Agent released by BlueZ\n" );
        g_dbus_method_invocation_return_value( invocation, NULL );
        return;
    }

    if (g_strcmp0( method_name, "Cancel" ) == 0) {
        g_variant_get( parameters, "(&o)", &device );

        printf( "Pairing request with %s cancelled\n", object_path );
        g_dbus_method_invocation_return_value( invocation, NULL );
        return;
    }

    if (g_strcmp0( method_name, "RequestAuthorization" ) == 0) {
        const gchar * device = NULL;
        g_variant_get( parameters, "(&o)", &device );

        printf( "Authorizing pairing with device: %s\n", device );

        /*
         * Returning without an error means accepting the pairing.
         */
        g_dbus_method_invocation_return_value( invocation, NULL );
        return;
    }

    if (g_strcmp0( method_name, "AuthorizeService" ) == 0) {
        const gchar * device = NULL;
        const gchar * uuid = NULL;

        g_variant_get( parameters, "(&o&s)", &device, &uuid );

        printf( "Authorizing service %s for device: %s\n", uuid, device );

        /*
         * Returning without an error means accepting the usage ofthe service.
         */
        g_dbus_method_invocation_return_value(invocation, NULL);
        return;
    }

    if (g_strcmp0( method_name, "RequestConfirmation" ) == 0) { 
        /*
         * With a strict JustWorks policy, we could reject this method,
         * because numeric comparison is not JustWorks. But there isnoharm in accepting it...
         */
        const gchar * device = NULL;
        guint32 passkey = 0;

        g_variant_get( parameters, "(&ou)", &device, &passkey );

        printf( "Auto-confirming pairing with device: %s, passkey: %06u\n", device, passkey );

        /*
         * Returning success confirms the pairing.
         *
         */
        g_dbus_method_invocation_return_value( invocation, NULL );
        return;
    }

    if (g_strcmp0( method_name, "DisplayPinCode" ) == 0) {
        const gchar * device = NULL;
        const gchar * pincode = NULL;

        g_variant_get( parameters, "(&o&s)", &device, &pincode );

        printf( "BlueZ requested DisplayPinCode for device %s: %s\n", device, pincode );

        g_dbus_method_invocation_return_value( invocation, NULL );
        return;
    }

    if (g_strcmp0( method_name, "DisplayPasskey" ) == 0) {
        const gchar * device = NULL;
        guint32 passkey = 0;
        guint16 entered = 0;

        g_variant_get( parameters, "(&ouq)", &device, &passkey, &entered );

        printf( "BlueZ requested DisplayPasskey for device %s: %06u, entered: %u\n", device, passkey, entered );

        g_dbus_method_invocation_return_value( invocation, NULL );
        return;
    }

    /*
     * Since this agent is NoInputNoOutput, it cannot provide PINs or passkeys.
     */
    if (g_strcmp0( method_name, "RequestPinCode" ) == 0 ||
        g_strcmp0( method_name, "RequestPasskey" ) == 0) {

        printf("Rejecting %s because agent is NoInputNoOutput\n", method_name);

        g_dbus_method_invocation_return_dbus_error( invocation, "org.bluez.Error.Rejected", "No PIN/passkey input available" );
        return;
    }

    g_dbus_method_invocation_return_dbus_error( invocation, "org.bluez.Error.Rejected", "Unsupported Agent1 method" );
}

static const GDBusInterfaceVTable agent_vtable = {
    .method_call = handle_agent_method_call,
    .get_property = NULL,
    .set_property = NULL
};

guint
register_just_works_agent_object( GDBusConnection * bus, char * agent_path, GError ** error )
{
    guint registration_id;
    GDBusNodeInfo *introspection_data = NULL;

    introspection_data = g_dbus_node_info_new_for_xml( introspection_xml, error );

    if (!introspection_data) {
        fprintf( stderr, "Could not parse introspection XML: %s\n", (*error)->message );
        return 0;
    }

    registration_id = g_dbus_connection_register_object( bus,
                                                         agent_path,
                                                         introspection_data->interfaces[0],
                                                         &agent_vtable,
                                                         NULL,
                                                         NULL,
                                                         error
                                                         );

    if (!registration_id) {
        fprintf( stderr, "Could not register agent object: %s\n", (*error)->message );
        g_dbus_node_info_unref( introspection_data );
        return 0;
    }
}
