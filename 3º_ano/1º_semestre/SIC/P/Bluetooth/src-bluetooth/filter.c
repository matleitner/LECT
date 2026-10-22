#include <stdio.h>
#include <gio/gio.h>

#include "filter.h"

GVariant *
install_filter( GDBusConnection * bus, char * bluetooth_transport, GError ** error )
{
    /*
     * Create a DiscoveryFilter:
     *   Transport = "le"
     * This tells BlueZ that we only want to find BLE devices.
     * A (key, value) tupple is first created, with a string key ("Transport") and a Variant value (in our case, a strig, "le").
     * This tupple is added to a Variant dictionary.
     */
    GVariantBuilder filter;

    g_variant_builder_init( &filter, G_VARIANT_TYPE_VARDICT );
    g_variant_builder_add( &filter, "{sv}", "Transport", g_variant_new_string( bluetooth_transport ) );
    g_variant_builder_add( &filter, "{sv}", "DuplicateData", g_variant_new_boolean( TRUE ) );

    printf( "Installed a \"%s\" transport filter\n", bluetooth_transport );
    printf( "Installed a \"no duplicate data\" filter\n" );

    /*
     * Install the discover filter associated with the hci0 Bluetooth device.
     */
    return g_dbus_connection_call_sync( bus,
                                        "org.bluez", // Bus name (sender)
                                        "/org/bluez/hci0", // Path to the object to call
                                        "org.bluez.Adapter1", // Object interface to use
                                        "SetDiscoveryFilter", // Interface method to be called
                                        g_variant_new( "(a{sv})", &filter ), // Method parameters. \
                                                                                This is a tupple, where each member is a parameter. \
                                                                                We only have one parameter, the filter. \
                                                                                It is described as a dictionary of (string, Variant) \
                                                                                key-value pairs.
                                        NULL, // Reply type (NULL if none)
                                        G_DBUS_CALL_FLAGS_NONE, // Call flags
                                        -1, // Timeout (none if negative)
                                        NULL, // Cancellable (NONE if not)
                                        error // Error feedback
                                        );
}
