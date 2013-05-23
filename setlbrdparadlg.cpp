#include "setlbrdparadlg.h"
#include "ui_setlbrdparadlg.h"

setLbrdParaDlg::setLbrdParaDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setLbrdParaDlg)
{
    ui->setupUi(this);
}


setLbrdParaDlg::~setLbrdParaDlg()
{
    delete ui;
}
