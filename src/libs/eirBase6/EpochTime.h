//!file {Eclipse6}/root/src/libs/eirBase6/EpochTime.h Epoch Milliseconds represemtation of date and time
#pragma once
#include "eirBase6.h"

#include <QDateTime>
#include <QString>
#include <QTime>

#include "Types.h"

class EIRBASE6_EXPORT EpochTime
{
public:
    EpochTime() : mMsec(0) {;}
    EpochTime(const SQWORD msec) : mMsec(msec) {;}
    EpochTime(const QTime qtm) : mMsec(qtm.msec()) {;}
    EpochTime(const QDateTime qdt) : mMsec(qdt.time().msec()) {;}

public: // const
    QDateTime toDateTime() const;
    QString toString(Qt::DateFormat format = Qt::TextDate) const;
    SQWORD toSQWord() const { return mMsec; }
    SQWORD operator() () const { return toSQWord(); }
    operator SQWORD() const { return toSQWord(); }

public: // non-const
    void clear();
    void set(const SQWORD msec) { mMsec = msec; }
    void set(const QTime qtm) { mMsec = qtm.msec(); }
    void set(const QDateTime qdt) { mMsec = qdt.time().msec(); }

public: // static
    static EpochTime current();

private:
    SQWORD mMsec;
};

inline QDateTime EpochTime::toDateTime() const
{
    return QDateTime::fromMSecsSinceEpoch(mMsec);
}

inline QString EpochTime::toString(Qt::DateFormat format) const
{
    return toDateTime().toString(format);
}
