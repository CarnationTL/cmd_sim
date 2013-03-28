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
        cmdsimmw.cpp \
    rfm2gse.cpp

HEADERS  += cmdsimmw.h \
    rfm2gse.h \
    cmddefs.h

FORMS    += cmdsimmw.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/qwtlib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/qwtlib/ -lqwtd

INCLUDEPATH += $$PWD/qwtinc
DEPENDPATH += $$PWD/qwtinc


win32: LIBS += -L$$PWD/rfmlib/ -lrfm2gdll_stdc

INCLUDEPATH += $$PWD/rfmlib
DEPENDPATH += $$PWD/rfmlib

win32: PRE_TARGETDEPS += $$PWD/rfmlib/rfm2gdll_stdc.lib
