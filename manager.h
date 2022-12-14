#ifndef MANAGER_H
#define MANAGER_H

#include <QString>
#include <QList>
#include <QDomDocument>

#include "center.h"
class Manager
{
public:
    Manager(QDomElement &xml);

private:
    QString m_name;
    QString m_id;
    QString m_leader;

    QList<Center>center;

private:
    /**
     * @brief parseXML 解析XML
     * @param docElem 传入打开的文件
     */
    void parseXML(QDomElement &docElem);

    int sureFor(QDomElement docElem);
};

#endif // MANAGER_H
