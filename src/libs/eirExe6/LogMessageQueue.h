//!file {Eclipse6}/root/src/libs/eirExe6/LogMessageQueue.h Queues for holding messages in the engine
#pragma once
#include "eirExe6.h"

#include <QObject>

#include <QQueue>

#include <Types.h>

#include "Key.h"
#include "Message.h"

class EIREXE_EXPORT LogMessageQueue : public QObject
{
    Q_OBJECT
public: // ctors
    LogMessageQueue(const Key key,
                    QObject *parent = nullptr);

public: // const
    bool isEmpty() const;
    Count count() const;
    Message peek() const;
    Message::List peekAll() const;
    Message::List peek(const Count c) const;

public: // non-const
    Message take();
    Message::List takeAll();
    Message::List take(const Count c);

public slots:
    void clear();
    void enqueue(const Message &msg);
    void enqueue(const Message::List &msgs);
    void dequeue(Count c=1); // to signal(s)
    void dequeueAll(); // to signal, if any

signals:
    void empty(const bool is);
    void countIs(const Count n);
    void enqueued(const Message &msg);
    void dequeued(const Message &msg);
    void dequeEmpty();
    void taken(const Message &msg);
    void discarded(const Message &msg);

private:
    QQueue<Message> mMessageQueue;

    // ================ PROPERTIES ==============
    const Key m_queueKey;
    const Uid m_queueUid;
    Count m_maxQueueCount;

    Q_PROPERTY(Key queueKey READ queueKey CONSTANT FINAL)
    Q_PROPERTY(Uid queueUid READ queueUid CONSTANT FINAL)
    Q_PROPERTY(Count maxQueueCount READ maxQueueCount WRITE maxQueueCount RESET reset_maxQueueCount NOTIFY changed_maxQueueCount FINAL)

public:
    Key queueKey() const
    {
        return m_queueKey;
    }
    Uid queueUid() const
    {
        return m_queueUid;
    }
    Count maxQueueCount() const
    {
        return m_maxQueueCount;
    }
    void maxQueueCount(Count new_maxQueueCount)
    {
        if (m_maxQueueCount == new_maxQueueCount)
            return;
        m_maxQueueCount = new_maxQueueCount;
        emit changed_maxQueueCount();
    }
    void reset_maxQueueCount()
    {
        maxQueueCount(0); // zero=unlimited
    }
signals:
    void changed_maxQueueCount();
};

inline bool LogMessageQueue::isEmpty() const
{
    return mMessageQueue.isEmpty();
}

inline Count LogMessageQueue::count() const
{
    return mMessageQueue.count();
}
