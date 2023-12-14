#pragma once

#include <QDateTime>
#include <QElapsedTimer>

#include "Types.h"

class NanosecondTime
{
public:
    NanosecondTime();

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
    static void staticStart();

private:
    static QDateTime mBaseTime;
    static QElapsedTimer mElapsedTimer;
    QElapsedTimer::Duration mDuration;
};

inline SQWORD NanosecondTime::nanoseconds() const
{
    return duration().count();
}

inline SQWORD NanosecondTime::microseconds() const
{
    return nanoseconds() / 1000;
}

inline SQWORD NanosecondTime::milliseconds() const
{
    return microseconds() / 1000;
}

inline SQWORD NanosecondTime::seconds() const
{
    return milliseconds() / 1000;
}

inline SQWORD NanosecondTime::minutes() const
{
    return seconds() / 60;
}

inline SQWORD NanosecondTime::hours() const
{
    return minutes() / 60;
}

inline QElapsedTimer::Duration NanosecondTime::duration() const
{
    return mDuration;
}
