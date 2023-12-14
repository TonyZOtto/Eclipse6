# {Eclipse6}/root/src/console/If6Console/If6Console.pri
message(****/src/console/If6Console/If6Console.pro)

QT       += core gui widgets
TEMPLATE = app
TARGET = IfEngine
CONFIG += c++17

include(../desktop.pri)
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


SOURCES += \
    main.cpp \
    EngineMainWindow.cpp

HEADERS += \
    ../../version.h \
    EngineMainWindow.h \
    version.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
