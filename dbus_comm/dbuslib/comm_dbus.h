/*
 * Generated by gdbus-codegen 2.55.1. DO NOT EDIT.
 *
 * The license of this code is the same as for the D-Bus interface description
 * it was derived from.
 */

#ifndef __COMM_DBUS_H__
#define __COMM_DBUS_H__

#include <gio/gio.h>

G_BEGIN_DECLS


/* ------------------------------------------------------------------------ */
/* Declarations for atech.e99.mpl.shm */

#define COMM_TYPE_ATECH_E99_MPL_SHM (comm_atech_e99_mpl_shm_get_type ())
#define COMM_ATECH_E99_MPL_SHM(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), COMM_TYPE_ATECH_E99_MPL_SHM, commAtechE99MplShm))
#define COMM_IS_ATECH_E99_MPL_SHM(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), COMM_TYPE_ATECH_E99_MPL_SHM))
#define COMM_ATECH_E99_MPL_SHM_GET_IFACE(o) (G_TYPE_INSTANCE_GET_INTERFACE ((o), COMM_TYPE_ATECH_E99_MPL_SHM, commAtechE99MplShmIface))

struct _commAtechE99MplShm;
typedef struct _commAtechE99MplShm commAtechE99MplShm;
typedef struct _commAtechE99MplShmIface commAtechE99MplShmIface;

struct _commAtechE99MplShmIface
{
  GTypeInterface parent_iface;



  gboolean (*handle_add_member) (
    commAtechE99MplShm *object,
    GDBusMethodInvocation *invocation,
    GVariant *arg_memberdetails1,
    GVariant *arg_memberdetails2);

  gboolean  (*get_verbose) (commAtechE99MplShm *object);

  void (*changes_notification) (
    commAtechE99MplShm *object,
    gint arg_member_id,
    guint arg_change);

};

GType comm_atech_e99_mpl_shm_get_type (void) G_GNUC_CONST;

GDBusInterfaceInfo *comm_atech_e99_mpl_shm_interface_info (void);
guint comm_atech_e99_mpl_shm_override_properties (GObjectClass *klass, guint property_id_begin);


/* D-Bus method call completion functions: */
void comm_atech_e99_mpl_shm_complete_add_member (
    commAtechE99MplShm *object,
    GDBusMethodInvocation *invocation,
    gint response);



/* D-Bus signal emissions functions: */
void comm_atech_e99_mpl_shm_emit_changes_notification (
    commAtechE99MplShm *object,
    gint arg_member_id,
    guint arg_change);



/* D-Bus method calls: */
void comm_atech_e99_mpl_shm_call_add_member (
    commAtechE99MplShm *proxy,
    GVariant *arg_memberdetails1,
    GVariant *arg_memberdetails2,
    GCancellable *cancellable,
    GAsyncReadyCallback callback,
    gpointer user_data);

gboolean comm_atech_e99_mpl_shm_call_add_member_finish (
    commAtechE99MplShm *proxy,
    gint *out_response,
    GAsyncResult *res,
    GError **error);

gboolean comm_atech_e99_mpl_shm_call_add_member_sync (
    commAtechE99MplShm *proxy,
    GVariant *arg_memberdetails1,
    GVariant *arg_memberdetails2,
    gint *out_response,
    GCancellable *cancellable,
    GError **error);



/* D-Bus property accessors: */
gboolean comm_atech_e99_mpl_shm_get_verbose (commAtechE99MplShm *object);
void comm_atech_e99_mpl_shm_set_verbose (commAtechE99MplShm *object, gboolean value);


/* ---- */

#define COMM_TYPE_ATECH_E99_MPL_SHM_PROXY (comm_atech_e99_mpl_shm_proxy_get_type ())
#define COMM_ATECH_E99_MPL_SHM_PROXY(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), COMM_TYPE_ATECH_E99_MPL_SHM_PROXY, commAtechE99MplShmProxy))
#define COMM_ATECH_E99_MPL_SHM_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), COMM_TYPE_ATECH_E99_MPL_SHM_PROXY, commAtechE99MplShmProxyClass))
#define COMM_ATECH_E99_MPL_SHM_PROXY_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), COMM_TYPE_ATECH_E99_MPL_SHM_PROXY, commAtechE99MplShmProxyClass))
#define COMM_IS_ATECH_E99_MPL_SHM_PROXY(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), COMM_TYPE_ATECH_E99_MPL_SHM_PROXY))
#define COMM_IS_ATECH_E99_MPL_SHM_PROXY_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), COMM_TYPE_ATECH_E99_MPL_SHM_PROXY))

