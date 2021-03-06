/* Generated by dbus-binding-tool; do not edit! */

#include <glib.h>
#include <dbus/dbus-glib.h>

G_BEGIN_DECLS

#ifndef DBUS_GLIB_CLIENT_WRAPPERS_atech_e99_mpl_shm
#define DBUS_GLIB_CLIENT_WRAPPERS_atech_e99_mpl_shm

static
#ifdef G_HAVE_INLINE
inline
#endif
gboolean
atech_e99_mpl_shm_add_member (DBusGProxy *proxy, const GPtrArray* IN_memberdetails1, gint* OUT_response, GError **error)

{
  return dbus_g_proxy_call (proxy, "AddMember", error, dbus_g_type_get_collection ("GPtrArray", dbus_g_type_get_struct ("GValueArray", G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INVALID)), IN_memberdetails1, G_TYPE_INVALID, G_TYPE_INT, OUT_response, G_TYPE_INVALID);
}

typedef void (*atech_e99_mpl_shm_add_member_reply) (DBusGProxy *proxy, gint OUT_response, GError *error, gpointer userdata);

static void
atech_e99_mpl_shm_add_member_async_callback (DBusGProxy *proxy, DBusGProxyCall *call, void *user_data)
{
  DBusGAsyncData *data = (DBusGAsyncData*) user_data;
  GError *error = NULL;
  gint OUT_response;
  dbus_g_proxy_end_call (proxy, call, &error, G_TYPE_INT, &OUT_response, G_TYPE_INVALID);
  (*(atech_e99_mpl_shm_add_member_reply)data->cb) (proxy, OUT_response, error, data->userdata);
  return;
}

static
#ifdef G_HAVE_INLINE
inline
#endif
DBusGProxyCall*
atech_e99_mpl_shm_add_member_async (DBusGProxy *proxy, const GPtrArray* IN_memberdetails1, atech_e99_mpl_shm_add_member_reply callback, gpointer userdata)

{
  DBusGAsyncData *stuff;
  stuff = g_new (DBusGAsyncData, 1);
  stuff->cb = G_CALLBACK (callback);
  stuff->userdata = userdata;
  return dbus_g_proxy_begin_call (proxy, "AddMember", atech_e99_mpl_shm_add_member_async_callback, stuff, g_free, dbus_g_type_get_collection ("GPtrArray", dbus_g_type_get_struct ("GValueArray", G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INVALID)), IN_memberdetails1, G_TYPE_INVALID);
}
#endif /* defined DBUS_GLIB_CLIENT_WRAPPERS_atech_e99_mpl_shm */

G_END_DECLS
