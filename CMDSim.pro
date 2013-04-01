#-------------------------------------------------
#
# Project created by QtCreator 2013-03-28T10:55:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CMDSim
TEMPLATE = app

QMAKE_CXXFLAGS += /Gd

CONFIG += qwt

SOURCES += main.cpp\
        cmdsimmw.cpp \
    rfm2gse.cpp \
    commonch.cpp \
    c75c3dllencap.cpp \
    lvdtch.cpp \
    commbrd.cpp

HEADERS  += cmdsimmw.h \
    rfm2gse.h \
    cmddefs.h \
    C75C3Expls.h \
    c75c3funcp.h \
    commonch.h \
    c75c3dllencap.h \
    lvdtch.h \
    commbrd.h

FORMS    += cmdsimmw.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/qwtlib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/qwtlib/ -lqwtd

INCLUDEPATH += $$PWD/qwtinc
DEPENDPATH += $$PWD/qwtinc


win32: LIBS += -L$$PWD/rfmlib/ -lrfm2gdll_stdc

INCLUDEPATH += $$PWD/rfmlib
DEPENDPATH += $$PWD/rfmlib

win32: PRE_TARGETDEPS += $$PWD/rfmlib/rfm2gdll_stdc.lib

#75C3 debug lib and release lib
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/75C3Rlib/ -lCPCI75C3Dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/75C3Dlib/ -lCPCI75C3Dlld

INCLUDEPATH += $$PWD/75C3inc
DEPENDPATH += $$PWD/75C3inc

OTHER_FILES += \
    notes.txt
