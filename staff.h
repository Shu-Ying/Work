#ifndef STAFF_H
#define STAFF_H

#include <QString>

class Staff
{
public:
    Staff();

    void setID(QString id);
    QString getID();

    void setName(QString name);
    QString getName();

    void setDepartment(QString de);
    QString getDepartment();

    void setHigherOffice(QString ho);
    QString getHigherOffice();

private:
    QString m_id;
    QString m_name;
    QString m_department;
    QString m_higherOffice;
};

#endif // STAFF_H
