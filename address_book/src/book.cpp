// -----------------------------------------------------------------------------------------------
/// @author dfernandez
/// @file   book.cpp
/// @date   April 20, 2018
/// @brief  Brief description of the class/struct.
// -----------------------------------------------------------------------------------------------

#include <algorithm>

#include "book.h"

//book::book() {
//}

book::book(QObject* parent) : QObject(parent) {
}

book::~book() {
}

void book::addPerson(const Person& person_) {
    if (!m_persons.contains(person_)) {
        m_persons.append(person_);
        emit personAdded(person_);

        
    }
    //PersonsVector::iterator it;
    //it = std::find(m_persons.begin(), m_persons.end(), person_);
    //if (it != m_persons.end()) {
    //    m_persons.append(person_);
    //}
    /*QVector<person*>::Iterator it;
    it = std::find(m_persons.begin(), m_persons.end(), person_);
    if (it != m_persons.end()) {
        m_persons.append(person_);
        emit personAdded(person_.GetName());
    }*/
}

void book::removePerson(const Person& person_) {
    emit personRemoved(person_.GetName());
    /*QVector<person*>::Iterator it;
    it = std::find(m_persons.begin(), m_persons.end(), person_);
    if ( it != m_persons.end() )
    {
        int i = m_persons.indexOf(it);
        m_persons.remove(i);


        emit personRemoved(person_.GetName());
    }*/
}

int book::ipersonRemoved() {
    return 33;
}
int book::ipersonUpdated() {
    return 33;
}
void book::sendMessage(const message& message) {
    Q_EMIT messageSent(message);
}