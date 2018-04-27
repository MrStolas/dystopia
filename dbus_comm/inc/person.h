// ------------------------------------------------------------------------------------------------
/// @author dfernandez
/// @file person.h
/// @date April 19, 2018
/// @brief Brief description of the class/struct.
// ------------------------------------------------------------------------------------------------

#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QMetaType>
#include <QtDBus>
// ------------------------------------------------------------------------------------------------
/// @class person
/// @Brief Brief information on the class.
// ------------------------------------------------------------------------------------------------

/*struct PropertyUpdate {
    QString propertyName;
    bool isAdded;
    bool isRemoved;
    bool isUpdated;
};
Q_DECLARE_METATYPE(PropertyUpdate)*/

class Person {
public:
    Person();
    Person(QString name, int age, QString gender, QString address);
    Person(QString name);

    virtual ~Person();

    QString GetAddress() const {
        return m_address;
    }

    void SetAddress(QString address) {
        this->m_address = address;
    }

    int GetAge() const {
        return m_age;
    }

    void SetAge(int age) {
        this->m_age = age;
    }

    QString GetGender() const {
        return m_gender;
    }

    void SetGender(QString gender) {
        this->m_gender = gender;
    }

    QString GetName() const {
        return m_name;
    }

    void SetName(QString name) {
        this->m_name = name;
    }

    bool operator==(const Person &person)
    {
        return person.m_name == m_name;
    }
    friend QDBusArgument &operator<<(QDBusArgument &argument, const Person &person);
    friend const QDBusArgument &operator>>(const QDBusArgument &argument, Person &person);
    //register Message with the Qt type system
    static void registerMetaType();
private:
    QString m_name;
    int m_age;
    QString m_gender;
    QString m_address;
};
// Declare the type as a Qt meta type
Q_DECLARE_METATYPE(Person)

#endif /* PERSON_H */

