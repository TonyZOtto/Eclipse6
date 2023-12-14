//!file {Eclipse6}/root/src/libs/eirExe6/ExeSupport.h Basic Executable (.exe or .dll) Support Class
#pragma once
#include "eirExe6.h"

class AppArguments;
class AppSettings;
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
    QDateTime baseTime() const;
    QTimeZone baseZone() const;
    QWORD nsecElapsed() const;

signals:

private:
    AppArguments * mpArguments=nullptr;
    AppSettings * mpSettings=nullptr;
    CommandLine * mpCommandLine=nullptr;
    Log mLog;
};
