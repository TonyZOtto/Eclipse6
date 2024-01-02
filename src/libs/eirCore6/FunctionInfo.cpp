#include "FunctionInfo.h"

FunctionInfo::FunctionInfo(const QMessageLogContext context)
{
    parse(context.function, context.file, context.category,
          context.line, context.version);
}

FunctionInfo::FunctionInfo(const char *qfi,
                           const char *fileName,
                           const char *category,
                           const int fileLine,
                           const int contextVersion)
{
    parse(qfi, fileName, category, fileLine, contextVersion);
}

QString FunctionInfo::fullFunction() const
{
    QString result;
    result += functionName();
    result += "(";
    // TODO foreach(argument)
    result += ")";
    return result;
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
