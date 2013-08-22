#include "dlglchset.h"
#include "ui_dlglchset.h"

DlgLchSet::DlgLchSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgLchSet)
{
    ui->setupUi(this);
    initpointers();
    plotInit();
    cycleandloop();
}

DlgLchSet::~DlgLchSet()
{
    delete ui;
}

//ch info
QString DlgLchSet::genChInfo(QStringList chlst, QStringList namelist) {
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

void DlgLchSet::plotInit() {
    plot->setAutoDelete (true);
    plot->setAxisScale(QwtPlot::xBottom, 0, 10.0);
    plot->setAxisScale(QwtPlot::yLeft, -10.0, 10.0);
    grid = new QwtPlotGrid();
    grid->enableXMin (true);
    grid->setMajorPen( Qt::white, 0, Qt::DotLine );
    grid->setMinorPen( Qt::gray, 0 , Qt::DotLine );
    if(plot != NULL) {
            grid->attach (plot);
    }

    plot->setCanvasBackground (QColor(0, 49, 114));
}

void DlgLchSet::initpointers() {
    plot = ui->plotWhole;
}

void DlgLchSet::cycleandloop() {

    ui->rbclyle_Saw->setChecked(true);
    ui->rbclyle_Sine->setChecked(true);
    ui->rbclyle_Squ->setChecked(true);
    ui->rbclyle_Tri->setChecked(true);

    ui->spcycle_Sine->setValue(1);
    ui->spcycle_Tri->setValue(1);
    ui->spcycle_Saw->setValue(1);
    ui->spcycle_Squ->setValue(1);
}

void DlgLchSet::on_sbAMP_Sine_valueChanged(double arg1) {

}

void DlgLchSet::on_sbTIME_Sine_valueChanged(double arg1)
{

}

void DlgLchSet::on_sbAMP_Tri_valueChanged(double arg1)
{

}


void DlgLchSet::on_sbTIME_Tri_valueChanged(double arg1)
{

}

void DlgLchSet::on_rbloo_Sine_clicked() {
    if(ui->rbloo_Sine->isChecked() == true) {
        ui->spcycle_Sine->setDisabled(true);
    }
}

void DlgLchSet::on_rbclyle_Sine_clicked() {
    if(ui->rbclyle_Sine->isChecked() == true)
        ui->spcycle_Sine->setDisabled(false);
}

void DlgLchSet::on_spcycle_Sine_valueChanged(int arg1)
{

}

void DlgLchSet::on_rbloo_Tri_clicked() {
    if(ui->rbloo_Tri->isChecked() == true) {
        ui->spcycle_Tri->setDisabled(true);
    }
}

void DlgLchSet::on_rbclyle_Tri_clicked() {
    if(ui->rbclyle_Tri->isChecked() == true)
        ui->spcycle_Tri->setDisabled(false);
}

void DlgLchSet::on_spcycle_Tri_valueChanged(int arg1)
{

}

void DlgLchSet::on_sbAMP_Saw_valueChanged(double arg1)
{

}

void DlgLchSet::on_sbTIME_Saw_valueChanged(double arg1)
{

}

void DlgLchSet::on_rbloo_Saw_clicked() {
    if(ui->rbloo_Saw->isChecked() == true)
        ui->spcycle_Saw->setDisabled(true);
}

void DlgLchSet::on_rbclyle_Saw_clicked() {
    if(ui->rbclyle_Saw->isChecked() == true)
        ui->spcycle_Saw->setDisabled(false);
}

void DlgLchSet::on_spcycle_Saw_valueChanged(int arg1) {

}

void DlgLchSet::on_sbAMP_Squ_valueChanged(double arg1)
{

}

void DlgLchSet::on_sbTIME_Squ_valueChanged(double arg1)
{

}

void DlgLchSet::on_sbDUTY_Squ_valueChanged(double arg1)
{

}

void DlgLchSet::on_rbloo_Squ_clicked() {
    if(ui->rbloo_Squ->isChecked() == true)
        ui->spcycle_Squ->setDisabled(true);
}

void DlgLchSet::on_rbclyle_Squ_clicked() {
    if(ui->rbclyle_Squ->isChecked() == true)
        ui->spcycle_Squ->setDisabled(false);
}

void DlgLchSet::on_spcycle_Squ_valueChanged(int arg1)
{

}

void DlgLchSet::on_sbstartTime_valueChanged(double arg1)
{

}

void DlgLchSet::on_sbEndTime_valueChanged(double arg1)
{

}

void DlgLchSet::on_sbStartY_valueChanged(double arg1)
{

}

void DlgLchSet::on_sbEndY_valueChanged(double arg1)
{

}

void DlgLchSet::on_btnConfirmSeg_clicked()
{

}

void DlgLchSet::on_lswcurv_clicked(const QModelIndex &index) {

}

void DlgLchSet::on_cbloop_Cur_clicked() {
   if (ui->cbloop_Cur->isChecked() == true) {

   } else {

   }
}

void DlgLchSet::on_btncurDel_clicked() {

}
