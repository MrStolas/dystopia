CMAKE_MINIMUM_REQUIRED ( VERSION 3.0.2 )

PROJECT ( comm_dbus )

SET ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
SET ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

SET (CMAKE_C_FLAGS "-Wall -std=gnu99 -g")
SET (CMAKE_CXX_FLAGS "-Wall -g")

FIND_PACKAGE ( PkgConfig REQUIRED )

pkg_check_modules(DBUS REQUIRED dbus-1>=1.2)
INCLUDE_DIRECTORIES ( ${DBUS_INCLUDE_DIRS} )
LINK_DIRECTORIES ( ${DBUS_LIBRARY_DIRS} )
#Adding glib library
pkg_check_modules(GLIB REQUIRED glib-2.0>=2.22)
INCLUDE_DIRECTORIES ( ${GLIB_INCLUDE_DIRS} )
LINK_DIRECTORIES ( ${GLIB_LIBRARY_DIRS} )

#SET ( COMM_DBUS_SRC comm_dbus.c )
#SET ( COMM_DBUS_HDR comm_dbus.h )
SET ( COMM_DBUS_SRC comm_client_bind.c )
SET ( COMM_DBUS_HDR comm_client_bind.h )

SET ( COMM_DBUS_INC
                    /usr/include/glib-2.0/
                    /usr/include/glib-2.0/gio/
                    /usr/lib64/glib-2.0/include/ )
#                    /usr/local/include/glib-2.0/
#                    /usr/local/include/glib-2.0/gio/ 
#                    /usr/local/lib/glib-2.0/include/ )

INCLUDE_DIRECTORIES ( ${COMM_DBUS_INC} )
ADD_LIBRARY ( comm_dbus ${COMM_DBUS_SRC} ${COMM_DBUS_HDR} )
TARGET_LINK_LIBRARIES ( comm_dbus ${DBUS_LIBRARIES} ${GLIB_LIBRARIES} )
