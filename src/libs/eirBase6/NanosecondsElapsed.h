#pragma once

#include <QDateTime>
#include <QElapsedTimer>

#include "Types.h"

class NanosecondsElapsed
{
public:
    NanosecondsElapsed();

public: // const
    SQWORD nanoseconds() const;
    SQWORD microseconds() const;
    SQWORD milliseconds() const;
    SQWORD seconds() const;
    SQWORD minutes() const;
    SQWORD hours() const;
    QElapsedTimer::Duration duration() const;

public: // non-const
    void sample();

public:
    static QElapsedTimer::ClockType clockType();
    static bool isMonotonic();

private:

private:
    static QDateTime mBaseTime;
    static QElapsedTimer mElapsedTimer;
    QElapsedTimer::Duration mDuration;
};

inline SQWORD NanosecondsElapsed::nanoseconds() const
{
    return duration().count();
}

inline SQWORD NanosecondsElapsed::microseconds() const
{
    return nanoseconds() / 1000;
}

inline SQWORD NanosecondsElapsed::milliseconds() const
{
    return microseconds() / 1000;
}

inline SQWORD NanosecondsElapsed::seconds() const
{
    return milliseconds() / 1000;
}

inline SQWORD NanosecondsElapsed::minutes() const
{
    return seconds() / 60;
}

inline SQWORD NanosecondsElapsed::hours() const
{
    return minutes() / 60;
}

inline QElapsedTimer::Duration NanosecondsElapsed::duration() const
{
    return mDuration;
}
