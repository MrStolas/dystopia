// -----------------------------------------------------------------------------------------------
/// @author dfernandez
/// @file   address_book.cpp
/// @date   April 19, 2018
/// @brief  Brief description of the class/struct.
// -----------------------------------------------------------------------------------------------

#include "address_book.h"
#include "message.h"
#include <QString>

/*address_book::address_book() {
    widget.setupUi(this);
}*/
address_book::address_book(book *mybook) : m_book(mybook) {
    widget.setupUi(this);
    const bool connected = connect(m_book, SIGNAL(personAdded(const Person&)), this, SLOT(add_person(const Person&)));
    Q_ASSERT(connected);
    Q_UNUSED(connected);
}

address_book::~address_book() {
}

void address_book::add_person(const Person& person) {
    static int row = 0;

    QStringList person_reg;
    person_reg << person.GetName() << QString::number(person.GetAge()) << person.GetGender() << person.GetAddress();

    if (this->widget.tableWidget->rowCount() < (row + 1)) {
        this->widget.tableWidget->setRowCount(row + 1);
    }

    for (int column = 0; column < this->widget.tableWidget->columnCount(); column++) {
        QTableWidgetItem *pItem = this->widget.tableWidget->item(row, column);
        if (!pItem) {
            pItem = new QTableWidgetItem();
            this->widget.tableWidget->setItem(row, column, pItem);
        }
        pItem->setText(person_reg.at(column));
    }
    row++;
}

void address_book::del_person(Person person) {
    
}

void address_book::upd_person(Person person) {
    
}