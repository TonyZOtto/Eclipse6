#include "ExeSupport.h"

#include "AppArguments.h"
#include "AppSettings.h"
#include "CommandLine.h"

ExeSupport::ExeSupport(QObject *parent)
    : QObject{parent}
    , mpArguments(new AppArguments(this))
    , mpSettings(new AppSettings(this))
    , mpCommandLine(new CommandLine(this))
{
    setObjectName("ExeSupport");
    Q_ASSERT_X(mpArguments, "ExeSupport ctor", "Invalid AppArguments child");
    Q_ASSERT_X(mpSettings, "ExeSupport ctor", "Invalid AppSettings child");
    Q_ASSERT_X(mpCommandLine, "ExeSupport ctor", "Invalid CommandLine child");
}
