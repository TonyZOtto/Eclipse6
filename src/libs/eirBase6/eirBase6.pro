# {Eclipse6}/root/src/console/If6Console/If6Console.pri
message(/root/src/console/If6Console/If6Console.pri)

QT -= gui
TEMPLATE = lib
TARGET = eirBase
CONFIG += c++17
DEFINES += EIRBASE6_LIBRARY

include(../../version.pri)
include(../../DESTDIR.pri)
message(DESTDIR = $$DESTDIR)
message(TARGET = $$TARGET)

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    VersionInfo.cpp \
    eirBase6.cpp

HEADERS += \
    Property.h \
    Types.h \
    VersionInfo.h \
    eirBase6_global.h \
    eirBase6.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
