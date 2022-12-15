#ifndef BRANCH_H
#define BRANCH_H

#include <QList>
#include <QDomElement>

#include "staff.h"

class Branch
{
public:
    Branch();

    /**
     * @brief parseXML 解析XML
     * @param xml 解析的值
     */
    void parseXML(QDomElement &xml);

    QString getName();

    void setName(QString name);
    void setID(QString id);
    void setLeader(QString leader);

    /**
     * @brief setStaff 设置员工信息
     * @param id ID
     * @param name 姓名
     */
    void setStaff(QString id,QString name);
private:
    QString m_name;
    QString m_id;
    QString m_leader;

    Staff subordinate;
};

#endif // BRANCH_H
