#include "setbrddlg.h"
#include "ui_setbrddlg.h"
#include <QPalette>
#include <Qwt/qwt_scale_engine.h>

SetBrdDlg::SetBrdDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetBrdDlg)
{
    ui->setupUi(this);
    //this->setLayout(ui->setbdGlay);
    mapsignals();
    initctls();
}

/**
  init board styles..
*/
void SetBrdDlg::initBrdDlgCtls() {

}

SetBrdDlg::~SetBrdDlg()
{
    delete ui;
}

void SetBrdDlg::on_buttonBox_accepted() {

}

void SetBrdDlg::on_buttonBox_rejected() {
    this->close();
}

void SetBrdDlg::on_kb1v_valueChanged(double value) {
    emit v1change(value);
}

void SetBrdDlg::on_kb1f_valueChanged(double value)
{

}

void SetBrdDlg::on_kb2v_valueChanged(double value)
{

}

void SetBrdDlg::on_kb2f_valueChanged(double value)
{

}

void SetBrdDlg::on_kb3v_valueChanged(double value)
{

}

void SetBrdDlg::on_kb3f_valueChanged(double value)
{

}

void SetBrdDlg::on_kb4v_valueChanged(double value)
{

}

void SetBrdDlg::on_kb4f_valueChanged(double value)
{

}

void SetBrdDlg::on_sp1v_valueChanged(double arg1)
{

}

void SetBrdDlg::on_sp1f_valueChanged(double arg1)
{

}

void SetBrdDlg::on_sp2v_valueChanged(double arg1)
{

}

void SetBrdDlg::on_sp2f_valueChanged(double arg1)
{

}

void SetBrdDlg::on_sp3v_valueChanged(double arg1)
{

}

void SetBrdDlg::on_sp3f_valueChanged(double arg1)
{

}

void SetBrdDlg::on_sp4v_valueChanged(double arg1)
{

}

void SetBrdDlg::on_sp4f_valueChanged(double arg1)
{

}

void SetBrdDlg::mapsignals() {

    connect(ui->sp1v, SIGNAL(valueChanged(double)), ui->kb1v, SLOT(setValue(double)));
    connect(ui->kb1v, SIGNAL(valueChanged(double)), ui->sp1v, SLOT(setValue(double)));

    connect(ui->kb1v, SIGNAL(valueChanged(double)), ui->lcd1v, SLOT(display(double)));
    connect(ui->sp1v, SIGNAL(valueChanged(double)), ui->lcd1v, SLOT(display(double)));
    connect(ui->kb1f, SIGNAL(valueChanged(double)), ui->lcd1f, SLOT(display(double)));
    connect(ui->sp1f, SIGNAL(valueChanged(double)), ui->lcd1f, SLOT(display(double)));

    connect(ui->sp2v, SIGNAL(valueChanged(double)), ui->kb2v, SLOT(setValue(double)));
    connect(ui->kb2v, SIGNAL(valueChanged(double)), ui->sp2v, SLOT(setValue(double)));

    connect(ui->kb2v, SIGNAL(valueChanged(double)), ui->lcd2v, SLOT(display(double)));
    connect(ui->sp2v, SIGNAL(valueChanged(double)), ui->lcd2v, SLOT(display(double)));
    connect(ui->kb2f, SIGNAL(valueChanged(double)), ui->lcd2f, SLOT(display(double)));
    connect(ui->sp2f, SIGNAL(valueChanged(double)), ui->lcd2f, SLOT(display(double)));

    connect(ui->sp3v, SIGNAL(valueChanged(double)), ui->kb3v, SLOT(setValue(double)));
    connect(ui->kb3v, SIGNAL(valueChanged(double)), ui->sp3v, SLOT(setValue(double)));

    connect(ui->kb3v, SIGNAL(valueChanged(double)), ui->lcd3v, SLOT(display(double)));
    connect(ui->sp3v, SIGNAL(valueChanged(double)), ui->lcd3v, SLOT(display(double)));
    connect(ui->kb3f, SIGNAL(valueChanged(double)), ui->lcd3f, SLOT(display(double)));
    connect(ui->sp3f, SIGNAL(valueChanged(double)), ui->lcd3f, SLOT(display(double)));

    connect(ui->sp4v, SIGNAL(valueChanged(double)), ui->kb4v, SLOT(setValue(double)));
    connect(ui->kb4v, SIGNAL(valueChanged(double)), ui->sp4v, SLOT(setValue(double)));

    connect(ui->kb4v, SIGNAL(valueChanged(double)), ui->lcd4v, SLOT(display(double)));
    connect(ui->sp4v, SIGNAL(valueChanged(double)), ui->lcd4v, SLOT(display(double)));
    connect(ui->kb4f, SIGNAL(valueChanged(double)), ui->lcd4f, SLOT(display(double)));
    connect(ui->sp4f, SIGNAL(valueChanged(double)), ui->lcd4f, SLOT(display(double)));

}

void SetBrdDlg::initctls() {

    ui->kb1f->setScale(360, 1800);
    ui->kb1f->setKnobStyle(QwtKnob::Flat);
    ui->kb1f->setMarkerStyle(QwtKnob::Notch);
    ui->kb1f->setScaleEngine(new QwtLogScaleEngine());
    ui->kb1f->setScaleStepSize(1.0);
    ui->kb1f->setScaleMaxMinor(10);

//    ui->kb2f->setScale(360, 1800);
//    ui->kb2f->setKnobStyle(QwtKnob::Flat);
//    ui->kb2f->setMarkerStyle(QwtKnob::Notch);
//    ui->kb2f->setScaleEngine(new QwtLogScaleEngine());
//    ui->kb2f->setScaleStepSize(1.0);
//    ui->kb2f->setScaleMaxMinor(10);
//
//    ui->kb3f->setScale(360, 1800);
//    ui->kb3f->setKnobStyle(QwtKnob::Flat);
//    ui->kb3f->setMarkerStyle(QwtKnob::Notch);
//    ui->kb3f->setScaleEngine(new QwtLogScaleEngine());
//    ui->kb3f->setScaleStepSize(1.0);
//    ui->kb3f->setScaleMaxMinor(10);
//
//    ui->kb4f->setScale(360, 1800);
//    ui->kb4f->setKnobStyle(QwtKnob::Flat);
//    ui->kb4f->setMarkerStyle(QwtKnob::Notch);
//    ui->kb4f->setScaleEngine(new QwtLogScaleEngine());
//    ui->kb4f->setScaleStepSize(1.0);
//    ui->kb4f->setScaleMaxMinor(10);

}

