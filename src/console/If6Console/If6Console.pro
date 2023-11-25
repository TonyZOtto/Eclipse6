# {Eclipse6}/root/src/console/If6Console/If6Console.pri
message(/root/src/console/If6Console/If6Console.pri)

QT = core
CONFIG += c++17 cmdline

include(../console.pri)
include(AppVer.pri)
include(WinTarget.pri)
include(../../useBase.pri)
include(../../useCore.pri)
#INCLUDEPATH *= ../../libs/eirBase6
message(INCLUDEPATH = $$INCLUDEPATH)
message(LIBS = $$LIBS)
message(QMAKE_TARGET_COMPANY = $$QMAKE_TARGET_COMPANY)
message(EIRVER_APPNAME = $$EIRVER_APPNAME)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Console.cpp \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ../../../../version.h \
    Console.h \
    version.h

DISTFILES += \
    ../../../RootVer.pri
