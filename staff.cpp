#include "staff.h"

Staff::Staff()
{

}

void Staff::setID(QString id)
{
    m_id=id;
}

QString Staff::getID()
{
    return m_id;
}

void Staff::setName(QString name)
{
    m_name=name;
}

QString Staff::getName()
{
    return m_name;
}

void Staff::setDepartment(QString de)
{
    m_department=de;
}

QString Staff::getDepartment()
{
    return m_department;
}

void Staff::setHigherOffice(QString ho)
{
    m_higherOffice=ho;
}

QString Staff::getHigherOffice()
{
    return m_higherOffice;
}
