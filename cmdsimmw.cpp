
#define WIN32_LEAN_AND_MEAN
#include <QMessageBox>
#include "cmdsimmw.h"
#include "ui_cmdsimmw.h"
#include "rfm2gse.h"
#include "c75c3encap.h"
#include "C75C3Expls.h"

typedef int(* funca )(int);


CMDSimMW::CMDSimMW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMDSimMW) {
#if 0
	if (initrfm() != EXE_SUCCESS) {
		QMessageBox::warning(NULL, "lib_load", "lib_load", QMessageBox::Yes);
	}
#endif

#if 0
    init75c3();
#endif

#if 1
    C75C3Encap enp;
    enp.pclib = new QLibrary("CPCI75C3Dll");
    enp.pclib->load();
    if(enp.pclib->isLoaded()) {
        QMessageBox::warning(this, "a", "b", QMessageBox::Yes);
    }
    funca pfunc = (funca)enp.pclib->resolve(FSTR_Open);
    if(pfunc) {
        int ret = pfunc(0);
        if(ret != CPCI75C3_SUCCESS) {
            QMessageBox::warning(this, "a", ",", QMessageBox::Yes);
        }
    }
    while(1) {

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

int CMDSimMW::init75c3() {
    C75C3Encap bd;
    return bd.OpenTest();
}
