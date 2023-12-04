#include "Console.h"

Console::Console(int &argc, char **argv)
    : QCoreApplication(argc, argv)
{

}

void Console::start()
{
    qInfo() << qApp->applicationName() << qApp->applicationVersion();
}
