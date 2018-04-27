/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   common-defs.h
 * Author: dfernandez
 *
 * Created on April 18, 2018, 3:59 PM
 */

#ifndef COMMON_DEFS_H
#define COMMON_DEFS_H

#ifdef __cplusplus
extern "C" {
#endif

/* Well-known name for this service. */
#define VALUE_SERVICE_NAME        "org.comm.dbus"
/* Object path to the provided object. */
#define VALUE_SERVICE_OBJECT_PATH "/GlobalValue"
/* And we're interested in using it through this interface.
   This must match the entry in the interface definition XML. */
#define VALUE_SERVICE_INTERFACE   "atech.e99.mpl.shm"


#ifdef __cplusplus
}
#endif

#endif /* COMMON_DEFS_H */

