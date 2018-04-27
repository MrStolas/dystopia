/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   dbus_comm_main.cpp
 * Author: dfernandez
 *
 * Created on April 11, 2018, 7:14 PM
 */
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusConnectionInterface>
#include <QApplication>
#include <cstdlib>
#include "address_book.h"
#include "message.h"
#include "person.h"
#include "book.h"
#include "bookAdaptor.h"

#define ADDR_BOOK_SERVICE "atech.e99.mpl.abook"
#define ADDR_BOOK_PATH "/abook"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {

    int result = 0;
    message::registerMetaType();
    Person::registerMetaType();
    QApplication app(argc, argv);
    
    book *pBook = NULL;
    MplAdaptor *pMPLAdaptor = NULL;

    /*
      Create a Chat instance and register it with the session bus only if
      the service isn't already available.
    */
    QDBusConnection connection = QDBusConnection::sessionBus();
    if (!connection.interface()->isServiceRegistered(ADDR_BOOK_SERVICE))
    {
        pBook = new book(&app);
        pMPLAdaptor = new MplAdaptor(pBook);

        if (!connection.registerService(ADDR_BOOK_SERVICE))
        {
            qFatal("Could not register service!");
        }

        if (!connection.registerObject(ADDR_BOOK_PATH, pBook))
        {
            qFatal("Could not register Chat object!");
        }
    }

    address_book addr(pBook);
    addr.show();

    result = app.exec();
    return result;
}

