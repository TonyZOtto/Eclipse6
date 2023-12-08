#include "IfConsole.h"
#include "../../version.h"
#include "version.h"

#include <QCoreApplication>
#include <QTimer>

#include <VersionInfo.h>

int main(int argc, char *argv[])
{
    VersionInfo v(VER_MAJOR, VER_MINOR, VER_BRANCH, VER_RELEASE,
                  VER_APPNAME, VER_ORGNAME, VER_COPYRIGHT, VER_COMMENT);
    IfConsole a(argc, argv);
    QCoreApplication::setApplicationName(VER_APPNAME);
    QCoreApplication::setApplicationVersion(v.string());
    QTimer::singleShot(500, &a, &IfConsole::start);
    return QCoreApplication::exec();
}
