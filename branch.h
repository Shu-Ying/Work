#ifndef BRANCH_H
#define BRANCH_H

#include <QList>
#include <QPair>
#include <QDomElement>

#include "staff.h"

class Branch
{
public:
    Branch();
    Branch(QString higherOffice);

    /**
     * @brief parseXML 解析XML
     * @param xml 解析的值
     */
    void parseXML(QDomElement &xml);

    QString getName();
    void setName(QString name);

    QString getID();
    void setID(QString id);

    QString getLeader();
    void setLeader(QString leader);

    /**
     * @brief getStaffMaxID 返回当前最大员工ID
     * @return
     */
    QString getStaffMaxID();

    /**
     * @brief setStaff 设置员工信息
     * @param id ID
     * @param name 姓名
     */
    void setStaff(QString id,QString name);

    QList<QStringList> getStaffInfo();
private:
    QString m_name;
    QString m_id;
    QString m_leader;
    QString m_higherOffice;

    QList<Staff>staff;
};

#endif // BRANCH_H
