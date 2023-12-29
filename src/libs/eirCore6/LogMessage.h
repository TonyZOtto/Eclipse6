#pragma once

#include <QObject>
#include "Message.h"

#include <NanosecondsElapsed.h>

#include "FunctionInfo.h"

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
    NanosecondsElapsed m_msgNano;
    FunctionInfo m_functionInfo;
    Q_PROPERTY(NanosecondsElapsed msgNano READ msgNano CONSTANT FINAL)
    Q_PROPERTY(FunctionInfo functionInfo READ functionInfo CONSTANT FINAL)

public:
    NanosecondsElapsed msgNano() const
    {
        return m_msgNano;
    }
    FunctionInfo functionInfo() const
    {
        return m_functionInfo;
    }
};
