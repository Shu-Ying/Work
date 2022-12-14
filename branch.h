#ifndef BRANCH_H
#define BRANCH_H

#include <QString>
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
private:
    QString m_name;
    QString m_id;
    QString m_leader;

    Staff subordinate;
};

#endif // BRANCH_H
