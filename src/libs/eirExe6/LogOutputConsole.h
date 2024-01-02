//!file {Eclipse6}/root/src/libs/eirExe6/LogOutputConsole.h Log message output to a console widget
#pragma once
#include "eirExe6.h"

#include "LogOutputBase.h"

class EIREXE_EXPORT LogOutputConsole : public LogOutputBase
{
    Q_OBJECT
public:
    explicit LogOutputConsole(QObject *parent = nullptr);
};
