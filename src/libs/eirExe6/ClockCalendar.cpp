#include "ClockCalendar.h"

ClockCalendar::ClockCalendar(QObject *parent)
    : QObject{parent}
{
    setObjectName("ClockCalendar");
}

void ClockCalendar::signalAt(const Uid uid, const QDateTime dt)
{

}

void ClockCalendar::signalIn(const Uid uid, const QTime tm)
{

}

void ClockCalendar::signalEvery(const Uid uid, const QTime tm)
{

}
