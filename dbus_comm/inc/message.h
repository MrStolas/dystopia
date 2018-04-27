// ------------------------------------------------------------------------------------------------
/// @author dfernandez
/// @file message.h
/// @date April 19, 2018
/// @brief Brief description of the class/struct.
// ------------------------------------------------------------------------------------------------

#ifndef MESSAGE_H
#define MESSAGE_H

#include <QtDBus>
#include "person.h"
// ------------------------------------------------------------------------------------------------
/// @class message
/// @Brief Brief information on the class.
// ------------------------------------------------------------------------------------------------

class message {
public:
    message();
    message(const Person &p);
    message& operator=(const message &other);
    virtual ~message();

    friend QDBusArgument &operator<<(QDBusArgument &argument, const message &message);
    friend const QDBusArgument &operator>>(const QDBusArgument &argument, message &message);

    Person getPerson() const;

    //register Message with the Qt type system
    static void registerMetaType();

private:
    Person m_person;
};
// Declare the type as a Qt meta type
Q_DECLARE_METATYPE(message)

#endif /* MESSAGE_H */

