CMAKE_MINIMUM_REQUIRED ( VERSION 3.0.2 )

PROJECT ( address_book )

SET ( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin )
SET ( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib )

SET (CMAKE_C_FLAGS "-Wall -std=gnu99 -g")
SET (CMAKE_CXX_FLAGS "-Wall -g")

SET ( CMAKE_AUTOUIC ON )
SET ( CMAKE_AUTOMOC ON )

INCLUDE_DIRECTORIES ( ${CMAKE_BINARY_DIR} 
                      inc
                      forms )

SET ( ADDR_SRCS 
                src/main.cpp
                src/address_book.cpp
                src/person.cpp
                src/message.cpp
                src/book.cpp
                inc/bookAdaptor.cpp
                inc/bookInterface.cpp )

SET ( UI_SRCS ./src/address_book_form.ui )

SET ( ADDR_MOC_HDRS inc/address_book.h
                    inc/book.h )


FIND_PACKAGE( Qt4 COMPONENTS QtCore QtDBUS QtGui QtXml REQUIRED )
INCLUDE( ${QT_USE_FILE})
INCLUDE_DIRECTORIES(${QT_QTCORE_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${QT_QTGUI_INCLUDE_DIR})

QT4_WRAP_UI( UI_HEADERS ${UI_SRCS} )
QT4_WRAP_CPP( ADDR_MOC_SRCS ${ADDR_MOC_HDRS} )

#qt4_add_dbus_adaptor( CustomDbusTypes_ADAPTOR_SRC
#        comm.interface.xml
#        DbusMessagesReceiver.hpp
#        DbusMessagesReceiver )
#QT4_GENERATE_DBUS_INTERFACE ( shm_information.h com.e99.mpl.interface.xml OPTIONS -A )
#QT4_ADD_DBUS_INTERFACE( comm_interface.h
#                         comm.interface.xml comm_interface)

#qt4_add_dbus_adaptor( CustomDbusTypes_ADAPTOR_SRC
#        comm.interface.xml
#        comm_interface.h
#        comm_interface )

ADD_EXECUTABLE ( address_book ${UI_SRCS} ${ADDR_SRCS} ${ADDR_MOC_SRCS} ${UI_HEADERS} )# ${CustomDbusTypes_ADAPTOR_SRC} )
TARGET_LINK_LIBRARIES ( address_book ${QT_LIBRARIES} )