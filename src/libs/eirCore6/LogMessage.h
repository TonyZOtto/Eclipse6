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
    LogMessage();
    LogMessage(const QMessageLogContext &qmlc);

public: // non-const
    void set(const QMessageLogContext &qmlc);

    // ====================== PROPERTIES ===================
private:
    LogContext m_logContext;
    NanosecondsElapsed m_msgNano;
    Q_PROPERTY(LogContext logContext READ logContext CONSTANT FINAL)
    Q_PROPERTY(NanosecondsElapsed msgNano READ msgNano CONSTANT FINAL)

public:
    LogContext logContext() const
    {
        return m_logContext;
    }
    NanosecondsElapsed msgNano() const
    {
        return m_msgNano;
    }
};
