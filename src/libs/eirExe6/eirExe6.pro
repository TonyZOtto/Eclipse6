# {Eclipse6}/root/src/libs/eirBase6/eirExe6.pro
message(===============/root/src/libs/eirBase6/eirExe6.pro)

QT *= core
QT *= gui
QT *= widgets
TEMPLATE = lib
TARGET = eirExe
CONFIG += c++17
DEFINES += EIREXE_LIBRARY
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../../version.pri)
include(../../DESTDIR.pri)
include(../libs.pri)
include(../../useBase.pri)
include(../../useCore.pri)
message(DESTDIR = $$DESTDIR)
message(TARGET = $$TARGET)
message(QT = $$QT)
message(INCLUDEPATH = $$INCLUDEPATH)

PRECOMPILED_HEADER = eirExe6_precompiled.h

SOURCES += \
    AppArguments.cpp \
    AppSettings.cpp \
    ClockCalendar.cpp \
    CommandLine.cpp \
    ConsoleApp.cpp \
    ConsoleIO.cpp \
    ConsoleMessage.cpp \
    ConsoleMessageDisplay.cpp \
    ConsoleMessageWidget.cpp \
    ConsoleWindowApp.cpp \
    ConsoleWindowAppMain.cpp \
    ExeSupport.cpp \
    SignalRecipient.cpp \
    eirExe6.cpp

HEADERS += \
    AppArguments.h \
    AppSettings.h \
    ClockCalendar.h \
    CommandLine.h \
    ConsoleApp.h \
    ConsoleIO.h \
    ConsoleMessage.h \
    ConsoleMessageDisplay.h \
    ConsoleMessageWidget.h \
    ConsoleWindowApp.h \
    ConsoleWindowAppMain.h \
    ExeSupport.h \
    SignalRecipient.h \
    eirExe6_global.h \
    eirExe6.h \
    eirExe6_precompiled.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
