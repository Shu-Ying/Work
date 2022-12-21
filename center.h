#ifndef CENTER_H
#define CENTER_H

#include <QList>
#include <QDomElement>

#include "branch.h"

class Center
{
public:
    Center();
    Center(QString higherOffice);

    /**
     * @brief parseXML 解析XML
     * @param xml 解析的值
     */
    void parseXML(QDomElement &xml);

    /**
     * @brief getID 获取中心ID
     * @return
     */
    QString getID();

    /**
     * @brief getID 获取部门ID
     * @param num   哪个中心下的部门
     * @return
     */
    QString getID(int num);

    /**
     * @brief getStaffMaxID 获取当前部门下员工最大ID
     * @return
     */
    QString getStaffMaxID();

    void setID(QString id);

    QString getLeader();
    void setLeader(QString leader);

    QString getName();

    /**
     * @brief getName 获取name
     * @param num   表示哪个部门的name
     * @return
     */
    QString getName(int num);
    void setName(QString name);

    int getLength();
    int getBranchLength();

    /**
     * @brief containsBranch 检索是否包含该部门
     * @param name 检索的部门名
     * @return
     */
    bool containsBranch(QString name);

    QList<QStringList> getStaffInfo();
    QList<QStringList> getStaffInfo(QString name);
private:
    QString m_name;
    QString m_id;
    QString m_leader;
    QString m_higherOffice;

    QList<Branch>subordinate;
    QList<Staff>staff;
};

#endif // CENTER_H
