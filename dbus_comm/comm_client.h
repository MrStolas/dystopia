/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   comm_client.h
 * Author: dfernandez
 *
 * Created on April 11, 2018, 7:30 PM
 */

#ifndef _COMM_CLIENT_H
#define _COMM_CLIENT_H

#include "ui_comm_client.h"
#include "payload.h"
#include "bookInterface.h"
#include "message.h"
//#include "comm_dbus.h"

class comm_client : public QMainWindow , Ui_comm_client {
    Q_OBJECT
public:
//    comm_client();
    //comm_client(atech::e99::mpl& bookInterface, QWidget *parent = 0);
    comm_client(atech::e99::mpl& bookInterface);
    virtual ~comm_client();
    void init();
//    void set_interface(atech::e99::mpl &interface);
private:
    Ui::comm_client widget;
    mypayload_t m_payload;
    Person m_person;
    atech::e99::mpl &m_book_interface;
    void fillTable(mypayload_t *);
    void sendDBUS(Person&);
//    static void dbus_result(GObject *, GAsyncResult *, gpointer);
signals:
//    void save();*/
private slots:
    void saveButtonClicked();
    void removeButtonClicked();
    void updateButtonClicked();
    void serverevent(Person);
};

#endif /* _COMM_CLIENT_H */
