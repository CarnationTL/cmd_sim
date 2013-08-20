#include "dlgsetch.h"
#include "ui_dlgsetch.h"

DlgSetCh::DlgSetCh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgSetCh)
{
    ui->setupUi(this);
    //table = ui->tableWidget;
    initTblchInfo();
}

DlgSetCh::~DlgSetCh()
{
    delete ui;
}

void DlgSetCh::on_rbCus_clicked()
{

}

void DlgSetCh::on_rbTri_clicked()
{

}

void DlgSetCh::on_rbSaw_clicked()
{

}

void DlgSetCh::on_rbSquare_clicked()
{

}

void DlgSetCh::on_rbSin_clicked()
{

}

void DlgSetCh::on_sbAMP_valueChanged(double arg1)
{

}

void DlgSetCh::on_sbTIME_valueChanged(double arg1)
{

}

void DlgSetCh::on_sbDUTY_valueChanged(double arg1)
{

}

void DlgSetCh::on_sbstartTime_valueChanged(double arg1)
{

}

void DlgSetCh::on_sbStartY_valueChanged(double arg1)
{

}

void DlgSetCh::on_sbEndTime_valueChanged(double arg1)
{

}

void DlgSetCh::on_sbEndY_valueChanged(double arg1)
{

}

void DlgSetCh::on_btnConfirmSeg_clicked()
{

}

void DlgSetCh::on_lswcurv_clicked(const QModelIndex &index)
{

}

void DlgSetCh::on_btncurDel_clicked()
{

}

void DlgSetCh::on_ckbloop_clicked()
{

}

void DlgSetCh::initTblchInfo() {
    if(table != NULL) {
//        table->VerticalHeader()->
    }
}
