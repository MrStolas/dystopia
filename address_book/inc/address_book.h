// ------------------------------------------------------------------------------------------------
/// @author dfernandez
/// @file address_book.h
/// @date April 19, 2018
/// @brief Brief description of the class/struct.
// ------------------------------------------------------------------------------------------------

#ifndef ADDRESS_BOOK_H
#define ADDRESS_BOOK_H

#include "ui_address_book_form.h"
#include "person.h"
#include <map>
#include <string>
#include "book.h"
#include "message.h"
// ------------------------------------------------------------------------------------------------
/// @class address_book
/// @Brief Brief information on the class.
// ------------------------------------------------------------------------------------------------

class address_book : public QMainWindow, Ui_address_book_form {
    Q_OBJECT
public:
    address_book(book *my_book);
    virtual ~address_book();
private:
    Ui::address_book_form widget;
    std::map<std::string, Person> m_mapbook;
    book *m_book;
private slots:
    void add_person(const Person&);
    void del_person(Person person);
    void upd_person(Person person);
};

#endif /* ADDRESS_BOOK_H */

