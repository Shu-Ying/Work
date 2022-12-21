#include "manager.h"

Manager::Manager()
{

}

/**
 * @brief Manager::parseXML 解析XML
 * @param xml
 */
void Manager::parseXML(QDomElement &xml)
{
    QDomNode docElem = xml.firstChild();
    QDomNode node = docElem.firstChild();

    while(!node.isNull())
    {
        QDomElement element = node.toElement();

        //固定类型
        if(element.toElement().attribute("type")=="boss") m_name = element.toElement().text();
        if(element.toElement().attribute("type")=="boss-leader") m_leader = element.toElement().text();
        if(element.toElement().attribute("type")=="id") m_id = element.toElement().text();

        if(element.toElement().tagName() == "item")
        {
            Center c(m_name);
            c.parseXML(element);
            subordinate.push_back(c);
        }

        node = node.nextSibling();
    }
}

QString Manager::getID()
{
    return m_id;
}

void Manager::setID(QString id)
{
    this->m_id = id;
}

QString Manager::getName()
{
    return m_name;
}

QString Manager::getName(int num)
{
    return subordinate[num].getName();
}

void Manager::setName(QString name)
{
    this->m_name = name;
}

QString Manager::getCenterName(int i,int num)
{
    return subordinate[i].getName(num);
}

QString Manager::getLeader()
{
    return m_leader;
}

void Manager::setLeader(QString leader)
{
    this->m_leader = leader;
}

int Manager::getLength()
{
    return subordinate.length();
}

int Manager::getCenterLength(int num)
{
    if(num>=subordinate.length()) return 0;
    return subordinate[num].getLength();
}

int Manager::getMaxID()
{
    int id = 1;

    foreach(Center ce,subordinate)
    {
        if(ce.getID().toInt()>id) id = ce.getID().toInt();
        if(ce.getID(0).toInt()>id) id = ce.getID(0).toInt(); ///<这里逻辑错误了 但是能实现
        if(ce.getStaffMaxID().toInt()>id) id = ce.getStaffMaxID().toInt();
    }

    return id;
}

QList<QStringList> Manager::getStaffInfo(QString name)
{
    QList<QStringList>list;

    foreach(Center ce,subordinate)
    {
        if(ce.getName() == name)
            return ce.getStaffInfo();

        if(ce.containsBranch(name))
            return ce.getStaffInfo(name);
    }

    return list;
}
