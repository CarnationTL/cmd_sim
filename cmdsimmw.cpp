#define WIN32_LEAN_AND_MEAN
#include <QMessageBox>
#include "cmdsimmw.h"
#include "ui_cmdsimmw.h"
#include "rfm2gse.h"
#include "C75C3Expls.h"
#include "c75c3dllencap.h"
#include "lvdtch.h"
#include <QStringList>
#include <QTextCodec>
#include <QDialog>
#include <QLayout>
#include "setbrddlg.h"
#include "setwpdlg.h"
#include <QCompleter>
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

    //in lvdt ch...class this is a test..
#if 0
    C75C3DllEncap *ptr = C75C3DllEncap::getInst();
    if(ptr != NULL) {
        if(ptr->isloaded() == false) {
            ptr->loadDll(); //in lvdtch construct...function..
        }

        if(ptr->isloaded()) {
            FPTR_OPEN ptrOpen =  ptr->getOpen();
            FPTR_OPEN ptrOpenMarco = ptr->getOpenMacro();
            if(ptrOpen == ptrOpenMarco) {
                QMessageBox::warning(this, "marco right", "marco rigth", QMessageBox::Yes);
            }
            if (ptrOpen != NULL) {
                int ret = ptrOpen(0);
                if (ret != 0) {
                    QMessageBox::warning(this, "funccall", "funcall", QMessageBox::Yes);
                }
            }
        }
    }
#endif

//    LVDTCh *ptrLch = new LVDTCh(1, "lvdt_ch1");
    initInsView();
    initSeachLE();
}

CMDSimMW::~CMDSimMW()
{
    delete ui;
}

int CMDSimMW::initInstructs() {
    QStringList *prefix = new QStringList();
    prefix->append(cvcp936("左驾驶盘位移信号"));
    prefix->append(cvcp936("右驾驶盘位移信号"));
    prefix->append(cvcp936("左驾驶柱位移信号"));
    prefix->append(cvcp936("右驾驶柱位移信号"));
    prefix->append(cvcp936("左脚蹬位移信号"));
    prefix->append(cvcp936("右脚蹬位移信号"));
    prefix->append(cvcp936("减速杆位置信号"));
    prefix->append(cvcp936("减速杆位置信号"));

    prefix->append(cvcp936("襟缝翼收放手柄位置信号"));
    prefix->append(cvcp936("起落架收放手柄位置信号"));

    prefix->append(cvcp936("左前轮位移信号"));
    prefix->append(cvcp936("左前轮位移信号"));

    prefix->append(cvcp936("左刹车位移信号"));
    prefix->append(cvcp936("左刹车位移信号"));

    QStringList *end = new QStringList();
    end->append("A");
    end->append("B");
    end->append("C");
    end->append("D");


    ps_ins_v = new QStringList();
    QString tempStr;

    if(prefix == NULL || end == NULL)
        return NULL;

    for(int i = 0; i < prefix->size(); i++) {
        for(int j = 0; j < end->size(); j++)  {
            tempStr.clear();
            tempStr.prepend(prefix->at(i));
            tempStr.append(end->at(j));
            ps_ins_v->append(tempStr);
        }
    }
    return ps_ins_v->size();
    delete prefix;
    delete end;
    prefix = NULL;
    end = NULL;
}

int CMDSimMW::initrfm() {
    RFM2gSE se;
    return se.open();
}

int CMDSimMW::init75c3() {
    return 0;
}
/**
  convert cp936 to unicode
*/
QString CMDSimMW::cvcp936(const char str[]) {
    if((sizeof(str) /sizeof(char)) <= 0)
        return QString("");
    QTextCodec *codec = QTextCodec::codecForName("cp936");
    if(codec != NULL) {
        QString ret = codec->toUnicode(str);
        return ret;
    }
    return QString("");
}

/**
  band the model to view
*/
void CMDSimMW::initInsView() {
    //Cmd_D_Model dv_model;
    QListView *pv = ui->listw_sig_sel;
    int cnt = initInstructs();
    dv_model = new QStandardItemModel(cnt, 0);
    if(pv != NULL && cnt > 0) {
        //// Cmd_DM_Item *newItem;
        QStandardItem *newItem;
        for(int i = 0; i < cnt; i++) {
            newItem = new QStandardItem(ps_ins_v->at(i));
            newItem->setCheckable(true);
            newItem->setCheckState(Qt::Unchecked);
            dv_model->setItem(i, newItem);
        }
    }
    pv->setModel(dv_model);
}

/**
  init the search edit...
*/
void CMDSimMW::initSeachLE() {
    _pSeachEdit = ui->edit_search;
    if(_pSeachEdit != NULL && dv_model != NULL) {
        _pCompleter = new QCompleter(this);
        _pCompleter->setModel(dv_model);
        _pSeachEdit->setCompleter(_pCompleter);
    }
}

/**
  set the layout of setBrdDlg (will move to new ui file)
*/
#if 0
int CMDSimMW::initSetBrdDlg(QDialog *pdlg) {
    if(pdlg != NULL) {
        //set parent.. prevent mem leak.
        _pMainLay = new QGridLayout(pdlg);
        _pMainLay->setContentsMargins(30, 11, 30, 11);

        for(int i = 0; i < LVDTBrds; i++) {
            QString tmpStr(cvcp936("LVDT板卡"));
            tmpStr.append(QString::number(i).toUtf8());
            tmpStr.append(": ");
            _plblLVDT[i] = new QLabel(tmpStr, pdlg);
            _pleLVDT[i] = new QLineEdit(pdlg);
       }
        _pMainLay->setSpacing(20);
        pdlg->setLayout(_pMainLay);
        return EXE_SUCCESS;
    }
    return EXE_FAIL;
}
#endif

/**
  add action set brd
*/
void CMDSimMW::on_actionSetBrd_triggered() {

#if 1
    _pdlg = new SetBrdDlg(this);

    if(_pdlg != NULL) {
        _pdlg->setAttribute(Qt::WA_DeleteOnClose);  //2parameter = true
        _pdlg->exec();
    }
#endif

#if 0
	_pdlg = new SetWPDlg(this);
	if (_pdlg != NULL) {
		_pdlg->setAttribute(Qt::WA_DeleteOnClose);
		_pdlg->exec();
	}
#endif
    //QMessageBox::warning(this, "set brd", "set brd", QMessageBox::Yes);
}

/**
  accept sel
*/
void CMDSimMW::on_bbx_sig_sel_accepted() {
    QMessageBox::warning(this, "accpet", "accept", QMessageBox::Yes);
}

/**
  reject sel
*/
void CMDSimMW::on_bbx_sig_sel_rejected() {
    QMessageBox::warning(this, "rejected..", "reject...", QMessageBox::Yes);
}
