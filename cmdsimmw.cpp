#include "cmdsimmw.h"
#include "ui_cmdsimmw.h"

CMDSimMW::CMDSimMW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMDSimMW)
{
    ui->setupUi(this);
}

CMDSimMW::~CMDSimMW()
{
    delete ui;
}
