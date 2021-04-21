#ifndef OBJECTINFO_H
#define OBJECTINFO_H
#include <QString>
#include "apple.h"

class Objectinfo
{
public:
    Objectinfo();
    Objectinfo(QString, int);

public:
    QString cellNunb{};
    QString objname{};
    int counter{};
 Objectinfo getObjectinfo();
};

#endif // OBJECTINFO_H
