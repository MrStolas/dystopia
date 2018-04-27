// -----------------------------------------------------------------------------------------------
/// @author dfernandez
/// @file   message.cpp
/// @date   April 19, 2018
/// @brief  Brief description of the class/struct.
// -----------------------------------------------------------------------------------------------

#include "message.h"

message::message() {
    registerMetaType();
}

message::message(const Person& p) {
    m_person = p;
}

message& message::operator =(const message& other) {
    m_person = other.m_person;
    return *this;
}

message::~message() {
}

Person message::getPerson() const {
    return this->m_person;
}

// Add qRegisterMetaType and qDBusRegisterMetaType calls to enable the framework to work with the custom type. 
void message::registerMetaType() {
    qRegisterMetaType<message>("message");
    qDBusRegisterMetaType<message>();
}

QDBusArgument &operator<<(QDBusArgument &argument, const message &message) {

    argument.beginStructure();
    argument << message.m_person.GetName();
    argument << message.m_person.GetAge();
    argument << message.m_person.GetGender();
    argument << message.m_person.GetAddress();
    argument.endStructure();

    return argument;
}

const QDBusArgument &operator>>(const QDBusArgument &argument, message &message) {
    QString unMarshal_string;
    int unMarshal_int = 0;

    argument.beginStructure();
    argument >> unMarshal_string;
    message.m_person.SetName(unMarshal_string);
    unMarshal_string.clear();
    argument >> unMarshal_int;
    message.m_person.SetAge(unMarshal_int);
    unMarshal_int = 0;
    argument >> unMarshal_string;
    message.m_person.SetGender(unMarshal_string);
    unMarshal_string.clear();
    argument >> unMarshal_string;
    message.m_person.SetAddress(unMarshal_string);
    unMarshal_string.clear();
    argument.endStructure();

    return argument;  
}
