#include "setwpdlg.h"
#include "ui_setwpdlg.h"

SetWPDlg::SetWPDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetWPDlg)
{
    ui->setupUi(this);
}

SetWPDlg::~SetWPDlg()
{
    delete ui;
}
