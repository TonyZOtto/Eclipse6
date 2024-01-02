#include "ExeSupport.h"

#include "AppArguments.h"
#include "AppSettings.h"
#include "ClockCalendar.h"
#include "CommandLine.h"
#include "UidManager.h"

ExeSupport::ExeSupport(QObject *parent)
    : QObject{parent}
    , mpUidManager(new UidManager(this))
    , mpClockCalendar(new ClockCalendar(this))
    , mpArguments(new AppArguments(this))
    , mpSettings(new AppSettings(this))
    , mpCommandLine(new CommandLine(this))
{
    setObjectName("ExeSupport");
    Q_ASSERT_X(mpUidManager, "ExeSupport ctor", "Invalid UidManager child");
    Q_ASSERT_X(mpClockCalendar, "ExeSupport ctor", "Invalid ClockCalendar child");
    Q_ASSERT_X(mpArguments, "ExeSupport ctor", "Invalid AppArguments child");
    Q_ASSERT_X(mpSettings, "ExeSupport ctor", "Invalid AppSettings child");
    Q_ASSERT_X(mpCommandLine, "ExeSupport ctor", "Invalid CommandLine child");
}

Uid ExeSupport::uid(const Key &key)
{
    Q_ASSERT_X(mpUidManager, Q_FUNC_INFO, "Invalid UidManager");
    return mpUidManager->uid(key);
}

Uid ExeSupport::uid(QObject *obj)
{
    Q_ASSERT_X(mpUidManager, Q_FUNC_INFO, "Invalid UidManager");
    return mpUidManager->uid(obj);
}

Key ExeSupport::key(const Uid uid)
{
    Q_ASSERT_X(mpUidManager, "ExeSupport ctor", "Invalid UidManager child");
    return mpUidManager->key(uid);
}
