# {Eclipse6}/root/src/libs/eirBase6/eirBase6.pri
message(/root/src/libs/eirBase6/eirBase6.pri)

QT -= gui
TEMPLATE = lib
TARGET = eirBase
CONFIG += c++17
DEFINES += EIRBASE6_LIBRARY
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../../version.pri)
include(../../DESTDIR.pri)
include(../libs.pri)
message(DESTDIR = $$DESTDIR)
message(TARGET = $$TARGET)

SOURCES += \
    MillisecondTime.cpp \
    VersionInfo.cpp \
    eirBase6.cpp \
    Uid.cpp

HEADERS += \
    MillisecondTime.h \
    Property.h \
    Types.h \
    VersionInfo.h \
    eirBase6_global.h \
    eirBase6.h \
    Uid.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
