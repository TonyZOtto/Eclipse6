#include "ConsoleApp.h"

#include <QCoreApplication>

#include "ConsoleIO.h"

ConsoleApp::ConsoleApp(int argc, char *argv[], QObject *parent)
    : ExeSupport{parent}
    , mpCoreApp(new QCoreApplication(argc, argv))
    , mpIO(new ConsoleIO(this))
{
    setObjectName("ConsoleApp");
    Q_ASSERT_X(mpCoreApp, "ConsoleApp ctor", "Invalid QCoreApplication pointer");
    Q_ASSERT_X(mpIO, "ConsoleApp ctor", "Invalid ConsoleIO child");

}
