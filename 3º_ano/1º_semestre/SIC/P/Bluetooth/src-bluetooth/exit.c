#include <gio/gio.h>

#include "exit.h"

/*
 * Generic function to exit and cleanup valid values
 */
void
exit_on_error ( GDBusConnection * bus, GError * error, int return_error )
{
    g_error_free( error);
    if (bus) g_object_unref( bus );

    exit( return_error );
}
