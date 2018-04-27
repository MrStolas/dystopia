CMAKE_MINIMUM_REQUIRED ( VERSION 3.0.2 )

PROJECT ( comm )

SET ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
SET ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

SET (CMAKE_C_FLAGS "-Wall -std=gnu99 -g")
SET (CMAKE_CXX_FLAGS "-Wall -g")

#FIND_PACKAGE ( PkgConfig REQUIRED )

#pkg_check_modules(DBUS REQUIRED dbus-1>=1.2)
#INCLUDE_DIRECTORIES ( ${DBUS_INCLUDE_DIRS} )
#LINK_DIRECTORIES ( ${DBUS_LIBRARY_DIRS} )
#MESSAGE ( STATUS "dbus library to link: ${DBUS_LIBRARIES}" )
##Adding glib library
#pkg_check_modules(GLIB REQUIRED glib-2.0>=2.22)
#INCLUDE_DIRECTORIES ( ${GLIB_INCLUDE_DIRS} )
#LINK_DIRECTORIES ( ${GLIB_LIBRARY_DIRS} )
#MESSAGE ( STATUS "glib library to link: ${GLIB_LIBRARIES}" )

#pkg_check_modules (DBUSGLIB REQUIRED dbus-glib-1)
#INCLUDE_DIRECTORIES (${DBUSGLIB_INCLUDE_DIRS})
#LINK_DIRECTORIES ( ${DBUSGLIB_LIBRARY_DIRS} )
#MESSAGE ( STATUS "dbus-glib-1 library to link: ${DBUSGLIB_LIBRARIES}" )
##include_directories( /usr/lib/ )
##link_directories( /usr/lib/ )

#ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

SET ( CMAKE_AUTOUIC ON )

SET ( COMM_SRCS 
                dbus_comm_main.cpp
                comm_client.cpp
                person.cpp
                bookInterface.cpp )

SET ( UI_SRCS comm_client.ui )

SET ( COMM_MOC_HDRS comm_client.h inc/bookInterface.h)

FIND_PACKAGE( Qt4 COMPONENTS QtCore QtDBUS QtGui QtXml REQUIRED )
INCLUDE( ${QT_USE_FILE})
INCLUDE_DIRECTORIES(${QT_QTCORE_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${QT_QTGUI_INCLUDE_DIR})

QT4_WRAP_UI( UI_HEADERS ${UI_SRCS} )
QT4_WRAP_CPP( COMM_MOC_SRCS ${COMM_MOC_HDRS} )

#ADD_SUBDIRECTORY ( dbuslib )

INCLUDE_DIRECTORIES (
                        /usr/include/
                        ${CMAKE_BINARY_DIR}
                        inc )
#                        dbuslib
#                        /usr/include/glib-2.0/
#                        /usr/include/glib-2.0/gio/
#                        /usr/lib64/glib-2.0/include/ )
#                        /usr/local/include/glib-2.0/
#                        /usr/local/include/glib-2.0/gio/
#                        /usr/local/lib/glib-2.0/include/ )

ADD_EXECUTABLE ( comm_client ${UI_SRCS} ${COMM_SRCS} ${COMM_MOC_SRCS} ${UI_HEADERS})
TARGET_LINK_LIBRARIES ( comm_client ${QT_LIBRARIES} )
#TARGET_LINK_LIBRARIES ( comm_client ${QT_LIBRARIES} comm_dbus ${GLIB_LIBRARIES} )
#TARGET_LINK_LIBRARIES ( comm_client ${QT_LIBRARIES} comm_dbus ${DBUS_LIBRARIES} ${GLIB_LIBRARIES} ${DBUSGLIB_LIBRARIES} )
#TARGET_LINK_LIBRARIES ( comm_client comm_dbus ${QT_LIBRARIES} dbus-glib-1 dbus-1 glib-2.0 )
#TARGET_LINK_LIBRARIES ( comm_client comm_dbus ${QT_LIBRARIES} dbus-glib-1 }
#TARGET_LINK_LIBRARIES ( comm_client comm_dbus ${QT_LIBRARIES} dbus-1 }
#TARGET_LINK_LIBRARIES ( comm_client comm_dbus ${QT_LIBRARIES} glib-2.0 )
#TARGET_LINK_LIBRARIES ( comm_client comm_dbus ${QT_LIBRARIES} ${DBUS_LIBRARIES} ${GLIB_LIBRARIES} ${DBUSGLIB_LIBRARIES} )