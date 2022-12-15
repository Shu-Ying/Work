#ifndef MANAGER_H
#define MANAGER_H

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
    void setID(QString id);

    QString getLeader();
    void setLeader(QString leader);

    QString getName();
    QString getName(int num);
    void setName(QString name);

    QString getCenterName(int i,int num);

    int getLength();
    int getCenterLength(int num);
private:
    QString m_name;
    QString m_id;
    QString m_leader;

    QList<Center>subordinate;

private:
    int sureFor(QDomElement docElem);
};

#endif // MANAGER_H
