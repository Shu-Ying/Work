#ifndef CENTER_H
#define CENTER_H

#include <QList>
#include <QDomElement>

#include "branch.h"

class Center
{
public:
    Center();

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
     * @brief getStaffMaxID 获取最大员工ID
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
private:
    QString m_name;
    QString m_id;
    QString m_leader;

    QList<Branch>subordinate;
};

#endif // CENTER_H
