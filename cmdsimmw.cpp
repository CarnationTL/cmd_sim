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
#include <QList>
#include <QHeaderView>
typedef int(* funca )(int);


CMDSimMW::CMDSimMW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMDSimMW) {

    SIG_LVDT = new QString(cvcp936("LVDT"));
    SIG_AO = new QString(cvcp936("AO"));
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




    initAOList();
    initLchList();
    initInsView();
    initSeachLE();
    initHWSel();
    initCHModel();

    initTbl();
    //_pcbxCh->clear();
    //_pcbxCh->setModel(ach_model);
}

CMDSimMW::~CMDSimMW() {
    if(SIG_LVDT != NULL)
        delete SIG_LVDT;
    if(SIG_AO != NULL)
        delete SIG_AO;
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

    delete prefix;
    delete end;
    prefix = NULL;
    end = NULL;
    return ps_ins_v->size();
}

void CMDSimMW::qbshow(QString str) {
    QMessageBox::warning(this, str, str, QMessageBox::Yes);
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
  init hw select
*/
void CMDSimMW::initHWSel() {
    _pcbxSigSel = ui->cbx_sigts;
    _pcbxCh = ui->cbx_ch;
    if(_pcbxSigSel != NULL && _pcbxCh != NULL) {
        _pcbxSigSel->addItem(cvcp936("LVDT"));
        _pcbxSigSel->addItem(cvcp936("AO"));
    }
}


/**
  diff type with diff models
*/

void CMDSimMW::initCHModel() {
    QString _tmpStr;
    QString _sLVDT(cvcp936("LVDT"));
    QString _sAO(cvcp936("AO"));
    _pcbxCh = ui->cbx_ch;
    if(_pcbxSigSel != NULL && _pcbxCh != NULL) {
//        _tmpStr = _pcbxSigSel->currentText();
        if(_tmpStr.compare(_sLVDT, Qt::CaseInsensitive) == 0) {
            //bind model
            //_pcbxCh->addItem(cvcp936("LVDT>>>>>>"));
            if(lch_model != NULL) {
                _pcbxCh->setModel(lch_model);
            }
        } else if(_tmpStr.compare(_sAO, Qt::CaseInsensitive) == 0) {
            //bind model
            //_pcbxCh->addItem(cvcp936("AO>>>>>>"));
            if(ach_model != NULL) {
                _pcbxCh->setModel(ach_model);
            }
        }
    }
}

void CMDSimMW::initLchList() {
    lch_model = new QStandardItemModel();
    for(int i = 0; i < MAX_LVDT_CH; i++) {
        QStandardItem *item = new QStandardItem(cvcp936("LVDT") + QString::number(i, 10));
        lch_model->appendRow(item);
    }
    rlch_model = new QStandardItemModel();
}

void CMDSimMW::initAOList() {
    ach_model = new QStandardItemModel();
    for(int i = 0; i < MAX_AO_CH; i++) {
        QStandardItem *item = new QStandardItem(cvcp936("AO") + QString::number(i, 10));
        ach_model->appendRow(item);
    }
    rach_model = new QStandardItemModel();
}

/**
  init tbl
*/
void CMDSimMW::initTbl() {
    _ptbl = ui->tbl_selres;
    tbl_model = new QStandardItemModel(4, 4);
    _ptbl->setModel(tbl_model);
    tbl_model->setHeaderData(0, Qt::Horizontal, cvcp936("类型"));
    tbl_model->setHeaderData(1, Qt::Horizontal, cvcp936("名称"));
    tbl_model->setHeaderData(2, Qt::Horizontal, cvcp936("编号"));
    tbl_model->setHeaderData(3, Qt::Horizontal, cvcp936("模式"));

    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            QModelIndex idx = tbl_model->index(i, j);
            if(j == 0) {
                tbl_model->setData(idx, "L");
            } else {
                tbl_model->setData(idx, "test");
            }

        }
    }
    //set last col
    _ptbl->horizontalHeader()->setStretchLastSection(true);
    _ptbl->setColumnWidth(0, 35);
    if(_ptbl != NULL) {

    }
}


