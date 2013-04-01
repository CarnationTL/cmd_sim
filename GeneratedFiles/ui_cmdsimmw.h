/********************************************************************************
** Form generated from reading UI file 'cmdsimmw.ui'
**
** Created: Mon Apr 1 15:32:05 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMDSIMMW_H
#define UI_CMDSIMMW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMDSimMW
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CMDSimMW)
    {
        if (CMDSimMW->objectName().isEmpty())
            CMDSimMW->setObjectName(QString::fromUtf8("CMDSimMW"));
        CMDSimMW->resize(400, 300);
        menuBar = new QMenuBar(CMDSimMW);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        CMDSimMW->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CMDSimMW);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CMDSimMW->addToolBar(mainToolBar);
        centralWidget = new QWidget(CMDSimMW);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        CMDSimMW->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CMDSimMW);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CMDSimMW->setStatusBar(statusBar);

        retranslateUi(CMDSimMW);

        QMetaObject::connectSlotsByName(CMDSimMW);
    } // setupUi

    void retranslateUi(QMainWindow *CMDSimMW)
    {
        CMDSimMW->setWindowTitle(QApplication::translate("CMDSimMW", "CMDSimMW", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CMDSimMW: public Ui_CMDSimMW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMDSIMMW_H
