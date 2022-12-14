#ifndef CENTER_H
#define CENTER_H

#include <QString>
#include <QList>
#include <QDomElement>

#include "branch.h"

class Center
{
public:
    Center(QDomElement &xml);

    void get(Center ce);
private:
    QString m_name;
    QString m_id;
    QString m_leader;

    QList<Branch>branch;
};

#endif // CENTER_H
