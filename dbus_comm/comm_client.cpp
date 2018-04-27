/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   comm_client.cpp
 * Author: dfernandez
 *
 * Created on April 11, 2018, 7:30 PM
 */

#include "comm_client.h"
#include <iostream>
#include <QStringList>

/*comm_client::comm_client() {
    widget.setupUi(this);
    init();
}*/

//comm_client::comm_client(atech::e99::mpl &bookInterface, QWidget *parent) : QMainWindow(parent), m_book_interface(bookInterface) {
comm_client::comm_client(atech::e99::mpl &bookInterface) : m_book_interface(bookInterface) {
    widget.setupUi(this);
    init();
    const bool bookconnected = connect(&m_book_interface, SIGNAL(personAdded(Person)), this, SLOT(serverevent(Person)));
    Q_ASSERT(bookconnected);
    Q_UNUSED(bookconnected);
}

void comm_client::init() {
    const bool saveconnected = connect(widget.pushButtonSave, SIGNAL(clicked()), this, SLOT(saveButtonClicked()));
    Q_ASSERT(saveconnected);
    Q_UNUSED(saveconnected);
    const bool updateconnected = connect(widget.pushButtonUpdate, SIGNAL(clicked()), this, SLOT(updateButtonClicked()));
    Q_ASSERT(updateconnected);
    Q_UNUSED(updateconnected);
    const bool removeconnected = connect(widget.pushButtonRemove, SIGNAL(clicked()), this, SLOT(removeButtonClicked()));
    Q_ASSERT(removeconnected);
    Q_UNUSED(removeconnected);
}

comm_client::~comm_client() {
}
/*void comm_client::set_interface(atech::e99::mpl& interface) {
    m_book_interface(interface);
}*/
void comm_client::fillTable(mypayload_t* pTable) {
    static int row = 0;

    QStringList payload;
    QString qname = QString::fromLatin1(pTable->name, NAME_SIZE);
    QString qage = QString::number(pTable->age);
    QString qgender = QChar(pTable->gender);
    QString qaddr = QString::fromLatin1(pTable->address, ADDR_SIZE);
    payload << qname.trimmed() << qage << qgender << qaddr.trimmed();
    if (widget.tableWidget->rowCount() < (row + 1)) {
        widget.tableWidget->setRowCount(row + 1);
    }

    for (int column = 0; column < widget.tableWidget->columnCount(); column++) {
        QTableWidgetItem *pItem = widget.tableWidget->item(row, column);
        if (!pItem) {
            pItem = new QTableWidgetItem();
            widget.tableWidget->setItem(row, column, pItem);
        }
        pItem->setText(payload.at(column));
    }
    row++;
}

/*void comm_client::dbus_result(GObject *source_object,
        GAsyncResult *res,
        gpointer user_data) {
    std::cout << "Result: " << std::endl;
}*/

void comm_client::sendDBUS(Person &person) {
    /*Person person(   QString::fromLatin1(payload->name),
                        payload->age, QChar(payload->gender),
                        //QString::fromLatin1(payload->gender),
                        QString::fromLatin1(payload->address));*/
    m_book_interface.addPerson(person);
/*
    commAtechE99MplShm *myproxy;
    GError *error;
    myproxy = comm_atech_e99_mpl_shm_proxy_new_for_bus_sync(
            G_BUS_TYPE_SESSION,
            G_DBUS_PROXY_FLAGS_NONE,
            "org.freedesktop.DBus",
            "/org/freedesktop/DBus/",
            NULL,
            &error
            );
    GVariantBuilder *builder;
    GVariant *arg1;
    builder = g_variant_builder_new(G_VARIANT_TYPE("as"));
    g_variant_builder_add(builder, "s", m_payload.name);
    g_variant_builder_add(builder, "s", m_payload.age);
    arg1 = g_variant_new("as", builder);
    g_variant_builder_unref(builder);
    builder = g_variant_builder_new(G_VARIANT_TYPE("iy"));
    g_variant_builder_add(builder, "i", m_payload.age);
    g_variant_builder_add(builder, "y", m_payload.gender);
    GVariant *arg2 = g_variant_new("iy", builder);
    g_variant_builder_unref(builder);
    comm_atech_e99_mpl_shm_call_add_member(myproxy, arg1, arg2, NULL, &comm_client::dbus_result, NULL);
*/
}

void comm_client::saveButtonClicked() {
    strncpy(m_payload.name,
            this->widget.m_nameLineEdit->text().toStdString().c_str(),
            NAME_SIZE);
    m_payload.age = this->widget.m_ageLineEdit->text().toInt();
    m_payload.gender = this->widget.m_femaleRadioButton->isChecked() ? 'f' : 'm';
    strncpy(m_payload.address,
            this->widget.m_addressTextEdit->toPlainText().toStdString().c_str(),
            ADDR_SIZE);
    m_person.SetName(QString::fromLatin1(m_payload.name));
    m_person.SetAge(m_payload.age);
    m_person.SetGender(QChar(m_payload.gender));
    m_person.SetAddress(QString::fromLatin1(m_payload.address));
    std::cout << "Send to D-BUS" << std::endl;
    sendDBUS(m_person);
    fillTable(&m_payload);
}

void comm_client::removeButtonClicked() {

}

void comm_client::updateButtonClicked() {

}

void comm_client::serverevent(Person a) {
    std::cout << "Signal from server: " << std::endl;
}
