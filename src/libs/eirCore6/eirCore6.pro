# {Eclipse6}/root/src/libs/eirBase6/eirCore6.pri
message(/root/src/libs/eirBase6/eirCore6.pri)

QT -= gui
TEMPLATE = lib
TARGET = eirCore
CONFIG += c++17
DEFINES += EIRCORE6_LIBRARY
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../../version.pri)
include(../../DESTDIR.pri)
message(DESTDIR = $$DESTDIR)
message(TARGET = $$TARGET)

SOURCES += \
    eirCore6.cpp

HEADERS += \
    eirCore6_global.h \
    eirCore6.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
