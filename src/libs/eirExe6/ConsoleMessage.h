//!file {Eclipse6}/root/src/libs/eirExe6/CommandLine.h Parses Command Line for ExeSupport
#pragma once
#include "eirExe6.h"

#include <QObject>

#include <MillisecondTime.h>
#include <Types.h>

class ConsoleMessage
{
    Q_GADGET
public:


public:
    explicit ConsoleMessage();

signals:

    // =================== PROPERTIES ===================
private:
    /*Log::Level*/ int mLevel;
    MillisecondTime mCreatedMst;

};
