#include "staff.h"

Staff::Staff()
{

}

QString Staff::getMaxID()
{
    QString max = "0";
    foreach(QString id,subordinate.keys())
    {
        if(id.toInt()>max.toInt()) max = id;
    }

    return max;
}
