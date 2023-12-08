# {Eclipse6}/root/src/libs/eirBase6/eirExe6.pri
message(/root/src/libs/eirBase6/eirExe6.pri)

QT += core gui widgets
TEMPLATE = lib
TARGET = eirExe
CONFIG += c++17
DEFINES += EIREXE_LIBRARY
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../../version.pri)
include(../../DESTDIR.pri)
message(DESTDIR = $$DESTDIR)
message(TARGET = $$TARGET)

SOURCES += \
    AppArguments.cpp \
    AppSettings.cpp \
    CommandLine.cpp \
    ConsoleApp.cpp \
    ConsoleIO.cpp \
    ConsoleMessage.cpp \
    ConsoleMessageWidget.cpp \
    ConsoleWindow.cpp \
    ConsoleWindowApp.cpp \
    ConsoleWindowAppMain.cpp \
    ExeSupport.cpp \
    eirExe6.cpp

HEADERS += \
    AppArguments.h \
    AppSettings.h \
    CommandLine.h \
    ConsoleApp.h \
    ConsoleIO.h \
    ConsoleMessage.h \
    ConsoleMessageWidget.h \
    ConsoleWindow.h \
    ConsoleWindowApp.h \
    ConsoleWindowAppMain.h \
    ExeSupport.h \
    eirExe_global.h \
    eirExe6.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
