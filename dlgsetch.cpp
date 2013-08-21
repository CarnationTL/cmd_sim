#include "dlgsetch.h"
#include "ui_dlgsetch.h"

DlgSetCh::DlgSetCh(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgSetCh)
{
    ui->setupUi(this);
    info = ui->lbinfo;

#if 1
    QStringList chs;
    QStringList naem;
    chs << "ch1" << "ch2";
    naem << "ch1 info" << "ch2 info";
    QString labst = genChInfo(chs, naem);
    info->setText(labst);
#endif

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

void DlgSetCh::on_sbEndTime_valueChanged(double arg1) {

}

void DlgSetCh::on_sbEndY_valueChanged(double arg1) {

}

void DlgSetCh::on_btnConfirmSeg_clicked() {

}

void DlgSetCh::on_lswcurv_clicked(const QModelIndex &index) {

}

void DlgSetCh::on_btncurDel_clicked() {

}

void DlgSetCh::on_ckbloop_clicked() {

}

void DlgSetCh::initTblchInfo() {
    if(table != NULL) {
//        table->VerticalHeader()->
    }
}


//ch info
QString DlgSetCh::genChInfo(QStringList chlst, QStringList namelist) {
    QString retstr;
    if(chlst.length() > 0 && namelist.length() > 0) {
        int chlen = chlst.length();
        int nlen = namelist.length();
        retstr = QString("CHs: ");
        for(int i = 0; i < chlen; i++) {
            retstr += chlst.at(i) + QString(" | ");
        }
        retstr += QString("\n");
        retstr += QString("CH_INFO: ");
        for(int j = 0; j < nlen; j++) {
            retstr += namelist.at(j) + QString(" | ");
        }
        retstr += QString("\n");
    }
    return retstr;
}
