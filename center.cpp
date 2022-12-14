#include "center.h"

#include <QDebug>

Center::Center(QDomElement &xml)
{
    QDomNode docElem = xml.firstChild();
    while(!docElem.isNull())
    {
        QDomElement element = docElem.toElement();


        if(element.toElement().attribute("type")=="center") this->m_name = element.toElement().text();

        if(element.toElement().attribute("type")=="center-leader") this->m_leader = element.toElement().text();

        if(element.toElement().attribute("type")=="id") this->m_id = element.toElement().text();

        if(element.toElement().tagName() == "item")
        {
            Branch b(element);
            branch.push_back(b);
        }

        docElem = docElem.nextSibling();
    }

//    for(int i=0;i<branch.size();i++)
//    {
//        branch[i].get(branch[i]);
    //    }
}

void Center::get(Center ce)
{
    qDebug()<<ce.m_id<<ce.m_name<<ce.m_leader;
}
