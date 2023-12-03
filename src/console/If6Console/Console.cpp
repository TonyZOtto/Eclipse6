#include "Console.h"

Console::Console(int &argc, char **argv)
    : QCoreApplication(argc, argv)
{

}

void Console::start()
{
    qInfo() << Q_FUNC_INFO << qApp->applicationVersion();
}
