/********************************************************************************
** Form generated from reading UI file 'cmdsimmw.ui'
**
** Created: Sun Apr 7 18:28:23 2013
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
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMDSimMW
{
public:
    QAction *actionSetBrd;
    QWidget *centralWidget;
    QGroupBox *gBox_sig_sel;
    QSplitter *splitter;
    QLabel *lbl_new_ch;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *edit_line;
    QDialogButtonBox *bbx_sig_sel;
    QListView *listw_sig_sel;
    QWidget *layoutWidget1;
    QFormLayout *formLayout;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CMDSimMW)
    {
        if (CMDSimMW->objectName().isEmpty())
            CMDSimMW->setObjectName(QString::fromUtf8("CMDSimMW"));
        CMDSimMW->resize(748, 542);
        actionSetBrd = new QAction(CMDSimMW);
        actionSetBrd->setObjectName(QString::fromUtf8("actionSetBrd"));
        centralWidget = new QWidget(CMDSimMW);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gBox_sig_sel = new QGroupBox(centralWidget);
        gBox_sig_sel->setObjectName(QString::fromUtf8("gBox_sig_sel"));
        gBox_sig_sel->setGeometry(QRect(20, 10, 201, 461));
        splitter = new QSplitter(gBox_sig_sel);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 380, 41, 16));
        splitter->setOrientation(Qt::Vertical);
        lbl_new_ch = new QLabel(splitter);
        lbl_new_ch->setObjectName(QString::fromUtf8("lbl_new_ch"));
        splitter->addWidget(lbl_new_ch);
        layoutWidget = new QWidget(gBox_sig_sel);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 400, 158, 51));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        edit_line = new QLineEdit(layoutWidget);
        edit_line->setObjectName(QString::fromUtf8("edit_line"));
        edit_line->setEnabled(true);
        edit_line->setMinimumSize(QSize(133, 17));

        verticalLayout->addWidget(edit_line);

        bbx_sig_sel = new QDialogButtonBox(layoutWidget);
        bbx_sig_sel->setObjectName(QString::fromUtf8("bbx_sig_sel"));
        bbx_sig_sel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(bbx_sig_sel);

        listw_sig_sel = new QListView(centralWidget);
        listw_sig_sel->setObjectName(QString::fromUtf8("listw_sig_sel"));
        listw_sig_sel->setGeometry(QRect(30, 30, 181, 341));
        listw_sig_sel->setViewMode(QListView::ListMode);
        layoutWidget1 = new QWidget(centralWidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 2, 2));
        formLayout = new QFormLayout(layoutWidget1);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        CMDSimMW->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CMDSimMW);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 748, 17));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        CMDSimMW->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CMDSimMW);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CMDSimMW->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CMDSimMW);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CMDSimMW->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionSetBrd);

        retranslateUi(CMDSimMW);

        QMetaObject::connectSlotsByName(CMDSimMW);
    } // setupUi

    void retranslateUi(QMainWindow *CMDSimMW)
    {
        CMDSimMW->setWindowTitle(QApplication::translate("CMDSimMW", "CMDSimMW", 0, QApplication::UnicodeUTF8));
        actionSetBrd->setText(QApplication::translate("CMDSimMW", "\346\235\277\345\215\241\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
        gBox_sig_sel->setTitle(QApplication::translate("CMDSimMW", "\346\214\207\344\273\244\344\277\241\345\217\267\351\200\211\346\213\251", 0, QApplication::UnicodeUTF8));
        lbl_new_ch->setText(QApplication::translate("CMDSimMW", "\346\226\260\351\200\232\351\201\223\357\274\232", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("CMDSimMW", "\350\256\276\347\275\256", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CMDSimMW: public Ui_CMDSimMW {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMDSIMMW_H
