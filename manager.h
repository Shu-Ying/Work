#ifndef MANAGER_H
#define MANAGER_H

#include <QString>
#include <QList>
#include <QDomDocument>

#include "center.h"
class Manager
{
public:
    Manager();

    /**
     * @brief parseXML 解析XML
     * @param xml 解析的值
     */
    void parseXML(QDomElement &xml);

    QString getID();
    QString getLeader();
    QString getName();
    QString getName(int num);
    QString getCenterName(int num);

    int getLength();
    int getCenterLength();
private:
    QString m_name;
    QString m_id;
    QString m_leader;

    QList<Center>subordinate;

private:
    int sureFor(QDomElement docElem);
};

#endif // MANAGER_H
