#include "FunctionInfo.h"

FunctionInfo::FunctionInfo(const QString &qfi)
    : m_qFuncInfo(qfi)
{
    parse();
}

void FunctionInfo::parse(const QString &qfi)
{
    m_qFuncInfo = qfi;
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
