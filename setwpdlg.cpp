#include "setwpdlg.h"
#include "ui_setwpdlg.h"
#include <QMessageBox>
SetWPDlg::SetWPDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetWPDlg)
{
    ui->setupUi(this);
}

/**

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
