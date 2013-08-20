#include "setbrddlg.h"
#include "ui_setbrddlg.h"

SetBrdDlg::SetBrdDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetBrdDlg)
{
    ui->setupUi(this);
    //this->setLayout(ui->setbdGlay);
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
