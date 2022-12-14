#include "manager.h"

#include <QDebug>

Manager::Manager(QDomElement &xml)
{
    QDomNode docElem = xml.firstChild();
    QDomNode node = docElem.firstChild();

    int length = sureFor(xml);

    for(int i=0;i<length;i++)
    {
        QDomElement element = node.toElement();

        if(element.toElement().attribute("type")=="boss") this->m_name = element.toElement().text();

        if(element.toElement().attribute("type")=="boss-leader") this->m_leader = element.toElement().text();

        if(element.toElement().attribute("type")=="id") this->m_id = element.toElement().text();

        if(element.toElement().tagName() == "item")
        {
            Center c(element);
            center.push_back(c);
        }

        node = node.nextSibling();
    }

        for(int i=0;i<center.size();i++)
        {
            center[i].get(center[i]);
        }
}

void Manager::parseXML(QDomElement &docElem)
{

}

/**
 * @brief Manager::sureFor 循环几次
 * @param xml   遍历文件
 * @return  返回循环几次
 */
int Manager::sureFor(QDomElement xml)
{
    QDomNode docElem = xml.firstChild();
    QDomNode node = docElem.firstChild();

    int num = 0;

    while(!node.isNull())
    {
        num++;
        node = node.nextSibling();
    }

    return num;
}

