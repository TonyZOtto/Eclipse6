#include "LogContext.h"


void LogContext::set(const QMessageLogContext qmlc)
{
    m_functionInfo = FunctionInfo(qmlc.function);
    m_contextVersion = qmlc.version;
    m_lineNumber = qmlc.version;
    m_fileInfo = QFileInfo(qmlc.file);
    m_category = qmlc.category;
}
