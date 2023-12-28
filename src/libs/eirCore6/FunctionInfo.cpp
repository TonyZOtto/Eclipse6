#include "FunctionInfo.h"

FunctionInfo::FunctionInfo(const LogContext context)
    : m_context(context)
{
    parse();
}

void FunctionInfo::parse(const LogContext context)
{
    m_context = context;
    parse();
}

void FunctionInfo::parse()
{
    m_qFuncInfo = m_context.functionInfo().m_qFuncInfo;
    m_fileInfo = QFileInfo(m_context().m_fileName);
    m_fileLine = m_context.lineNumber();
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
