//!file {Eclipse6}/root/src/libs/eirExe6/ConsoleWindowApp.h Widget Application Support for ConsoleWindow
#pragma once
#include "eirExe6.h"

#include <QApplication>
#include <QObject>

class EIREXE_EXPORT ConsoleWindowApp : public QApplication
{
public:
    ConsoleWindowApp(int &argc, char **argv);
};
