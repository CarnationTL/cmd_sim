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
    commbrd.cpp \
    apdapter.cpp \
    setbrddlg.cpp \
    setwpdlg.cpp \
    brd75c3.cpp \
    setlbrdparadlg.cpp \
    siggen.cpp \
    sigpara.cpp

HEADERS  += cmdsimmw.h \
    rfm2gse.h \
    cmddefs.h \
    C75C3Expls.h \
    c75c3funcp.h \
    commonch.h \
    c75c3dllencap.h \
    lvdtch.h \
    commbrd.h \
    apdapter.h \
    setbrddlg.h \
    setwpdlg.h \
    brd75c3.h \
    setlbrdparadlg.h \
    siggen.h \
    sigpara.h

FORMS    += cmdsimmw.ui \
    setbrddlg.ui \
    setwpdlg.ui \
    setlbrdparadlg.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/qwtlib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/qwtlib/ -lqwtd

INCLUDEPATH += $$PWD/qwtinc
DEPENDPATH += $$PWD/qwtinc

#add qwt linux

unix:!macx: LIBS += -L$$PWD/../../../usr/local/qwt-6.1.0-rc3/lib/ -lqwt

INCLUDEPATH += $$PWD/../../../usr/local/qwt-6.1.0-rc3/include
DEPENDPATH += $$PWD/../../../usr/local/qwt-6.1.0-rc3/include


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
    notes.txt \
    image/taskbar.ico \
    image/password.ico \
    image/package_settings.ico \
    image/package_development.ico \
    image/looknfeel.ico \
    image/linuxconf.ico \
    image/konsole.ico \
    image/kmenuedit.ico \
    image/kcmprocessor.ico \
    image/kcmmemory.ico \
    image/hwinfo.ico \
    image/edu_mathematics.ico \
    image/terminal.ico

RESOURCES += \
    qres.qrc



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/75C3Rlib/ -lCPCI75C3Dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/75C3Dlib/ -lCPCI75C3Dlld

INCLUDEPATH += $$PWD/75C3Rlib
DEPENDPATH += $$PWD/75C3Rlib
