#ifndef BRANCH_H
#define BRANCH_H

#include <QString>
#include <QList>
#include <QDomElement>

#include "staff.h"

class Branch
{
public:
    Branch(QDomElement &xml);

    void get(Branch be);
private:
    QString m_name;
    QString m_id;
    QString m_leader;

    Staff staff;
};

#endif // BRANCH_H
