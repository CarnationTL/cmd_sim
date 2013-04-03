#include "setbrddlg.h"
#include "ui_setbrddlg.h"

SetBrdDlg::SetBrdDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetBrdDlg)
{
    ui->setupUi(this);
    this->setLayout(ui->setbdGlay);
}

SetBrdDlg::~SetBrdDlg()
{
    delete ui;
}
