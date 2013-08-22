#include "dlgrfmdebug.h"
#include "ui_dlgrfmdebug.h"

DlgRFMDebug::DlgRFMDebug(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgRFMDebug)
{
    ui->setupUi(this);
}

DlgRFMDebug::~DlgRFMDebug()
{
    delete ui;
}
