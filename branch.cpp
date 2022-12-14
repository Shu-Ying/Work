#include "branch.h"

Branch::Branch()
{

}

/**
 * @brief parseXML 解析XML
 * @param xml 解析的值
 */
void Branch::parseXML(QDomElement &xml)
{
    Staff staff;
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
            staff.subordinate.insert(element.attribute("id"),element.text());
        }

        docElem = docElem.nextSibling();
    }
}

QString Branch::getName()
{
    return m_name;
}
