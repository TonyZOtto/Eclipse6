//!file {Eclipse6}/root/src/libs/eirExe6/ConsoleApp.h Console Application based on ExeSupport
#pragma once
#include "eirExe6.h"

#include <QObject>

class QCoreApplication;

#include "ExeSupport.h"
class ConsoleIO;

class EIREXE_EXPORT ConsoleApp : public ExeSupport
{
    Q_OBJECT
public:
    explicit ConsoleApp(int argc, char *argv[], QObject *parent = nullptr);

signals:

private:
    QCoreApplication * mpCoreApp=nullptr;
    ConsoleIO * mpIO=nullptr;
};
