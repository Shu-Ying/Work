#include "center.h"

Center::Center()
{

}

Center::Center(QString higherOffice)
{
    m_higherOffice = higherOffice;
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
        if(element.toElement().attribute("type")=="center") m_name = element.toElement().text();
        if(element.toElement().attribute("type")=="center-leader") m_leader = element.toElement().text();
        if(element.toElement().attribute("type")=="id") m_id = element.toElement().text();

        if(element.toElement().tagName() == "staff")
        {
            Staff s;
            s.setID(element.attribute("id"));
            s.setName(element.toElement().text());
            s.setDepartment(m_name);
            s.setHigherOffice(m_higherOffice);

            staff.push_back(s);
        }

        if(element.toElement().tagName() == "item")
        {
            Branch b(m_name);
            b.parseXML(element);
            subordinate.push_back(b);
        }

        docElem = docElem.nextSibling();
    }
}

/**
 * @brief getID 获取中心ID
 * @return
 */
QString Center::getID()
{
    return m_id;
}

/**
 * @brief getID 获取部门ID
 * @param num   哪个中心下的部门
 * @return
 */
QString Center::getID(int num)
{
    return subordinate[num].getID();
}

/**
 * @brief getStaffMaxID 获取当前部门下员工最大ID
 * @return
 */
QString Center::getStaffMaxID()
{
    QString id = "0";

    foreach(Branch br,subordinate)
        if(br.getStaffMaxID().toInt()>id.toInt()) id=br.getStaffMaxID();

    return id;
}

void Center::setID(QString id)
{
    this->m_id = id;
}

QString Center::getLeader()
{
    return m_leader;
}

void Center::setLeader(QString leader)
{
    this->m_leader = leader;
}

QString Center::getName()
{
    return m_name;
}

/**
 * @brief getName 获取name
 * @param num   表示哪个部门的name
 * @return
 */
QString Center::getName(int num)
{
    return subordinate[num].getName();
}

void Center::setName(QString name)
{
    this->m_name = name;
}

int Center::getLength()
{
    return subordinate.length();
}

bool Center::containsBranch(QString name)
{
    for(Branch br:subordinate)
        if(br.getName()==name) return true;

    return false;
}

QList<QStringList> Center::getStaffInfo()
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

QList<QStringList> Center::getStaffInfo(QString name)
{
    QList<QStringList> list;

    for(Branch br:subordinate)
    {
        if(br.getName()==name)
            return br.getStaffInfo();
    }

    return list;
}
