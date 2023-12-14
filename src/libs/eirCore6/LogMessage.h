#pragma once

#include <QObject>
#include "Message.h"

#include <QLoggingCategory>

class LogMessage : public Message
{
    Q_GADGET
public:

    // ====================== PROPERTIES ===================
private:
    QMessageLogContext m_LogContext;
    QDateTime m_CreatedTime;
    Level m_MsgLevel;

public:
    LogMessage();
};
