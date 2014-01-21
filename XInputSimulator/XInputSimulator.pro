TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

TARGET = XInputSimulatorMain

SOURCES += main.cpp \
    xinputsimulatorimpl.cpp \
    xinputsimulator.cpp \
    xinputsimulatorimpllinux.cpp \
    notimplementedexception.cpp \
    xinputsimulatorimplmacos.cpp \
    xinputsimulatorimplwin.cpp

HEADERS += \
    xinputsimulator.h \
    xinputsimulatorimpl.h \
    xinputsimulatorimpllinux.h \
    notimplementedexception.h \
    xinputsimulatorimplmacos.h \
    xinputsimulatorimplwin.h

macx {
# mac only
    LIBS += -framework ApplicationServices
}
unix:!macx{
# linux only
    LIBS += -lX11 -lXtst
}
win32 {
# windows only
    LIBS += "C:\Program Files\Microsoft SDKs\Windows\v7.1\Lib\User32.Lib"
}
