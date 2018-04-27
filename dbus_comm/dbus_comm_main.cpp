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
#include "comm_client.h"
#include "bookInterface.h"
#include "person.h"

#define ADDR_BOOK_SERVICE "atech.e99.mpl.abook"
#define ADDR_BOOK_PATH "/abook"

using namespace std;

/*
 *
 */
int main(int argc, char** argv) {
    int result = 0;
    Person::registerMetaType();
    QApplication app(argc, argv);

    QDBusConnection connection = QDBusConnection::sessionBus();
    atech::e99::mpl bookInterface(ADDR_BOOK_SERVICE, ADDR_BOOK_PATH, connection);

    comm_client cclient(bookInterface);
    //comm_client cclient;
    //cclient.set_interface(bookInterface);
    cclient.show();

    result = app.exec();
    return result;
}

