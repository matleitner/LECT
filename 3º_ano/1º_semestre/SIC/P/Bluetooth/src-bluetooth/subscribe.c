#include <gio/gio.h>

#include "subscribe.h"

/*
 * Subscribe the notification of new Bluetooth interfaces added to D-Bus.
 * An interface (remote device) is represented by a BlueZ objects.
 * This function returns an integer that can be used to remove the subscription.
 * It NEVER returns an error!
 */
int
subscribe_new_interfaces( GDBusConnection * bus, GDBusSignalCallback callback )
{
    return g_dbus_connection_signal_subscribe( bus,
                                               "org.bluez", // Bus name (sender)
                                               "org.freedesktop.DBus.ObjectManager", // Bluetooth interface object class
                                               "InterfacesAdded", // D-Bus service to subscribe
                                               NULL, // Object path to match (NULL if unused)
                                               NULL, // Parameter for matching a Name Space or a Path (NULL if unnused)
                                               G_DBUS_SIGNAL_FLAGS_NONE, // Flags for the use of the previous parameter
                                               callback, // Notifications' callback
                                               NULL, // Arbitrary user data to pass to the callback (NULL if none)
                                               NULL // function to release the memory occupied by the user data (NULL if none)
                                               );
}

/*
 * 
 */
int
subscribe_device_properties_changed( GDBusConnection * bus, gchar * path, GDBusSignalCallback callback, gpointer data )
{
    return g_dbus_connection_signal_subscribe( bus,
                                               "org.bluez", // Bus name (sender)
                                               "org.freedesktop.DBus.Properties", // Bluetooth interface object class
                                               "PropertiesChanged", // D-Bus service to subscribe
                                               path, // Object path to match (NULL if unused)
                                               NULL, // Parameter for matching a Name Space or a Path (NULL if unnused)
                                               G_DBUS_SIGNAL_FLAGS_NONE, // Flags for the use of the previous parameter
                                               callback, // Notifications' callback
                                               data, // Arbitrary user data to pass to the callback (NULL if none)
                                               NULL // function to release the memory occupied by the user data (NULL if none)
                                               );
}
