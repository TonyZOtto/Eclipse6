#include "NanosecondsElapsed.h"

QDateTime NanosecondsElapsed::mBaseTime;
QElapsedTimer NanosecondsElapsed::mElapsedTimer;

NanosecondsElapsed::NanosecondsElapsed()
{
    if ( ! mElapsedTimer.isValid())
    {
        mBaseTime = QDateTime::currentDateTime();
        mElapsedTimer.start();
    }
    sample();
}

void NanosecondsElapsed::sample()
{
#ifdef QT_DEBUG
    Q_ASSERT_X(mElapsedTimer.isValid(), Q_FUNC_INFO, "Invalid Elapsed Timer");
#endif
    mDuration = mElapsedTimer.isValid()
        ? mElapsedTimer.durationElapsed()
        : QElapsedTimer::Duration();
}

QElapsedTimer::ClockType NanosecondsElapsed::clockType()
{
    return QElapsedTimer::clockType();
}

bool NanosecondsElapsed::isMonotonic()
{
    return QElapsedTimer::isMonotonic();
}