#if 0
void CMDSimMW::initLchModel() {
    QStringList _strlist;
    lch_model = new QStandardItemModel(MAX_LVDT_CH, 0, 0);
    QString _tmp;
    for(int i = 0; i < MAX_LVDT_CH; i++) {
        _tmp.clear();
        _tmp.append((cvcp936("LVDT") + i));
        _strlist.append(_tmp);
        QStandardItem *_item = new QStandardItem(_tmp.at(i));
        //lch_model->setItem(i, _item);
        lch_model->insertRow(i, _item);
    }
//    _pcbxCh = ui->cbx_ch;
//    _pcbxCh->setModelColumn(0);
//    _pcbxCh->setModel(lch_model);
}
#endif

#if 0
void CMDSimMW::initAOModel() {
 QStringList _strlist;
    ach_model = new QStandardItemModel(MAX_AO_CH, 0);
    QString _tmp;
    for(int i = 0; i < MAX_LVDT_CH; i++) {
        _tmp.clear();
        _tmp.append((cvcp936("AO") + i));
        _strlist.append(_tmp);
        QStandardItem *_item = new QStandardItem(_tmp.at(i));
        ach_model->setItem(i, _item);
    }
}
#endif

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

/**
  bind the model when indx changed..
*/
void CMDSimMW::on_cbx_sigts_currentIndexChanged(const QString &arg1) {

    if(lch_model->rowCount() < 0 || ach_model->rowCount() < 0) {
        return;
    }

    QString _sLVDT(cvcp936("LVDT"));
    QString _sAO(cvcp936("AO"));
    _pcbxCh = ui->cbx_ch;
    //_pcbxCh->clear();
    if(arg1.compare(_sLVDT, Qt::CaseInsensitive) == 0) {
        //band model
        //_pcbxCh->addItem(cvcp936("LVDT>>>>>>"));
        _pcbxCh->setModel(lch_model);
    } else if(arg1.compare(_sAO, Qt::CaseInsensitive) == 0) {
        //band model
        //_pcbxCh->addItem(cvcp936("AO>>>>>>"));
        _pcbxCh->setModel(ach_model);

    }
}
/**
  select the sig ch and type
*/
void CMDSimMW::on_pushButton_clicked() {
    _pcbxCh = ui->cbx_ch;
    _pcbxSigSel = ui->cbx_sigts;
    QString _curText, _curText2;
    _curText = _pcbxCh->currentText();
    _curText2 = _pcbxSigSel->currentText();

    QList <QStandardItem *> findres;
    findres = lch_model->findItems(_curText);
    if(findres.size() == 1) {
       qbshow( QString::number(findres.at(0)->row(), 10));
    }
}


/**
  switch To remove models
*/
bool CMDSimMW::switchtoRmodel(QStandardItem *item, int type) {
    QList <QStandardItem *> fres;
    if(type == T_L) {
        fres = lch_model->findItems(item->text());
        if(fres.size() == 1) { //ex find
            rlch_model->appendRow(item);
            lch_model->removeRow(item->row());
            return true;
        }
        return false;
    } else if(type == T_A) {
        fres = ach_model->findItems(item->text());
        if(fres.size() == 1) {
            rach_model->appendRow(item);
            ach_model->removeRow(item->row());
            return true;
        }
        return true;
    }
    return false;
}


/**
  switch r model to u model
*/
bool CMDSimMW::switchtoUmodel(QStandardItem *item, int type) {
    QList <QStandardItem *> fres;
    if(type == T_L) {
        fres = rlch_model->findItems(item->text());
        if(fres.size() == 1) { //ex find
            lch_model->appendRow(item);
            rlch_model->removeRow(item->row());
            lch_model->sort(0);
            return true;
        }
        return false;
    } else if(type == T_A) {
        fres = rach_model->findItems(item->text());
        if(fres.size() == 1) {
            ach_model->appendRow(item);
            rach_model->removeRow(item->row());
            ach_model->sort(0);
            return true;
        }
        return true;
    }
    return false;
}
