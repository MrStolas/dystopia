/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <glib.h>
#include <dbus/dbus-glib.h>
#include <stdlib.h> /* exit, EXIT_FAILURE */
#include <string.h> /* strcmp */

/* Pull the common symbolic defines. */
#include "common-defs.h"

/* Pull in the client stubs that were generated with
   dbus-binding-tool */
#include "comm_client_bind.h"

/**
 * This function will be called repeatedly from within the mainloop
 * timer launch code.
 *
 * The function will start with two statically initialized variables
 * (int and double) which will be incremented after each time this
 * function runs and will use the setvalue* remote methods to set the
 * new values. If the set methods fail, program is not aborted, but an
 * message will be issued to the user describing the error.
 */
//static gboolean timerCallback(DBusGProxy* remoteobj) {
static gboolean sendDBUS(DBusGProxy* remoteobj) {
  /* Local values that we'll start updating to the remote object. */
  static gint localValue1 = -80;
  static gdouble localValue2 = -120.0;

  GError* error = NULL;

  /* Set the first value. */
  atech_e99_mpl_shm_add_member(remoteobj, localValue1, &error);
  if (error != NULL) {
    handleError("Failed to set value1", error->message, FALSE);
  } else {
    g_print(PROGNAME ":timerCallback Set value1 to %d\n", localValue1);
  }

  /* If there was an error with the first, release the error, and
     don't attempt the second time. Also, don't add to the local
     values. We assume that errors from the first set are caused by
     server going off the D-Bus, but are hopeful that it will come
     back, and hence keep trying (returning TRUE). */
  if (error != NULL) {
    g_clear_error(&error);
    return TRUE;
  }

  /* Tell the timer launcher that we want to remain on the timer
     call list in the future as well. Returning FALSE here would
     stop the launch of this timer callback. */
  return TRUE;
}

