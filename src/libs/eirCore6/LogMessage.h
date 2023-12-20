#pragma once

#include <QObject>
#include "Message.h"

#include <NanosecondsElapsed.h>

#include "LogContext.h"
#include "MessageTrackingItem.h"

class LogMessage : public Message
{
    Q_GADGET

public: // ctors
    LogMessage() {;}

public: // non-const
    void set(const QMessageLogContext qmlc);
    void track(const MessageTrackingItem &mti);

    // ====================== PROPERTIES ===================
private:
    LogContext m_logContext;
    NanosecondsElapsed m_msgNano;
    QMap<NanosecondsElapsed, MessageTrackingItem> m_tracking;
    Q_PROPERTY(LogContext logContext READ logContext CONSTANT FINAL)
    Q_PROPERTY(NanosecondsElapsed msgNano READ msgNano CONSTANT FINAL)
    Q_PROPERTY(QMap<NanosecondsElapsed, MessageTrackingItem> tracking READ tracking CONSTANT FINAL)

public:
    LogContext logContext() const
    {
        return m_logContext;
    }
    NanosecondsElapsed msgNano() const
    {
        return m_msgNano;
    }
    QMap<NanosecondsElapsed, MessageTrackingItem> tracking() const
    {
        return m_tracking;
    }
};
