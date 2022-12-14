#ifndef CENTER_H
#define CENTER_H

#include <QString>
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

    QString getID();
    QString getLeader();
    QString getName();
    QString getName(int num);

    int getLength();
    int getBranchLength();
private:
    QString m_name;
    QString m_id;
    QString m_leader;

    QList<Branch>subordinate;
};

#endif // CENTER_H
