#-------------------------------------------------
#
# Project created by QtCreator 2013-03-28T10:55:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CMDSim
TEMPLATE = app

win32: QMAKE_CXXFLAGS += /Gd

CONFIG += qwt

DEFINES += QWT_DLL QT_DLL
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
    sigpara.cpp \
    cmdsimmw_init.cpp \
    oscilloscope/curvedata.cpp \
    oscilloscope/knob.cpp \
    oscilloscope/plot.cpp \
    oscilloscope/samplingthread.cpp \
    oscilloscope/signaldata.cpp \
    oscilloscope/wheelbox.cpp \
    oscilloscope/qwtoscmain.cpp \
    sigdata.cpp \
    dlgsetch.cpp \
    sigGen/sinusdata.cpp \
    sigGen/tridata.cpp \
    sigGen/squdata.cpp \
    sigGen/curvedatan.cpp \
    sigGen/sawdata.cpp \
    exttools.cpp \
    dlgrfmdebug.cpp

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
    sigpara.h \
    oscilloscope/curvedata.h \
    oscilloscope/knob.h \
    oscilloscope/plot.h \
    oscilloscope/samplingthread.h \
    oscilloscope/signaldata.h \
    oscilloscope/wheelbox.h \
    oscilloscope/qwtoscmain.h \
    sigdata.h \
    dlgsetch.h \
    sigGen/sinusdata.h \
    sigGen/tridata.h \
    sigGen/squdata.h \
    sigGen/curvedatan.h \
    sigGen/sawdata.h \
    exttools.h \
    dlgrfmdebug.h

FORMS    += cmdsimmw.ui \
    setbrddlg.ui \
    setwpdlg.ui \
    setlbrdparadlg.ui \
    dlgsetch.ui \
    exttools.ui \
    dlgrfmdebug.ui

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/qwtlib/ -lqwt
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/qwtlib/ -lqwtd

INCLUDEPATH += $$PWD/qwtinc
DEPENDPATH += $$PWD/qwtinc







#add qwt linux

unix:!macx: LIBS += -L$$PWD/../../../usr/local/qwt-6.1.0-rc3/lib/ -lqwt

unix:!macx: INCLUDEPATH += $$PWD/../../../usr/local/qwt-6.1.0-rc3/include
unix:!macx: DEPENDPATH += $$PWD/../../../usr/local/qwt-6.1.0-rc3/include


win32: LIBS += -L$$PWD/rfmlib/ -lrfm2gdll_stdc

win32: INCLUDEPATH += $$PWD/rfmlib
win32: DEPENDPATH += $$PWD/rfmlib

win32: PRE_TARGETDEPS += $$PWD/rfmlib/rfm2gdll_stdc.lib

#75C3 debug lib and release lib
win32:CONFIG(release, debug|release): LIBS += -L$$PWD/75C3Rlib/ -lCPCI75C3Dll
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/75C3Dlib/ -lCPCI75C3Dlld

win32: INCLUDEPATH += $$PWD/75C3inc
win32: DEPENDPATH += $$PWD/75C3inc

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

win32: INCLUDEPATH += $$PWD/75C3Rlib
win32: DEPENDPATH += $$PWD/75C3Rlib


#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Qwt-6.1.0/lib/ -lqwt
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Qwt-6.1.0/lib/ -lqwtd
#
#INCLUDEPATH += $$PWD/../../Qwt-6.1.0/include
#DEPENDPATH += $$PWD/../../Qwt-6.1.0/include
