#include "EngineMainWindow.h"

#include <ConsoleWindowApp.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EngineMainWindow w;
    w.show();
    return a.exec();
}
