//!file {Eclipse6}/root/src/libs/eirExe6/ExeSupport.h Basic Executable (.exe or .dll) Support Class
#pragma once
#include "eirExe6.h"


/* in .cpp file
#include "ExeSupport.h"
Q_GLOBAL_STATIC(ExeSupport, EXE)
*/

#include <Uid.h>
#include <Key.h>

#include "Log.h"
class AppArguments;
class AppSettings;
class ClockCalendar;
class CommandLine;
class UidManager;

class EIREXE_EXPORT ExeSupport : public QObject
{
    Q_OBJECT
public:
    explicit ExeSupport(QObject *parent = nullptr);

public:
    Uid uid(const Key &key);
    Uid uid(QObject * obj);
    Key key(const Uid uid);

signals:

private:
    UidManager * mpUidManager=nullptr;
    ClockCalendar * mpClockCalendar=nullptr;
    AppArguments * mpArguments=nullptr;
    AppSettings * mpSettings=nullptr;
    CommandLine * mpCommandLine=nullptr;
    Log mLog;
};
