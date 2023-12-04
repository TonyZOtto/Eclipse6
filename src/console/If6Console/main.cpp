#include "Console.h"
#include "../../version.h"
#include "version.h"

#include <QTimer>

#include <VersionInfo.h>

int main(int argc, char *argv[])
{
    VersionInfo v(VER_MAJOR, VER_MINOR, VER_BRANCH, VER_RELEASE,
                  VER_APPNAME, VER_ORGNAME, VER_COPYRIGHT, VER_COMMENT);
    Console a(argc, argv);
    a.setApplicationName(VER_APPNAME);
    a.setApplicationVersion(v.string());
    QTimer::singleShot(500, &a, &Console::start);
    return a.exec();
}
