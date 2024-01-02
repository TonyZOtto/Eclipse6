# {Eclipse6}/root/src/libs/eirBase6/eirBase6.pri
message(/root/src/libs/eirBase6/eirBase6.pri)

QT *= core gui
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
    AText.cpp \
    BaseError.cpp \
    Boolean.cpp \
    EpochTime.cpp \
    NanosecondsElapsed.cpp \
    ObjectHelper.cpp \
    Success.cpp \
    URL.cpp \
    VersionInfo.cpp \
    eirBase6.cpp \
    Uid.cpp

HEADERS += \
    AText.h \
    BaseError.h \
    Boolean.h \
    DualMap.h \
    EpochTime.h \
    NanosecondsElapsed.h \
    ObjectHelper.h \
    Property.h \
    Success.h \
    Types.h \
    URL.h \
    UidMap.h \
    VersionInfo.h \
    eirBase6_global.h \
    eirBase6.h \
    Uid.h

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
