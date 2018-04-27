// ------------------------------------------------------------------------------------------------
/// @author dfernandez
/// @file book.h
/// @date April 20, 2018
/// @brief Brief description of the class/struct.
// ------------------------------------------------------------------------------------------------

#ifndef BOOK_H
#define BOOK_H

#include <QObject>
#include <QVector>
#include "person.h"

// ------------------------------------------------------------------------------------------------
/// @class book
/// @Brief Brief information on the class.
// ------------------------------------------------------------------------------------------------
class message;

typedef QVector<Person> PersonsVector;
Q_DECLARE_METATYPE(PersonsVector)

class book : public QObject {
    Q_OBJECT;

    Q_CLASSINFO("D-Bus Interface", "atech.e99.mpl")
    Q_PROPERTY(int person_removed READ ipersonRemoved)
    Q_PROPERTY(int person_updated READ ipersonUpdated)

signals:
    void personAdded(const Person& person);
    void personRemoved(const QString& name);

    void messageSent(const message &message);

public slots:
    void addPerson(const Person &person_);
    void removePerson(const Person &person_);
    int ipersonRemoved();
    int ipersonUpdated();

    void sendMessage(const message &message);
public:
    //book();
    book(QObject* parent = 0);
    virtual ~book();
private:
    PersonsVector m_persons;
};

//Q_DECLARE_METATYPE(book)

#endif /* BOOK_H */

