#include "setwpdlg.h"
#include "ui_setwpdlg.h"
#include <QMessageBox>
#include <qwt_dial_needle.h>

SetWPDlg::SetWPDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetWPDlg)
{
    ui->setupUi(this);
    //set dail style
    setdialstyle(ui->dial);
}

/**
  distruct...
*/
SetWPDlg::~SetWPDlg()
{
    delete ui;
}

/**

*/
void SetWPDlg::on_pb_test_clicked() {
    QMessageBox::warning(this, "fdsafdas", "fdsafdsa", QMessageBox::Yes);
}

void SetWPDlg::on_knob_sliderMoved(double value) {
#if 0
    QwtKnob *p = ui->knob;
    QwtTextLabel *l = ui->TextLabel;
    if(p != NULL && l != NULL) {
        QwtText txt;
        txt = QString::number(value);
        l->setText(txt);
        p->setValue(value);
    } else {
        QMessageBox::warning(this, "fsadsa", "fdsfsda", QMessageBox::Yes);
    }
#endif
}

/**
 * set the dial style
*/
void SetWPDlg::setdialstyle(QwtDial *p) {
    p->setTracking(true);
    p->setScaleArc(0, 360);
    p->setScale(-145, 105);
    p->setTotalSteps(200);
    p->setWrapping(false);
    p->setOrigin(100);
    QwtDialSimpleNeedle * nd = new QwtDialSimpleNeedle(QwtDialSimpleNeedle::Arrow);
    p->setScaleMaxMajor(14);
    p->setNeedle(nd);
}


