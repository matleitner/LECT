#include <gio/gio.h>

#include "set_adapter_property.h"

void
set_adapter_property_boolean( GDBusConnection * bus,
                              const char * adapter_path,
                              const char * property_name,
                              gboolean value,
                              GError **error
                              )
{
    GVariant * result;

    result = g_dbus_connection_call_sync( bus,
                                          "org.bluez",
                                          adapter_path,
                                          "org.freedesktop.DBus.Properties",
                                          "Set",
                                          g_variant_new( "(ssv)", "org.bluez.Adapter1", property_name, g_variant_new_boolean(value) ),
                                          NULL,
                                          G_DBUS_CALL_FLAGS_NONE,
                                          -1,
                                          NULL,
                                          error
                                          );

    g_variant_unref( result );
}
