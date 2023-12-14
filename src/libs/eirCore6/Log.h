//!file {Eclipse6}/root/src/libs/eirCore6/Log.h Coder-facing log definitions
#pragma once
#include "eirCore6.h"

#include <QObject>
#include <QMessageLogger>

class EIRCORE6_EXPORT Log
{

public:
    Log();

private:
    //static QtMessageHandler logMessageHandler;
    static void logMessageHandler(QtMsgType qmt,
                                  const QMessageLogContext & context,
                                  const QString & message);
};

#include "LogMacros.h"

