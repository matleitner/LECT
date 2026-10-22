int subscribe_new_interfaces( GDBusConnection * bus, GDBusSignalCallback callback );
int subscribe_device_properties_changed( GDBusConnection * bus, gchar * path, GDBusSignalCallback callback );
