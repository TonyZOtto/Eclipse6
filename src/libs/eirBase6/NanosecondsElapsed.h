//!file {Eclipse6}/root/src/libs/eirBase6/NanosecondsElapsed.h Unique Nanosecond-based identifier
#pragma once
#include "eirBase6.h"

#include <QElapsedTimer>

#include "EpochTime.h"
#include "Types.h" // TODO const nanoPerMicro, etc.

class EIRBASE6_EXPORT NanosecondsElapsed
{
public:
    NanosecondsElapsed();

public: // const
    Nano nanoseconds() const;
    Nano microseconds() const;
    Nano milliseconds() const;
    Nano seconds() const;
    Nano minutes() const;
    Nano hours() const;
    QElapsedTimer::Duration duration() const;
    bool operator < (const NanosecondsElapsed &other) const;

public: // non-const
    QElapsedTimer::Duration sample();

public:
    static QElapsedTimer::ClockType clockType();
    static bool isMonotonic();

private:

private:
    static EpochTime mBaseEms;
    static QElapsedTimer mElapsedTimer;
    QElapsedTimer::Duration mDuration;
};

inline Nano NanosecondsElapsed::nanoseconds() const
{
    return mDuration.count();
}

inline Nano NanosecondsElapsed::microseconds() const
{
    return nanoseconds() / 1000;
}

inline Nano NanosecondsElapsed::milliseconds() const
{
    return microseconds() / 1000;
}

inline Nano NanosecondsElapsed::seconds() const
{
    return milliseconds() / 1000;
}

inline Nano NanosecondsElapsed::minutes() const
{
    return seconds() / 60;
}

inline Nano NanosecondsElapsed::hours() const
{
    return minutes() / 60;
}

inline QElapsedTimer::Duration NanosecondsElapsed::duration() const
{
    return mDuration;
}

