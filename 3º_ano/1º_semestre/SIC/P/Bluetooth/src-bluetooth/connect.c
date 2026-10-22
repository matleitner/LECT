#include <stdio.h>
#include <gio/gio.h>

#include "connect.h"

GVariant *
connect_device( GDBusConnection *bus, const gchar * device, int timeout, GError **error )
{
    printf( "%s\n", device );
    return g_dbus_connection_call_sync( bus,
					"org.bluez", // Bus name (sender)
					device,
                                        "org.bluez.Device1", // Object interface to use
					"Connect",
					NULL,
					NULL,
					G_DBUS_CALL_FLAGS_NONE,
					timeout,
					NULL,
					error );
}
