#include <glib.h>

#ifndef BD_MPATH
#define BD_MPATH

#define MULTIPATH_MIN_VERSION "0.4.9"

GQuark bd_mpath_error_quark (void);
#define BD_MPATH_ERROR bd_mpath_error_quark ()
typedef enum {
    BD_MPATH_ERROR_FLUSH,
    BD_MPATH_ERROR_NOT_ROOT,
    BD_MPATH_ERROR_DM_ERROR,
    BD_MPATH_ERROR_INVAL,
} BDMpathError;

/*
 * If using the plugin as a standalone library, the following functions should
 * be called to:
 *
 * check_deps() - check plugin's dependencies, returning TRUE if satisfied
 * init()       - initialize the plugin, returning TRUE on success
 * close()      - clean after the plugin at the end or if no longer used
 *
 */
gboolean bd_mpath_check_deps ();
gboolean bd_mpath_init ();
void bd_mpath_close ();

gboolean bd_mpath_flush_mpaths (GError **error);
gboolean bd_mpath_is_mpath_member (const gchar *device, GError **error);
gchar** bd_mpath_get_mpath_members (GError **error);
gboolean bd_mpath_set_friendly_names (gboolean enabled, GError **error);

#endif  /* BD_MPATH */
