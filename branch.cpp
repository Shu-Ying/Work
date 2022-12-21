#include "branch.h"

Branch::Branch()
{

}

Branch::Branch(QString higherOffice)
{
    m_higherOffice=higherOffice;
}

/**
 * @brief Branch::parseXML 解析XML
 * @param xml
 */
void Branch::parseXML(QDomElement &xml)
{
    QDomNode docElem = xml.firstChild();
    while(!docElem.isNull())
    {
        QDomElement element = docElem.toElement();

        //三种固定值
        if(element.toElement().attribute("type")=="branch") this->m_name = element.toElement().text();
        if(element.toElement().attribute("type")=="branch-leader") this->m_leader = element.toElement().text();
        if(element.toElement().attribute("type")=="id") this->m_id = element.toElement().text();

        //存储员工信息
        if(element.toElement().tagName() == "staff")
        {
            Staff s;
            s.setID(element.attribute("id"));
            s.setName(element.toElement().text());
            s.setDepartment(m_name);
            s.setHigherOffice(m_higherOffice);

            staff.push_back(s);
        }

        docElem = docElem.nextSibling();
    }
}

QString Branch::getName()
{
    return m_name;
}

void Branch::setName(QString name)
{
    this->m_name = name;
}

QString Branch::getID()
{
    return m_id;
}

void Branch::setID(QString id)
{
    this->m_id = id;
}

QString Branch::getLeader()
{
    return m_leader;
}

void Branch::setLeader(QString leader)
{
    this->m_leader = leader;
}

QString Branch::getStaffMaxID()
{
    QString id = "0";

    foreach(Staff st,staff)
        if(st.getID().toInt()>id.toInt()) id=st.getID();

    return id;
}

void Branch::setStaff(QString id, QString name)
{
    Staff s;
    s.setID(id);
    s.setName(name);
    s.setDepartment(m_name);
    s.setHigherOffice(m_higherOffice);

    staff.push_back(s);
}

QList<QStringList> Branch::getStaffInfo()
{
    QList<QStringList> list;
    QStringList info;

    if(staff.length())
    {
        info<<m_id<<m_leader<<staff[0].getHigherOffice()<<m_leader;
    } else
    {
        info<<m_id<<m_leader<<""<<m_leader;
    }

    list.push_back(info);

    for(Staff st:staff)
    {
        info.clear();
        info<<st.getID()<<st.getName()<<st.getHigherOffice()<<m_leader;

        list.push_back(info);
    }


    return list;
}
