//!file {Eclipse6}/root/src/libs/eirExe6/ExeSupport.h Basic Executable (.exe or .dll) Support Class
#pragma once
#include "eirExe6.h"

class AppArguments;
class AppSettings;
class ClockCalendar;
class CommandLine;

#include <Log.h>

/*
Q_GLOBAL_STATIC(EXE, ExeSupport)
*/

class EIREXE_EXPORT ExeSupport : public QObject
{
    Q_OBJECT
public:
    explicit ExeSupport(QObject *parent = nullptr);

public:

signals:

private:
    ClockCalendar * mpClockCalendar=nullptr;
    AppArguments * mpArguments=nullptr;
    AppSettings * mpSettings=nullptr;
    CommandLine * mpCommandLine=nullptr;
    Log mLog;
};
