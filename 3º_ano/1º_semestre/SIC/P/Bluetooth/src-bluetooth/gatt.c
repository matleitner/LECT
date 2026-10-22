#include <stdio.h>
#include <string.h>
#include <gio/gio.h>

#include "gatt.h"

void
list_gatt_services( GDBusConnection * bus, const char * device_path, GError ** error )
{
    GVariant *reply;
    GVariantIter *objects;
    const char *path;
    GVariant *interfaces;

    reply = g_dbus_connection_call_sync( bus,
                                         "org.bluez", // Bus name (sender)
					 "/",
					 "org.freedesktop.DBus.ObjectManager",
					 "GetManagedObjects",
					 NULL,
					 G_VARIANT_TYPE("(a{oa{sa{sv}}})"),
					 G_DBUS_CALL_FLAGS_NONE,
					 -1,
					 NULL,
					 error );

    if (!reply) return;

    printf( "Device %s services:\n", device_path );

    g_variant_get( reply, "(a{oa{sa{sv}}})", &objects );

    /*
     * Iterate over the list of objects returned, extracting their path and list of interfaces
     */
    while (g_variant_iter_next( objects, "{&o@a{sa{sv}}}", &path, &interfaces ) ) {
        GVariant * iface_props;

	/*
	 * Filter by our path of interest
	 */
        if (!g_str_has_prefix( path, device_path )) {
            g_variant_unref( interfaces );
            continue;
        }

	/*
	 * Filter by the interface "org.bluez.Device1", which allows us to list the services
	 */
        if (!g_variant_lookup( interfaces, "org.bluez.Device1", "@a{sv}", &iface_props) ) {
            g_variant_unref( interfaces );
            continue;
        }

        GVariant * uuids;

        if (!g_variant_lookup( iface_props, "UUIDs", "@as", &uuids )) {
	    printf( "\tNo services\n" );
        }
	else {
            gsize n;
	    const gchar ** uuid_strings = g_variant_get_strv( uuids, &n );

	    for (gsize i= 0; i < n; i++) {
		printf( "\tUUID %s\n", uuid_strings[i] );
	    }
	    g_variant_unref( uuids );
	    g_free( uuid_strings );
	}

        g_variant_unref( interfaces );
        g_variant_unref( iface_props );
    }

    g_variant_iter_free( objects );
    g_variant_unref( reply );
}
