#include "NanosecondTime.h"

QDateTime NanosecondTime::mBaseTime;
QElapsedTimer NanosecondTime::mElapsedTimer;

NanosecondTime::NanosecondTime()
{
    sample();
}

void NanosecondTime::sample()
{
    mDuration = mElapsedTimer.isValid()
        ? mElapsedTimer.durationElapsed()
        : QElapsedTimer::Duration();
}

QElapsedTimer::ClockType NanosecondTime::clockType()
{
    return QElapsedTimer::clockType();
}

bool NanosecondTime::isMonotonic()
{
    return QElapsedTimer::isMonotonic();
}

void NanosecondTime::staticStart()
{
    mBaseTime = QDateTime::currentDateTime();
    mElapsedTimer.start();
}
