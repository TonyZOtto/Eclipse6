#include "ConsoleWindowApp.h"

#include <QApplication>

ConsoleWindowApp::ConsoleWindowApp(int &argc, char **argv)
    : mpApp(new QApplication(argc, argv))
{
    Q_ASSERT_X(mpApp, "ConsoleWindowApp", "Invalid mpApp");
    setObjectName("ConsoleWindowApp");
}

void ConsoleWindowApp::start()
{
    qInfo() << Q_FUNC_INFO;
}
