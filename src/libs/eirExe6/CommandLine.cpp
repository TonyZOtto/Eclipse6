#include "CommandLine.h"

#include "ExeSupport.h"

CommandLine::CommandLine(ExeSupport *parent)
    : QObject{parent}
{
    qDebug() << Q_FUNC_INFO;
    setObjectName("CommandLine");
    mpSupport = qobject_cast<ExeSupport *>(parent);
    Q_ASSERT_X(mpSupport, "CommandLine ctor", "Invalid ExeSupport parent");
}
