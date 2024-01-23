//!file {Eclipse6}/root/src/libs/eirCore6/Log.h Coder-facing log definitions
#pragma once
#include "eirCore6.h"

#include <QObject>
#include <QMessageLogger>

#include "LogMessage.h"

class EIRCORE6_EXPORT Log
{

public:
    Log();

private:
    static void logMessageHandler(QtMsgType qmt,
                                  const QMessageLogContext & context,
                                  const QString & message);
};


