#include "IfConsole.h"

#include <QtDebug>

#include <QCoreApplication>

IfConsole::IfConsole(int &argc, char **argv)
    : ConsoleApp(argc, argv)
{

}

void IfConsole::start()
{
    qInfo() << qApp->applicationName() << qApp->applicationVersion();
}
