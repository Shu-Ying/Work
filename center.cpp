#include "center.h"

#include <QDebug>

Center::Center()
{

}

/**
 * @brief Center::parseXML 解析XML
 * @param xml
 */
void Center::parseXML(QDomElement &xml)
{
    QDomNode docElem = xml.firstChild();
    while(!docElem.isNull())
    {
        QDomElement element = docElem.toElement();

        //三种固定值
        if(element.toElement().attribute("type")=="center") this->m_name = element.toElement().text();
        if(element.toElement().attribute("type")=="center-leader") this->m_leader = element.toElement().text();
        if(element.toElement().attribute("type")=="id") this->m_id = element.toElement().text();

        if(element.toElement().tagName() == "item")
        {
            Branch b;
            b.parseXML(element);
            subordinate.push_back(b);
        }

        docElem = docElem.nextSibling();
    }

//    foreach(Branch be,subordinate)
//    {
//        qDebug()<<be.getName();
//    }
}

QString Center::getID()
{
    return m_id;
}

QString Center::getLeader()
{
    return m_leader;
}

QString Center::getName()
{
    return m_name;
}

QString Center::getName(int num)
{
    return subordinate[num].getName();
}

int Center::getLength()
{
    return subordinate.length();
}
