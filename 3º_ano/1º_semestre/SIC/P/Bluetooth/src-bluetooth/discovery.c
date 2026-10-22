#include <gio/gio.h>

#include "discovery.h"

GVariant *
start_discovery( GDBusConnection * bus, GError ** error )
{
    /*
     * Start BLE discovery.
     */
    return g_dbus_connection_call_sync( bus,
                                        "org.bluez", // Bus name (sender)
                                        "/org/bluez/hci0", // Path to the object to call
                                        "org.bluez.Adapter1", // Object interface to use
                                        "StartDiscovery", // Interface method to be called
                                        NULL, // Method parameters (none)
                                        NULL, // Reply type (NULL if none)
                                        G_DBUS_CALL_FLAGS_NONE, // Call flags
                                        -1, // Timeout (none if negative)
                                        NULL, // Cancellable (NONE if not)
                                        error // Error feedback
                                        );
}

GVariant *
stop_discovery( GDBusConnection * bus, GError ** error )
{
    /*
     * Stop the device scanning and clean up
     */
    return g_dbus_connection_call_sync( bus,
                                        "org.bluez", // Bus name (sender)
                                        "/org/bluez/hci0", // Path to the object to call
                                        "org.bluez.Adapter1", // Object interface to use
                                        "StopDiscovery", // Interface method to be called
                                        NULL, // Method parameters (none)
                                        NULL, // Reply type (NULL if none)
                                        G_DBUS_CALL_FLAGS_NONE, // Call flags
                                        -1, // Timeout (none if negative)
                                        NULL, // Cancellable (NONE if not)
                                        error // Error feedback
                                        );
}
