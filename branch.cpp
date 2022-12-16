#include "branch.h"

Branch::Branch()
{

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
            subordinate.subordinate.insert(element.attribute("id"),element.text());
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
    return subordinate.getMaxID();
}

void Branch::setStaff(QString id, QString name)
{
    subordinate.subordinate.insert(id,name);
}
