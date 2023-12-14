#include "ExeSupport.h"

#include "AppArguments.h"
#include "AppSettings.h"
#include "CommandLine.h"

ExeSupport::ExeSupport(QObject *parent)
    : QObject{parent}
    , mBaseTime(QDateTime::currentDateTime())
{
    setObjectName("ExeSupport");
    mpArguments = new AppArguments(this);
    mpSettings = new AppSettings(this);
    mpCommandLine = new CommandLine(this);
    Q_ASSERT_X(mpArguments, "ExeSupport ctor", "Invalid AppArguments child");
    Q_ASSERT_X(mpSettings, "ExeSupport ctor", "Invalid AppSettings child");
    Q_ASSERT_X(mpCommandLine, "ExeSupport ctor", "Invalid CommandLine child");
    mElapsedTimer.start();
    qInfo() << Q_FUNC_INFO << baseTime() << baseZone() << nsecElapsed();
}

QDateTime ExeSupport::baseTime() const
{
    return mBaseTime;
}

QTimeZone ExeSupport::baseZone() const
{
    return baseTime().timeZone();
}

QWORD ExeSupport::nsecElapsed() const
{
    return mElapsedTimer.nsecsElapsed();
}
