#include "AppArguments.h"

#include "ExeSupport.h"

AppArguments::AppArguments(ExeSupport *parent)
    : QObject{parent}
{
    setObjectName("AppArguments");
    mpSupport = qobject_cast<ExeSupport *>(parent);
    Q_ASSERT_X(mpSupport, "CommandLine ctor", "Invalid ExeSupport parent");

}
