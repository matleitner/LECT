#include <stdio.h>
#include <gio/gio.h>

#include "exit.h"
#include "dbus.h"

/*
 * Get ahandle to use D-Bus
 */
GDBusConnection * 
get_dbus_handle( GError ** error )
{
    /*
     * Synchronously get to D-Bus handle
     */
    return g_bus_get_sync( G_BUS_TYPE_SYSTEM, NULL, error );
}
