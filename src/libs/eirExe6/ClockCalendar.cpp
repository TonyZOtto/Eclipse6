#include "ClockCalendar.h"

#include "ExeSupport.h"

ClockCalendar::ClockCalendar(ExeSupport *parent)
    : QObject{parent}
{
    setObjectName("ClockCalendar");
}

void ClockCalendar::signalAt(const Uid uid, const QDateTime dt)
{
    Q_UNUSED(uid); Q_UNUSED(dt); // TODO signalAt
}

void ClockCalendar::signalIn(const Uid uid, const QTime tm)
{
    Q_UNUSED(uid); Q_UNUSED(tm); // TODO signalAt

}

void ClockCalendar::signalEvery(const Uid uid, const QTime tm)
{
    Q_UNUSED(uid); Q_UNUSED(tm); // TODO signalAt

}
