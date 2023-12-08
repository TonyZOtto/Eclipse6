# {Eclipse6}/root/src/console/If6Console/If6Console.pri
message(****/src/console/If6Console/If6Console.pro)

QT = core
TEMPLATE = app
TARGET = IfConsole
CONFIG += c++17 cmdline

include(../console.pri)
include(../../version.pri)
include(../../DESTDIR.pri)
include(AppVer.pri)
include(WinTarget.pri)
include(../../useBase.pri)
include(../../useCore.pri)
include(../../useExe.pri)

message(LIBDIR = $$LIBDIR)
message(INCLUDEPATH = $$INCLUDEPATH)
message(LIBS = $$LIBS)
message(DESTDIR = $$DESTDIR)
message(DESTDIR_TARGET = $$DESTDIR_TARGET)
message(TARGET = $$TARGET)
message(QMAKE_TARGET_COMPANY = $$QMAKE_TARGET_COMPANY)
message(EIRVER_APPNAME = $$EIRVER_APPNAME)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000
#   disables all the APIs deprecated before Qt 6.0.0
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SOURCES += \
        IfConsole.cpp \
        main.cpp


HEADERS += \
    ../../version.h \
    IfConsole.h \
    version.h

DISTFILES += \
