#ifndef STAFF_H
#define STAFF_H

#include <QString>
#include <QMap>
#include <QDomElement>

class Staff
{
public:
    Staff();

    QMap<QString,QString>subordinate;
};

#endif // STAFF_H
