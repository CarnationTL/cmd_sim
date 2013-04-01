
#define WIN32_LEAN_AND_MEAN
#include <QMessageBox>
#include "cmdsimmw.h"
#include "ui_cmdsimmw.h"
#include "rfm2gse.h"
#include "C75C3Expls.h"
#include "c75c3dllencap.h"
typedef int(* funca )(int);


CMDSimMW::CMDSimMW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMDSimMW) {

    ui->setupUi(this);
#if 0
	if (initrfm() != EXE_SUCCESS) {
		QMessageBox::warning(NULL, "lib_load", "lib_load", QMessageBox::Yes);
	}
#endif

#if 0
    init75c3();
#endif

#if 0
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
            QMessageBox::warning(this, "load", ",", QMessageBox::Yes);
        }
    }
    while(1) {

    }
#endif

#if 0
    C75C3DllEncap *ptr = C75C3DllEncap::getInst();
    if(ptr != NULL) {
		ptr->loadDll();
		FPTR_OPEN ptrOpen =  ptr->getopen();
		if (ptrOpen != NULL) {
			int ret = ptrOpen(0);
			if (ret != 0) {
				QMessageBox::warning(this, "funccall", "funcall", QMessageBox::Yes);
			}
		}
	}
#endif


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
    return 0;
}
