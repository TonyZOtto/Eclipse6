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
    Configuration.cpp \
    ConsoleApp.cpp \
    ConsoleAppMainWindow.cpp \
    ConsoleIO.cpp \
    ConsoleMessage.cpp \
    ConsoleMessageConfiguration.cpp \
    ConsoleMessageWidget.cpp \
    ConsoleStreamDisplay.cpp \
    ConsoleWindowApp.cpp \
    ExeSupport.cpp \
    Log.cpp \
    LogCacheBase.cpp \
    LogCacheFiles.cpp \
    LogEngine.cpp \
    LogFormatBase.cpp \
    LogFormatContextual.cpp \
    LogMessageQueue.cpp \
    LogOutputBase.cpp \
    LogOutputConsole.cpp \
    LogOutputTextFile.cpp \
    LogOutputTroll.cpp \
    Settings.cpp \
    SignalRecipient.cpp \
    UidManager.cpp \
    eirExe6.cpp

HEADERS += \
    AppArguments.h \
    AppSettings.h \
    ClockCalendar.h \
    CommandLine.h \
    Configuration.h \
    ConsoleApp.h \
    ConsoleAppMainWindow.h \
    ConsoleIO.h \
    ConsoleMessage.h \
    ConsoleMessageConfiguration.h \
    ConsoleMessageWidget.h \
    ConsoleStreamDisplay.h \
    ConsoleWindowApp.h \
    ExeSupport.h \
    Log.h \
    LogCacheBase.h \
    LogCacheFiles.h \
    LogEngine.h \
    LogFormatBase.h \
    LogFormatContextual.h \
    LogMacros.h \
    LogMessageQueue.h \
    LogOutputBase.h \
    LogOutputConsole.h \
    LogOutputTextFile.h \
    LogOutputTroll.h \
    Settings.h \
    SignalRecipient.h \
    UidManager.h \
    eirExe6_global.h \
    eirExe6.h \
    eirExe6_precompiled.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
