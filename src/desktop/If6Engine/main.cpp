#include "EngineMainWindow.h"

#include <ConsoleWindowApp.h>

int main(int argc, char *argv[])
{
    ConsoleWindowApp a(argc, argv);
    EngineMainWindow w;
    w.show();
    return a.exec();
}
