#include "LogMessage.h"


LogMessage::LogMessage() {;}

LogMessage::LogMessage(const QMessageLogContext &qmlc)
{
    m_logContext.set(qmlc);
}

void LogMessage::set(const QMessageLogContext &qmlc)
{
    m_logContext.set(qmlc);
}
