#include "ConsoleWindowApp.h"

#include <QApplication>

ConsoleWindowApp::ConsoleWindowApp(int &argc, char **argv)
    : mpApp(new QApplication(argc, argv))
{
    qDebug() << Q_FUNC_INFO;
    Q_ASSERT_X(mpApp, "ConsoleWindowApp", "Invalid mpApp");
    setObjectName("ConsoleWindowApp");
}

void ConsoleWindowApp::start()
{
    qDebug() << Q_FUNC_INFO;
}
