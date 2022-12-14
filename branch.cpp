#include "branch.h"

#include <QDebug>

Branch::Branch(QDomElement &xml)
{
    QDomNode docElem = xml.firstChild();
    while(!docElem.isNull())
    {
        QDomElement element = docElem.toElement();


        if(element.toElement().attribute("type")=="branch") this->m_name = element.toElement().text();

        if(element.toElement().attribute("type")=="branch-leader") this->m_leader = element.toElement().text();

        if(element.toElement().attribute("type")=="id") this->m_id = element.toElement().text();

        if(element.toElement().tagName() == "staff")
        {
            staff.staff.insert(element.attribute("id"),element.text());
        }

        docElem = docElem.nextSibling();
    }

//    foreach(QString str,staff.staff.uniqueKeys())
//    {
//        foreach (QString i, staff.staff.values(str))    // 遍历键中所有的值
//                   qDebug() << str << " : " << i;
    //    }
}

void Branch::get(Branch be)
{
    qDebug()<<be.m_id<<be.m_name<<be.m_leader;
}
