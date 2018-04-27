// -----------------------------------------------------------------------------------------------
/// @author dfernandez
/// @file   person.cpp
/// @date   April 19, 2018
/// @brief  Brief description of the class/struct.
// -----------------------------------------------------------------------------------------------

#include "person.h"

Person::Person() {
/*    m_name = "John";
    m_age = 33;
    m_gender = "male";
    m_address = "St John 666";*/
}

Person::~Person() {
}

Person::Person(QString name, int age, QString gender, QString address) {
    m_name = name;
    m_age = age;
    m_gender = gender;
    m_address = address;
}

Person::Person(QString name) {
    m_name = name;
}

QDBusArgument &operator<<(QDBusArgument &argument, const Person &person) {

    argument.beginStructure();
    argument << person.GetName();
    argument << person.GetAge();
    argument << person.GetGender();
    argument << person.GetAddress();
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, Person &person) {
    QString unMarshal_string;
    int unMarshal_int = 0;

    argument.beginStructure();
    argument >> unMarshal_string;
    person.SetName(unMarshal_string);
    unMarshal_string.clear();
    argument >> unMarshal_int;
    person.SetAge(unMarshal_int);
    unMarshal_int = 0;
    argument >> unMarshal_string;
    person.SetGender(unMarshal_string);
    unMarshal_string.clear();
    argument >> unMarshal_string;
    person.SetAddress(unMarshal_string);
    unMarshal_string.clear();
    argument.endStructure();

    return argument;  
}
void Person::registerMetaType() {
    qRegisterMetaType<Person>("person");
    qDBusRegisterMetaType<Person>();
}
