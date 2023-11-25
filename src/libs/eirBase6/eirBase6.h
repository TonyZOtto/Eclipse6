#ifndef EIRBASE6_H
#define EIRBASE6_H

#include "eirBase6_global.h"

#include <QString>
#include <QStringList>

class EIRBASE6_EXPORT eirBase6
{
public:
    eirBase6();
    static QString joinLines(const QStringList &qsl);
    static QStringList splitLines(const QString &qs);
};

#endif // EIRBASE6_H
