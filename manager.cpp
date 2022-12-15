#include "manager.h"

#include <QDebug>

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

        //固定三种类型
        if(element.toElement().attribute("type")=="boss") this->m_name = element.toElement().text();
        if(element.toElement().attribute("type")=="boss-leader") this->m_leader = element.toElement().text();
        if(element.toElement().attribute("type")=="id") this->m_id = element.toElement().text();

        if(element.toElement().tagName() == "item")
        {
            Center c;
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
    qDebug()<<subordinate[num].getLength();
    return subordinate[num].getLength();
}
