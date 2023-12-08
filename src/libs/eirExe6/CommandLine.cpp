#include "CommandLine.h"

#include "ExeSupport.h"

CommandLine::CommandLine(ExeSupport *parent)
    : QObject{parent}
{
    setObjectName("CommandLine");
    mpSupport = qobject_cast<ExeSupport *>(parent);
    Q_ASSERT_X(mpSupport, "CommandLine ctor", "Invalid ExeSupport parent");
}
