#include "LogContext.h"


LogContext::LogContext()
{
    m_contextVersion = m_lineNumber = 0;
}

LogContext::LogContext(const QMessageLogContext qmlc)
{
    m_functionInfo = FunctionInfo(qmlc.function),
        m_contextVersion = qmlc.version,
        m_lineNumber = qmlc.version,
        m_fileInfo = QFileInfo(qmlc.file),
        m_category = qmlc.category;
}

LogContext::LogContext(const LogContext &other)
{
    m_functionInfo = other.m_functionInfo,
        m_contextVersion = other.m_contextVersion,
        m_lineNumber = other.m_lineNumber,
        m_fileInfo = other.m_fileInfo,
        m_category = other.m_category;
}

void LogContext::set(const QMessageLogContext qmlc)
{
    m_functionInfo = FunctionInfo(qmlc.function),
        m_contextVersion = qmlc.version,
        m_lineNumber = qmlc.version,
        m_fileInfo = QFileInfo(qmlc.file),
        m_category = qmlc.category;
}
