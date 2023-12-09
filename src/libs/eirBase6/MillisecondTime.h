//!file {Eclipse6}/root/src/libs/eirBase6/VersionInfo.h Manage version numbers; wraps QVersionNumber
#pragma once
#include "eirBase6.h"

#include <QDateTime>
#include <QTimeZone>
#include <QString>

#include "Types.h"

class EIRBASE6_EXPORT MillisecondTime
{
public:
    MillisecondTime();
    MillisecondTime(const QDateTime dt,
                    const QTimeZone::Initialization tzi=QTimeZone::LocalTime);
    MillisecondTime(const QDateTime dt, const QTimeZone &tz);
    MillisecondTime(const EpochMilliseconds ems,
                    const QTimeZone::Initialization tzi=QTimeZone::LocalTime);
    MillisecondTime(const EpochMilliseconds ems, const QTimeZone &tz);

public:
    QDateTime dateTime() const;
    EpochMilliseconds ems() const;
    EpochMilliseconds emsLocal() const;
    EpochMilliseconds emsUtc() const;
    QTimeZone timeZone() const;
    int tzOffset() const;
    bool isNull() const;

public:
    void set(const QDateTime dt,
             const QTimeZone::Initialization tzi=QTimeZone::LocalTime);
    void set(const QDateTime dt, const QTimeZone &tz);
    void set(const EpochMilliseconds ems,
             const QTimeZone::Initialization tzi=QTimeZone::LocalTime);
    void set(const EpochMilliseconds ems, const QTimeZone &tz);
    void setUtc(const QDateTime dt);
    void setUtc(const EpochMilliseconds ems);
    void set(const QTimeZone &tz);
    void set(const QTimeZone::Initialization tzi);

public:
    MillisecondTime null() const;

private:
    QDateTime mDateTime=QDateTime::currentDateTime();
    QTimeZone mTimeZone=QTimeZone(QTimeZone::LocalTime);
};
