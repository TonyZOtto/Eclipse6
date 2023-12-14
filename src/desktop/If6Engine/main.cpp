#include "EngineMainWindow.h"

#include <QCoreApplication>
#include <QTimer>

#include <ConsoleWindowApp.h>
#include <Log.h>
#include <VersionInfo.h>

#include "../../version.h"
#include "version.h"

int main(int argc, char *argv[])
{
    ConsoleWindowApp a(argc, argv);
    EngineMainWindow w;
    VersionInfo v(VER_MAJOR, VER_MINOR, VER_BRANCH, VER_RELEASE,
                  VER_APPNAME, VER_ORGNAME, VER_COPYRIGHT, VER_COMMENT);
    QCoreApplication::setApplicationName(VER_APPNAME);
    QCoreApplication::setApplicationVersion(v.string());

    w.show();
    QTimer::singleShot(500, &a, &ConsoleWindowApp::start);
    return QCoreApplication::exec();
}