typedef struct _commAtechE99MplShmProxy commAtechE99MplShmProxy;
typedef struct _commAtechE99MplShmProxyClass commAtechE99MplShmProxyClass;
typedef struct _commAtechE99MplShmProxyPrivate commAtechE99MplShmProxyPrivate;

struct _commAtechE99MplShmProxy
{
  /*< private >*/
  GDBusProxy parent_instance;
  commAtechE99MplShmProxyPrivate *priv;
};

struct _commAtechE99MplShmProxyClass
{
  GDBusProxyClass parent_class;
};

GType comm_atech_e99_mpl_shm_proxy_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (commAtechE99MplShmProxy, g_object_unref)
#endif

void comm_atech_e99_mpl_shm_proxy_new (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
commAtechE99MplShm *comm_atech_e99_mpl_shm_proxy_new_finish (
    GAsyncResult        *res,
    GError             **error);
commAtechE99MplShm *comm_atech_e99_mpl_shm_proxy_new_sync (
    GDBusConnection     *connection,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);

void comm_atech_e99_mpl_shm_proxy_new_for_bus (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GAsyncReadyCallback  callback,
    gpointer             user_data);
commAtechE99MplShm *comm_atech_e99_mpl_shm_proxy_new_for_bus_finish (
    GAsyncResult        *res,
    GError             **error);
commAtechE99MplShm *comm_atech_e99_mpl_shm_proxy_new_for_bus_sync (
    GBusType             bus_type,
    GDBusProxyFlags      flags,
    const gchar         *name,
    const gchar         *object_path,
    GCancellable        *cancellable,
    GError             **error);


/* ---- */

#define COMM_TYPE_ATECH_E99_MPL_SHM_SKELETON (comm_atech_e99_mpl_shm_skeleton_get_type ())
#define COMM_ATECH_E99_MPL_SHM_SKELETON(o) (G_TYPE_CHECK_INSTANCE_CAST ((o), COMM_TYPE_ATECH_E99_MPL_SHM_SKELETON, commAtechE99MplShmSkeleton))
#define COMM_ATECH_E99_MPL_SHM_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_CAST ((k), COMM_TYPE_ATECH_E99_MPL_SHM_SKELETON, commAtechE99MplShmSkeletonClass))
#define COMM_ATECH_E99_MPL_SHM_SKELETON_GET_CLASS(o) (G_TYPE_INSTANCE_GET_CLASS ((o), COMM_TYPE_ATECH_E99_MPL_SHM_SKELETON, commAtechE99MplShmSkeletonClass))
#define COMM_IS_ATECH_E99_MPL_SHM_SKELETON(o) (G_TYPE_CHECK_INSTANCE_TYPE ((o), COMM_TYPE_ATECH_E99_MPL_SHM_SKELETON))
#define COMM_IS_ATECH_E99_MPL_SHM_SKELETON_CLASS(k) (G_TYPE_CHECK_CLASS_TYPE ((k), COMM_TYPE_ATECH_E99_MPL_SHM_SKELETON))

typedef struct _commAtechE99MplShmSkeleton commAtechE99MplShmSkeleton;
typedef struct _commAtechE99MplShmSkeletonClass commAtechE99MplShmSkeletonClass;
typedef struct _commAtechE99MplShmSkeletonPrivate commAtechE99MplShmSkeletonPrivate;

struct _commAtechE99MplShmSkeleton
{
  /*< private >*/
  GDBusInterfaceSkeleton parent_instance;
  commAtechE99MplShmSkeletonPrivate *priv;
};

struct _commAtechE99MplShmSkeletonClass
{
  GDBusInterfaceSkeletonClass parent_class;
};

GType comm_atech_e99_mpl_shm_skeleton_get_type (void) G_GNUC_CONST;

#if GLIB_CHECK_VERSION(2, 44, 0)
G_DEFINE_AUTOPTR_CLEANUP_FUNC (commAtechE99MplShmSkeleton, g_object_unref)
#endif

commAtechE99MplShm *comm_atech_e99_mpl_shm_skeleton_new (void);


G_END_DECLS

#endif /* __COMM_DBUS_H__ */
