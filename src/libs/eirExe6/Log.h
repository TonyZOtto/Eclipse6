//!file {Eclipse6}/root/src/libs/eirExe6/Log.h Coder-facing log definitions
#pragma once
#include "eirExe6.h"

#include <QObject>
#include <QMessageLogger>

class EIREXE_EXPORT Log
{

public:
    Log();

private:
    static void logMessageHandler(QtMsgType qmt,
              const QMessageLogContext & context,
              const QString & message);
};


