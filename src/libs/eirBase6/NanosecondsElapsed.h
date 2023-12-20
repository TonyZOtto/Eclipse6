//!file {Eclipse6}/root/src/libs/eirBase6/NanosecondsElapsed.h Unique Nanosecond-based identifier
#pragma once
#include "eirBase6.h"

#include <QElapsedTimer>

#include "EpochTime.h"
#include "Types.h"

class EIRBASE6_EXPORT NanosecondsElapsed
{
public:
    NanosecondsElapsed();

public: // const
    SQWORD nanoseconds() const
    {
        return duration().count();
    }
    SQWORD microseconds() const
    {
        return nanoseconds() / 1000;
    }
    SQWORD milliseconds() const
    {
        return microseconds() / 1000;
    }
    SQWORD seconds() const
    {
        return milliseconds() / 1000;
    }
    SQWORD minutes() const
    {
        return seconds() / 60;
    }
    SQWORD hours() const
    {
        return minutes() / 60;
    }
    QElapsedTimer::Duration duration() const
    {
        return mDuration;
    }
    operator < (const NanosecondsElapsed &other) const;

public: // non-const
    void sample();

public:
    static QElapsedTimer::ClockType clockType();
    static bool isMonotonic();

private:

private:
    static EpochTime mBaseEms;
    static QElapsedTimer mElapsedTimer;
    QElapsedTimer::Duration mDuration;
};

