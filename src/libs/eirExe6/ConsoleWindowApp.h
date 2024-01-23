//!file {Eclipse6}/root/src/libs/eirExe6/ConsoleWindowApp.h Widget Application Support for ConsoleWindow
#pragma once
#include "eirExe6.h"

#include "ExeSupport.h"

class QApplication;

class EIREXE_EXPORT ConsoleWindowApp : public ExeSupport
{
public:
    ConsoleWindowApp(int &argc, char **argv);

public:

public slots:
    void initialize();
    void setup();
    void start();


private:
    QApplication * mpApp=nullptr;
};
