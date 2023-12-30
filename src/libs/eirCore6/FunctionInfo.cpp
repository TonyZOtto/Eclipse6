#include "FunctionInfo.h"

FunctionInfo::FunctionInfo(const QMessageLogContext context)
{
    m_qFuncInfo = QString(context.function),
        m_fileInfo = QFileInfo(context.file),
        m_fileLine = context.line,
        m_logCategory = QString(context.category),
        m_contextVersion = context.version;
    parse();
}

void FunctionInfo::parse(const char *qfi,
                         const char *fileName,
                         const char *category,
                         const int fileLine,
                         const int contextVersion)
{
    m_qFuncInfo = QString(qfi),
        m_fileInfo = QFileInfo(fileName),
        m_fileLine = fileLine,
        m_logCategory = QString(category),
        m_contextVersion = contextVersion;
    parse();
}

void FunctionInfo::parse()
{
    initialSplit();
    handleAnte();
    handleNames();
    handlePost();
    splitArguments();
    // TODO
}

void FunctionInfo::initialSplit()
{
    // TODO

}

void FunctionInfo::handleAnte()
{
    // TODO

}

void FunctionInfo::handleNames()
{
    // TODO

}

void FunctionInfo::handlePost()
{
    // TODO

}

void FunctionInfo::splitArguments()
{
    // TODO

}
