#-------------------------------------------------
#
# Project created by QtCreator 2013-03-28T10:55:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CMDSim
TEMPLATE = app


CONFIG += qwt

SOURCES += main.cpp\
        cmdsimmw.cpp

HEADERS  += cmdsimmw.h

FORMS    += cmdsimmw.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/C:/Qwt-6.1.0-rc3/lib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/C:/Qwt-6.1.0-rc3/lib/ -lqwtd

INCLUDEPATH += $$PWD/C:/Qwt-6.1.0-rc3/include
DEPENDPATH += $$PWD/C:/Qwt-6.1.0-rc3/include
