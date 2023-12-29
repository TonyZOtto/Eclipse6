#include "LogMessage.h"


LogMessage::LogMessage() {;}

LogMessage::LogMessage(const QMessageLogContext &qmlc)
{
    m_msgNano.sample();
    Q_UNUSED(qmlc);  // FIXME m_logContext.set(qmlc);
}

void LogMessage::set(const QMessageLogContext &qmlc)
{
    m_msgNano.sample();
    Q_UNUSED(qmlc);  // FIXME m_logContext.set(qmlc);
}
