#include "LogMessageQueue.h"

#include <QtDebug>

#include "ExeSupport.h"
Q_GLOBAL_STATIC(ExeSupport, EXE)

LogMessageQueue::LogMessageQueue(const Key key, QObject *parent)
    : QObject{parent}
    , m_queueKey(key)
    , m_queueUid(EXE->uid(key))
    , m_maxQueueCount(0) // unlimited
{
    qDebug() << Q_FUNC_INFO << key << queueUid().tail();
    setObjectName("LogMessageQueue:"+key);
}

void LogMessageQueue::clear()
{
    qDebug() << Q_FUNC_INFO << count();
    while ( ! isEmpty())
    {
        const Message tMessage = mMessageQueue.dequeue();
        emit discarded(tMessage);
    }
    Q_ASSERT(isEmpty());
    Q_ASSERT(0 == count());
    emit empty(isEmpty());
    emit countIs(count());
}

void LogMessageQueue::enqueue(const Message &msg)
{
    qDebug() << Q_FUNC_INFO << count();
    mMessageQueue.enqueue(msg);
    Q_ASSERT( ! isEmpty());
    Q_ASSERT(count() > 1);
    emit enqueued(msg);
    emit empty(isEmpty());
    emit countIs(count());
}

void LogMessageQueue::enqueue(const Message::List &msgs)
{
    foreach (Message tMsg, msgs) enqueue(tMsg);
}

void LogMessageQueue::dequeue(Count c)
{
    while (c--)
    {
        if (isEmpty())
        {
            emit dequeEmpty();
            break;
        }
        else
        {
            Message tMsg = mMessageQueue.dequeue();
            emit dequeued(tMsg);
        }
    }
    emit empty(isEmpty());
    emit countIs(count());
}

void LogMessageQueue::dequeueAll()
{
    dequeue(count());
}

