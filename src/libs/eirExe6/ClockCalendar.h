//!file {Eclipse6}/root/src/libs/eirExe6/ClockCalendar.h Send signals based upon time and day
#pragma once
#include "eirExe6.h"

#include <QObject>

#include <EpochTime.h>
#include <Uid.h>

#include "ExeSupport.h"
#include "SignalRecipient.h"

class EIREXE_EXPORT ClockCalendar : public QObject
{
    Q_OBJECT
public: // types

public: // ctors
    explicit ClockCalendar(ExeSupport *parent = nullptr);

public slots:
    void signalAt(const Uid uid, const QDateTime dt);
    void signalIn(const Uid uid, const QTime tm);
    void signalEvery(const Uid uid, const QTime tm);

signals:
    void newMinute(const QDateTime cdt);
    void minuteOfHour(const int moh);
    void newHour(const QDateTime cdt);
    void quarterHour(const QDateTime cdt);
    void halfHour(const QDateTime cdt);
    void hourOfDay(const int hod);
    void newDay(const QDateTime cdt);
    void signal(const Uid uid, const QDateTime cdt);

private:
    QMultiMap<EpochTime, SignalRecipient> mAtTimeRecipientMMap;
    QMultiMap<QTime, SignalRecipient> mEveryTimeRecipientMMap;
    QMultiMap<SignalRecipient, QTime> mEveryRecipientTimeMMap;

};
