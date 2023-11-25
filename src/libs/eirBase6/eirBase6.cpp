#include "eirBase6.h"

eirBase6::eirBase6()
{
}

QString eirBase6::joinLines(const QStringList &qsl)
{
    QString result;
#ifdef Q_OS_WINDOWS
    result = qsl.join("\r\n");
#else
    result = qsl.join('\n');
#endif
    return result;
}

QStringList eirBase6::splitLines(const QString &qs)
{
    QString tInput = qs;
    tInput.replace("\r\n", "\n");
    tInput.replace("\r", "\n");
    return tInput.split('\n');
}

