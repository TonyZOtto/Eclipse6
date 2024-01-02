#include "LogEngine.h"

#include <QtDebug>

#include "ExeSupport.h"
Q_GLOBAL_STATIC(ExeSupport, EXE)

#include "LogMessageQueue.h"

LogEngine::LogEngine(QObject *parent)
    : QObject{parent}
    , mpInputQueue(new LogMessageQueue("eirExe/Log/MessageQueue/InputQueue", this))
{
    qDebug() << Q_FUNC_INFO;
    setObjectName("LogEngine");
    Q_ASSERT_X(mpInputQueue, Q_FUNC_INFO, "InputQueue");
}

void LogEngine::add(Message msg, QObject * sender)
{
    Q_ASSERT_X(mpInputQueue, Q_FUNC_INFO, "InputQueue");
    msg.set(EXE->uid(sender), EXE->uid(this));
    mpInputQueue->enqueue(msg);
}
