#include "AppSettings.h"

#include "ExeSupport.h"

AppSettings::AppSettings(ExeSupport *parent)
    : QObject{parent}
{
    setObjectName("AppSettings");
    mpSupport = qobject_cast<ExeSupport *>(parent);
    Q_ASSERT_X(mpSupport, "CommandLine ctor", "Invalid ExeSupport parent");
}


