#include "MillisecondTime.h"


MillisecondTime::MillisecondTime()
{
    mDateTime=QDateTime::currentDateTime();
    mTimeZone=QTimeZone(QTimeZone::LocalTime);
}

MillisecondTime::MillisecondTime(const QDateTime dt,
                                 const QTimeZone::Initialization tzi)
{
    mDateTime = dt, mTimeZone = QTimeZone(tzi);
}

MillisecondTime::MillisecondTime(const QDateTime dt,
                                 const QTimeZone &tz)
{
    mDateTime = dt, mTimeZone = tz;
}

MillisecondTime::MillisecondTime(const EpochMilliseconds ems,
                                 const QTimeZone::Initialization tzi)
{
    mDateTime = QDateTime::fromMSecsSinceEpoch(ems),
        mTimeZone = QTimeZone(tzi);
}

MillisecondTime::MillisecondTime(const EpochMilliseconds ems,
                                 const QTimeZone &tz)
{
    mDateTime = QDateTime::fromMSecsSinceEpoch(ems), mTimeZone = tz;
}

QDateTime MillisecondTime::dateTime() const
{
    return mDateTime;
}

EpochMilliseconds MillisecondTime::ems() const
{
    return mDateTime.toMSecsSinceEpoch();
}

EpochMilliseconds MillisecondTime::emsLocal() const
{
    return mDateTime.toLocalTime().toMSecsSinceEpoch();
}

EpochMilliseconds MillisecondTime::emsUtc() const
{
    return mDateTime.toUTC().toMSecsSinceEpoch();
}

QTimeZone MillisecondTime::timeZone() const
{
    return mTimeZone;
}

int MillisecondTime::tzOffset() const
{
    return mTimeZone.offsetFromUtc(mDateTime);
}

bool MillisecondTime::isNull() const
{
    return mDateTime.isNull() && ! mTimeZone.isValid();
}

void MillisecondTime::set(const QDateTime dt, const QTimeZone::Initialization tzi)
{
    mDateTime = dt, mTimeZone = QTimeZone(tzi);
}

void MillisecondTime::set(const QDateTime dt, const QTimeZone &tz)
{
    mDateTime = dt, mTimeZone = tz;
}

void MillisecondTime::set(const EpochMilliseconds ems,
                          const QTimeZone::Initialization tzi)
{
    mDateTime = QDateTime::fromMSecsSinceEpoch(ems),
        mTimeZone = QTimeZone(tzi);
}

void MillisecondTime::set(const EpochMilliseconds ems,
                          const QTimeZone &tz)
{
    mDateTime = QDateTime::fromMSecsSinceEpoch(ems), mTimeZone = tz;
}

void MillisecondTime::setUtc(const QDateTime dt)
{
    mDateTime = dt.toUTC(), mTimeZone = QTimeZone(QTimeZone::UTC);
}

void MillisecondTime::setUtc(const EpochMilliseconds ems)
{
    mDateTime = QDateTime::fromMSecsSinceEpoch(ems).toUTC(),
        mTimeZone = QTimeZone(QTimeZone::UTC);
}

void MillisecondTime::set(const QTimeZone &tz)
{
    mTimeZone = tz;
}

void MillisecondTime::set(const QTimeZone::Initialization tzi)
{
    mTimeZone = QTimeZone(tzi);
}

// static
MillisecondTime MillisecondTime::null() const
{
    return MillisecondTime(QDateTime(), QTimeZone());
}

