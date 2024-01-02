# {Eclipse6}/root/src/libs/eirBase6/eirCore6.pri
message(/root/src/libs/eirBase6/eirCore6.pri)

QT *= core
QT *= gui
TEMPLATE = lib
TARGET = eirCore
CONFIG += c++17
DEFINES += EIRCORE6_LIBRARY
DEFINES += QT_MESSAGELOGCONTEXT
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include(../../version.pri)
include(../../DESTDIR.pri)
include(../libs.pri)
include(../../useBase.pri)
# include(../../useExe.pri)
message(DESTDIR = $$DESTDIR)
message(TARGET = $$TARGET)

SOURCES += \
    BaseMachine.cpp \
    FunctionInfo.cpp \
    Key.cpp \
    KeySeg.cpp \
    KeySegList.cpp \
    Message.cpp \
    Value.cpp \
    Variable.cpp \
    VariableList.cpp \
    VariableMap.cpp \
    eirCore6.cpp

HEADERS += \
    BaseMachine.h \
    FunctionInfo.h \
    Key.h \
    KeySeg.h \
    KeySegList.h \
    Message.h \
    MetaTypeSample.h \
    Return.h \
    SafeList.h \
    Value.h \
    Variable.h \
    VariableList.h \
    VariableMap.h \
    eirCore6_global.h \
    eirCore6.h

STATECHARTS += \
    BaseStateMachine.scxml

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target
