
#include <QMessageBox>
#include "cmdsimmw.h"
#include "ui_cmdsimmw.h"
#include "rfm2gse.h"


CMDSimMW::CMDSimMW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMDSimMW) {
#if 0
	if (initrfm() != EXE_SUCCESS) {
		QMessageBox::warning(NULL, "lib_load", "lib_load", QMessageBox::Yes);
	}
#endif

    ui->setupUi(this);
}

CMDSimMW::~CMDSimMW()
{
    delete ui;
}

int CMDSimMW::initrfm() {
    RFM2gSE se;
	return se.open();
}
