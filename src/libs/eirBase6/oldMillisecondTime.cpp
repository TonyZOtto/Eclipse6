#include "oldMillisecondTime.h"


oldMillisecondTime::oldMillisecondTime()
{
    mDateTime=QDateTime::currentDateTime();
    mTimeZone=QTimeZone(QTimeZone::LocalTime);
}

oldMillisecondTime::oldMillisecondTime(const QDateTime dt,
                                 const QTimeZone::Initialization tzi)
{
    mDateTime = dt, mTimeZone = QTimeZone(tzi);
}

oldMillisecondTime::oldMillisecondTime(const QDateTime dt,
                                 const QTimeZone &tz)
{
    mDateTime = dt, mTimeZone = tz;
}

oldMillisecondTime::oldMillisecondTime(const EpochMilliseconds ems,
                                 const QTimeZone::Initialization tzi)
{
    mDateTime = QDateTime::fromMSecsSinceEpoch(ems),
        mTimeZone = QTimeZone(tzi);
}

oldMillisecondTime::oldMillisecondTime(const EpochMilliseconds ems,
                                 const QTimeZone &tz)
{
    mDateTime = QDateTime::fromMSecsSinceEpoch(ems), mTimeZone = tz;
}

QDateTime oldMillisecondTime::dateTime() const
{
    return mDateTime;
}

EpochMilliseconds oldMillisecondTime::ems() const
{
    return mDateTime.toMSecsSinceEpoch();
}

EpochMilliseconds oldMillisecondTime::emsLocal() const
{
    return mDateTime.toLocalTime().toMSecsSinceEpoch();
}

EpochMilliseconds oldMillisecondTime::emsUtc() const
{
    return mDateTime.toUTC().toMSecsSinceEpoch();
}

QTimeZone oldMillisecondTime::timeZone() const
{
    return mTimeZone;
}

int oldMillisecondTime::tzOffset() const
{
    return mTimeZone.offsetFromUtc(mDateTime);
}

bool oldMillisecondTime::isNull() const
{
    return mDateTime.isNull() && ! mTimeZone.isValid();
}

void oldMillisecondTime::set(const QDateTime dt, const QTimeZone::Initialization tzi)
{
    mDateTime = dt, mTimeZone = QTimeZone(tzi);
}

void oldMillisecondTime::set(const QDateTime dt, const QTimeZone &tz)
{
    mDateTime = dt, mTimeZone = tz;
}

void oldMillisecondTime::set(const EpochMilliseconds ems,
                          const QTimeZone::Initialization tzi)
{
    mDateTime = QDateTime::fromMSecsSinceEpoch(ems),
        mTimeZone = QTimeZone(tzi);
}

void oldMillisecondTime::set(const EpochMilliseconds ems,
                          const QTimeZone &tz)
{
    mDateTime = QDateTime::fromMSecsSinceEpoch(ems), mTimeZone = tz;
}

void oldMillisecondTime::setUtc(const QDateTime dt)
{
    mDateTime = dt.toUTC(), mTimeZone = QTimeZone(QTimeZone::UTC);
}

void oldMillisecondTime::setUtc(const EpochMilliseconds ems)
{
    mDateTime = QDateTime::fromMSecsSinceEpoch(ems).toUTC(),
        mTimeZone = QTimeZone(QTimeZone::UTC);
}

void oldMillisecondTime::set(const QTimeZone &tz)
{
    mTimeZone = tz;
}

void oldMillisecondTime::set(const QTimeZone::Initialization tzi)
{
    mTimeZone = QTimeZone(tzi);
}

// static
oldMillisecondTime oldMillisecondTime::null() const
{
    return oldMillisecondTime(QDateTime(), QTimeZone());
}

