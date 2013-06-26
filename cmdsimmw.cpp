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

#include <sigpara.h>
#include <siggen.h>

#include <QTextBrowser>
#include <QPlainTextEdit>
#include <QPalette>
#include <QTimer>
#include <QIcon>
#include <QDebug>

typedef int(* funca )(int);
int chSta = -1;
#define TBL_COL 4

CMDSimMW::CMDSimMW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMDSimMW) {


    connect(this, SIGNAL(msig_delIndex(QModelIndex&)), this, SLOT(m_delItem(QModelIndex&)));

    SIG_LVDT = new QString(cvcp936("LVDT"));
    SIG_AO = new QString(cvcp936("AO"));

    ui->setupUi(this);


    initWidgetsPointer();

#if 1
	addtionSetUi();
#endif
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
    initoptLog();


#if 1                                           /* test the sig gen */
    Sine para(1, 23);
    SineGen *p = new SineGen();
    p->genData(para);
#endif

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


int CMDSimMW::initAoInstructs() {
    QStringList *prefix = new QStringList();

    prefix->append(cvcp936("左驾驶盘力信号"));
    prefix->append(cvcp936("右驾驶盘力信号"));
    prefix->append(cvcp936("左驾驶柱力信号"));
    prefix->append(cvcp936("右驾驶柱力信号"));

    prefix->append(cvcp936("左脚蹬力信号"));
    prefix->append(cvcp936("右脚蹬力信号"));

    prefix->append(cvcp936("减速杆力信号"));
    prefix->append(cvcp936("减速杆力信号"));

    QStringList *end = new QStringList();
    end->append("A");
    end->append("B");
    end->append("C");
    end->append("D");


    ps_ao_ins_v = new QStringList();
    QString tempStr;

    if(prefix == NULL || end == NULL)
        return NULL;

    for(int i = 0; i < prefix->size(); i++) {
        for(int j = 0; j < end->size(); j++)  {
            tempStr.clear();
            tempStr.prepend(prefix->at(i));
            tempStr.append(end->at(j));
            ps_ao_ins_v->append(tempStr);
        }
    }

    delete prefix;
    delete end;
    prefix = NULL;
    end = NULL;
    return ps_ao_ins_v->size();
}


int CMDSimMW::initLvInstructs() {
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
    //Cmd_D_model.Model dv_model;
    //_plistvsig = ui->listw_sig_sel;
    int cnt = initLvInstructs();
    initLvsigNameModel(cnt);
    int cnt1 = initAoInstructs();
    initAOsigNameModel(cnt1);

    _plistvsig->setModel(dv_lv_model);
}


/**
  init the search edit...
*/
void CMDSimMW::initSeachLE() {
    //_pSeachEdit = ui->edit_search;
    if(_pSeachEdit != NULL && dv_lv_model != NULL) {
        _pCompleter = new QCompleter(this);
        _pCompleter->setModel(dv_lv_model);
        _pSeachEdit->setCompleter(_pCompleter);
    }
}


/**
  init sigtype  select
*/
void CMDSimMW::initHWSel() {
    //_pcbxSigSel = ui->cbx_sigts;
    //_pcbxCh = ui->cbx_ch;
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
    //_pcbxCh = ui->cbx_ch;
    if(_pcbxSigSel != NULL && _pcbxCh != NULL) {
//        _tmpStr = _pcbxSigSel->currentText();
        if(_tmpStr.compare(_sLVDT, Qt::CaseInsensitive) == 0) {
            //bind model
            //_pcbxCh->addItem(cvcp936("LVDT>>>>>>"));
            if(lch_model != NULL) {
                _pcbxCh->setModel(lch_model);
                _plistvsig->setModel(dv_lv_model);
            }
        } else if(_tmpStr.compare(_sAO, Qt::CaseInsensitive) == 0) {
            //bind model
            //_pcbxCh->addItem(cvcp936("AO>>>>>>"));
            if(ach_model != NULL) {
                _pcbxCh->setModel(ach_model);
                _plistvsig->setModel(dv_ao_model);
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
    //set table sytle
    //_ptbl = ui->tbl_selres;
    if(_ptbl == NULL) {
        return;
    }
    tbl_model = new QStandardItemModel(4, 4);
    _ptbl->setModel(tbl_model);
    tbl_model->setHeaderData(0, Qt::Horizontal, cvcp936("类型"));
    tbl_model->setHeaderData(1, Qt::Horizontal, cvcp936("名称"));
    tbl_model->setHeaderData(2, Qt::Horizontal, cvcp936("编号"));
    tbl_model->setHeaderData(3, Qt::Horizontal, cvcp936("模式"));
    for(int i = 0; i < TBL_COL; i++) {
        for(int j = 0; j < TBL_COL; j++) {
            QModelIndex idx = tbl_model->index(i, j);
            //test the first col...
            if(j == 0) {
                tbl_model->setData(idx, "L");
                //TableVButtonDeg btn;
                //_ptbl->setItemDelegate(&btn);
                _ptbl->setIndexWidget(tbl_model->index(i, j), new QPushButton("L"));
            } else {
                tbl_model->setData(idx, "test");
            }
        }
    }
}



/* not complete yet for show warning in plainEdit  */
int CMDSimMW::warningTextInfo(QPlainTextEdit &p) {
    QPalette porg = p.palette();
    QPalette pdef;
    pdef.setColor(QPalette::WindowText, Qt::yellow);
    pdef.setColor(QPalette::Text, Qt::yellow);
    pdef.setColor(QPalette::Active, QPalette::Base, Qt::red);
    pdef.setColor(QPalette::Inactive, QPalette::Base, Qt::red);


    p.setPalette(pdef);

    pdef.setColor(QPalette::WindowText, Qt::green);
    pdef.setColor(QPalette::Text, Qt::yellow);
    pdef.setColor(QPalette::Active, QPalette::Base, Qt::red);
    pdef.setColor(QPalette::Inactive, QPalette::Base, Qt::red);

    p.setPalette(pdef);



    pdef.setColor(QPalette::WindowText, Qt::blue);
    pdef.setColor(QPalette::Text, Qt::yellow);
    pdef.setColor(QPalette::Active, QPalette::Base, Qt::green);
    pdef.setColor(QPalette::Inactive, QPalette::Base, Qt::green);

    p.setPalette(pdef);


    pdef.setColor(QPalette::WindowText, Qt::yellow);
    pdef.setColor(QPalette::Text, Qt::yellow);
    pdef.setColor(QPalette::Active, QPalette::Base, Qt::red);
    pdef.setColor(QPalette::Inactive, QPalette::Base, Qt::red);

    p.setPalette(pdef);


    p.setPalette(porg);
    return 0;
}


int CMDSimMW::showWarning() {
    for(int i = 0; i < 10 ; i++) {
        warningTextInfo(*(ui->pploptStatus));
    }
    return 0;

}

/**
  init Qtextbrowser and QPlainTextEdit
*/
void CMDSimMW::initoptLog() {

    //_ppl = ui->pploptStatus;
    QPalette pal;
    pal.setColor(QPalette::WindowText, Qt::yellow);
    pal.setColor(QPalette::Text, Qt::yellow);
    pal.setColor(QPalette::Active, QPalette::Base, Qt::red);
    pal.setColor(QPalette::Inactive, QPalette::Base, Qt::red);
    _ppl->setPalette(pal);

    if(_ppl != NULL) {
        _ppl->setPlainText("=============");
        _ppl->appendPlainText("show one line");
        _ppl->appendPlainText("===============");

        _ppl->setReadOnly(true);
    }
#if 0
    for(int i = 0;i < 5; i++) {

        QMessageBox::warning(this, "fsdafdsa", "fdsafdsa", QMessageBox::Yes);
        Sleep(100);
        pal.setColor(QPalette::WindowText, Qt::yellow);
        pal.setColor(QPalette::Text, Qt::yellow);
        pal.setColor(QPalette::Active, QPalette::Base, Qt::red);
        pal.setColor(QPalette::Inactive, QPalette::Base, Qt::red);

        pal.setColor(QPalette::WindowText, Qt::black);
        pal.setColor(QPalette::Text, Qt::black);
        pal.setColor(QPalette::Active, QPalette::Base, Qt::white);
        pal.setColor(QPalette::Inactive, QPalette::Base, Qt::white);

        _ppl->setPalette(pal);
    }
#endif
    /* qbshow(_ppl->toPlainText()); */
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

    if(_plistvsig->model() == dv_lv_model) {
        if(_pNewSigEdit != NULL) {
            QString tmp = _pNewSigEdit->text();
            if(tmp.size() > 0) {
                addItemToModel(dv_lv_model, tmp);
                QString astr(cvcp936("添加信号：") + tmp + QString("--->") + cvcp936("LVDT信号列表"));
                appendtxtStatus(astr);
            } else {
                QMessageBox::warning(this, "waring", cvcp936("请输入信号名称！"));
            }
        }
    } else if(_plistvsig->model() == dv_ao_model) {
        if(_pNewSigEdit != NULL) {
            QString tmp = _pNewSigEdit->text();
            if(tmp.size() > 0) {
                addItemToModel(dv_ao_model, tmp);
                QString astr(cvcp936("添加信号：") + tmp + QString("--->") + cvcp936("AO信号列表"));
                appendtxtStatus(astr);
            } else {
                QMessageBox::warning(this, "waring", cvcp936("请输入信号名称！"));
            }
        }
    }
}

/**
  reject sel do this function once can't del all 
  so use while to force call del function
*/
void CMDSimMW::on_bbx_sig_sel_rejected() {
    if(_plistvsig->model() == dv_lv_model) {
        while(rechkItemSel(dv_lv_model)) {
            for(int i = 0; i < dv_lv_model->rowCount(); i++) {
                if(dv_lv_model->item(i, 0)->checkState() == Qt::Checked) {
                    emit(msig_delIndex(dv_lv_model->index(i, 0)));
                }
            }
        }
    } else if(_plistvsig->model() == dv_ao_model) {
        while(rechkItemSel(dv_ao_model)) {
            for(int i = 0; i < dv_ao_model->rowCount(); i++) {
                if(dv_ao_model->item(i, 0)->checkState() == Qt::Checked) {
                    emit(msig_delIndex(dv_ao_model->index(i, 0)));
                }
            }
        }
    }

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
    //_pcbxCh = ui->cbx_ch;
    //_pcbxCh->clear();
    if(arg1.compare(_sLVDT, Qt::CaseInsensitive) == 0) {
        //band model
        //_pcbxCh->addItem(cvcp936("LVDT>>>>>>"));
        _pcbxCh->setModel(lch_model);
        _plistvsig->setModel(dv_lv_model);
    } else if(arg1.compare(_sAO, Qt::CaseInsensitive) == 0) {
        //band model
        //_pcbxCh->addItem(cvcp936("AO>>>>>>"));
        _pcbxCh->setModel(ach_model);
        _plistvsig->setModel(dv_ao_model);

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
        return false;
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
        return false;
    }
    return false;
}

void CMDSimMW::on_commandLinkButton_clicked() {


#if 1
    showWarning();
#endif
#if 0
    _pqwtdlg = new SetWPDlg(this);
    if(_pqwtdlg != NULL) {
        //_pqwtdlg->setAttribute(Qt::WA_DeleteOnClose);  //2parameter = true
        _pqwtdlg->setAttribute(Qt::WA_DeleteOnClose);
        _pqwtdlg->exec();
    }
#endif
}

/*
  _pqwtdlg = new SetWPDlg(this);
  if(_pqwtdlg_ )
*/

void CMDSimMW::on_pushButton_2_clicked() {

    //_ppl = ui->pploptStatus;
    QPalette pal;
    pal.setColor(QPalette::WindowText, Qt::red);
    pal.setColor(QPalette::Text, Qt::red);
    pal.setColor(QPalette::Active, QPalette::Base, Qt::blue);
    pal.setColor(QPalette::Inactive, QPalette::Base, Qt::blue);
    _ppl->setPalette(pal);

    if(_ppl != NULL) {
        _ppl->setPlainText("=============");
        _ppl->appendPlainText("show one line");
        _ppl->appendPlainText("===============");

        _ppl->setReadOnly(true);
    }

#if 0
    for(int i = 0;i < 5; i++) {
        Sleep(1000);
        if(i % 2 == 0) {
            pal.setColor(QPalette::WindowText, Qt::yellow);
            pal.setColor(QPalette::Text, Qt::yellow);
            pal.setColor(QPalette::Active, QPalette::Base, Qt::red);
            pal.setColor(QPalette::Inactive, QPalette::Base, Qt::red);
        } else {
            pal.setColor(QPalette::WindowText, Qt::black);
            pal.setColor(QPalette::Text, Qt::black);
            pal.setColor(QPalette::Active, QPalette::Base, Qt::white);
            pal.setColor(QPalette::Inactive, QPalette::Base, Qt::white);
        }
       _ppl->setPalette(pal);
    }
#endif

}

void CMDSimMW::on_pushButton_3_clicked() {

    //_ppl = ui->pploptStatus;
    QPalette pal;
    pal.setColor(QPalette::WindowText, Qt::red);
    pal.setColor(QPalette::Text, Qt::red);
    pal.setColor(QPalette::Active, QPalette::Base, Qt::yellow);
    pal.setColor(QPalette::Inactive, QPalette::Base, Qt::yellow);
    _ppl->setPalette(pal);

    if(_ppl != NULL) {
        _ppl->setPlainText("=============");
        _ppl->appendPlainText("show one line");
        _ppl->appendPlainText("===============");
        _ppl->setReadOnly(true);
    }
}


void CMDSimMW::on_btn_setwp_clicked() {
	QDialog *p = new SetWPDlg();
	if(p != NULL) {
		p->show();
	}
}

void CMDSimMW::myBtnSlot() {
	qbshow("test my own slot");
}


/* init pointers of main Widget.. */
void CMDSimMW::initWidgetsPointer() {

    _pMainLay = NULL;
    _pLeftLay = NULL;
    _pLeftLay = NULL;
    _pCompleter = NULL;
    _pcbxSigSel = NULL;
    _pcbxCh = NULL;
    _ptbl = NULL;
    _pqwtdlg = NULL;
    _ppl = NULL;
    _ptbl = NULL;
    _pbtnBoxSigSel = NULL;

    _pbtnBoxSigSel = ui->bbx_sig_sel;

    _pSeachEdit = ui->edit_search;
    _plistvsig = ui->listw_sig_sel;
    _pNewSigEdit = ui->edit_newSig;
    _ppl = ui->pploptStatus;
    _pcbxSigSel = ui->cbx_sigts;
    _pcbxCh = ui->cbx_ch;
    _ptbl = ui->tbl_selres;

}

/*add own sig to Control */
void CMDSimMW::addtionSetUi() {
    connect(ui->btn_MySin, SIGNAL(clicked()), this, SLOT(myBtnSlot()));

    //modify
    if(_pbtnBoxSigSel != NULL) {
        QPushButton *pt = NULL;
        pt = _pbtnBoxSigSel->button(QDialogButtonBox::Ok);
        if(pt != NULL) {
            pt->setText(cvcp936("添加信号"));
        }
        pt = NULL;
        pt = _pbtnBoxSigSel->button(QDialogButtonBox::Cancel);
        if(pt != NULL) {
            pt->setText(cvcp936("删除信号"));
        }
    }
    CMDSimMW::setWindowIcon(QIcon(":image/MW.ico"));

}

/* append text to status brower*/
void CMDSimMW::appendtxtStatus(QString &str) {
    //_ppl = ui->pploptStatus;
    _ppl->appendPlainText(str);
}

void CMDSimMW::on_pushButton_4_clicked() {
    //_ppl = ui->pploptStatus;
    _ppl->appendPlainText("new line\n");
}



/**
  select the sig ch and type
*/
void CMDSimMW::on_btn_sigSel_ok_clicked() {
 //_pcbxCh = ui->cbx_ch;
    //_pcbxSigSel = ui->cbx_sigts;
    QString _curText, _curText2;
    _curText = _pcbxCh->currentText();
    _curText2 = _pcbxSigSel->currentText();

    QList <QStandardItem *> findres;
    findres = lch_model->findItems(_curText);
    if(findres.size() == 1) {
       qbshow( QString::number(findres.at(1)->row(), 10));
    }
}


//void  CMDSimMW::on_sigLv_clicked(const QModelIndex &index) {
//
//}
/* listw_sig_sel checkState  */
void CMDSimMW::on_listw_sig_sel_clicked(const QModelIndex &index) {
     QStandardItem *pf = NULL;
    if(_plistvsig->model() == dv_lv_model) {
        pf = dv_lv_model->itemFromIndex(index);
    } else if(_plistvsig->model() == dv_ao_model) {
        pf = dv_ao_model->itemFromIndex(index);
    }
    if(pf == NULL) {
        return;
    }
    QString tmp("");
    if(pf->isCheckable() == false) {
        return;
    }
    if(pf->checkState() == Qt::Checked && chSta == Qt::Unchecked ) {
        tmp.append(cvcp936("选中->"));
        tmp.append(pf->text());
        appendtxtStatus(tmp);
    } else if (pf->checkState() == Qt::Unchecked && chSta == Qt::Checked ) {
        tmp.append(cvcp936("取消选中->"));
        tmp.append(pf->text());
        appendtxtStatus(tmp);
    }
}

void CMDSimMW::addtionSigSlotsMVC() {
    return;
}

int CMDSimMW::addItemToModel(QStandardItemModel *model, QString &newItem) {
    QStandardItem *pi = new QStandardItem(newItem);
    pi->setCheckable(true);
    pi->setCheckState(Qt::Unchecked);
    model->appendRow(pi);
    return 0;
}

/* del Items from model by check */
int CMDSimMW::delItemFromModel(QStandardItemModel *model) {
    if(model->rowCount() > 0) {
        int tmp = model->rowCount();
        for (int i = 0; i < tmp; i++) {
            if(model->item(i, 0)->checkState() == Qt::Checked) {
                model->removeRow(i);
            }
        }
    }
    return 0;
}

int CMDSimMW::rechkItemSel(QStandardItemModel *model) {
    int tmp = model->rowCount();
    for(int i = 0; i < tmp; i++) {
        if(model->item(i)->checkState() == Qt::Checked){
            return 1;
        }
    }
    return 0;
}

void CMDSimMW::m_delItem(QModelIndex &index) {
    if(_plistvsig->model() == dv_lv_model) {
        dv_lv_model->removeRow(index.row(), index.parent());
        QString tmp(dv_lv_model->itemFromIndex(index)->text());
        QString astr(cvcp936("删除信号：") + tmp + QString("<---") + cvcp936("LVDT信号列表"));
        appendtxtStatus(astr);
    } else if(_plistvsig->model() == dv_ao_model) {
        dv_ao_model->removeRow(index.row(), index.parent());
        QString tmp(dv_ao_model->itemFromIndex(index)->text());
        QString astr(cvcp936("删除信号：") + tmp + QString("<---") + cvcp936("AO信号列表"));
        appendtxtStatus(astr);
    }
}

/* reset lvdt sig */
void CMDSimMW::on_action_reset_sigDis_triggered() {
    QString tmpstr(cvcp936("确定重置LVDT信号列表？"));
    int ret = QMessageBox::warning(this, cvcp936("提示"),
            tmpstr,
            QMessageBox::Yes | QMessageBox::Cancel,
            QMessageBox::Yes);

    if(ret == QMessageBox::Yes) {
        dv_lv_model->clear();
        dv_lv_model->removeRows(0, dv_lv_model->rowCount());
        int tmp = org_dv_lv_model->rowCount();
        for(int i = 0; i < tmp; i++) {
            QStandardItem *p = new QStandardItem(org_dv_lv_model->item(i, 0)->text());
            p->setCheckable(true);
            p->setCheckState(Qt::Unchecked);
            dv_lv_model->setItem(i, 0, p);
        }
        appendtxtStatus(cvcp936("重置LVDT信号列表!"));
        //_plistvsig->setModel(dv_model);           /* already bind model to Widget  */
    } else if(ret == QMessageBox::Cancel) {
        //do nothing
    }
}

/*init lch signal model */
void CMDSimMW::initLvsigNameModel(int cnt) {
    dv_lv_model = new QStandardItemModel(cnt, 0);
    org_dv_lv_model = new QStandardItemModel(cnt, 0);
    if(cnt > 0) {
        //// Cmd_DM_Item *newItem;
        QStandardItem *newItem;
        QStandardItem *org_newItem;
        for(int i = 0; i < cnt; i++) {
            newItem = new QStandardItem(ps_ins_v->at(i));
            newItem->setCheckable(true);
            newItem->setCheckState(Qt::Unchecked);

            org_newItem = new QStandardItem(ps_ins_v->at(i));
            org_newItem->setCheckable(true);
            org_newItem->setCheckState(Qt::Unchecked);

            dv_lv_model->setItem(i, newItem);
            org_dv_lv_model->setItem(i, org_newItem);
        }
    }
}
/* init ao ch model */
void CMDSimMW::initAOsigNameModel(int cnt) {
    dv_ao_model = new QStandardItemModel(cnt, 0);
    org_dv_ao_model = new QStandardItemModel(cnt, 0);
    if(cnt > 0) {
        QStandardItem *newItem;
        QStandardItem *org_newItem;
        for(int i = 0; i < cnt; i++) {
            newItem = new QStandardItem(ps_ao_ins_v->at(i));
            newItem->setCheckable(true);
            newItem->setCheckState(Qt::Unchecked);

            org_newItem = new QStandardItem(ps_ao_ins_v->at(i));
            org_newItem->setCheckable(true);
            org_newItem->setCheckState(Qt::Unchecked);

            dv_ao_model->setItem(i, newItem);
            org_dv_ao_model->setItem(i, org_newItem);
        }
    }
}

void CMDSimMW::on_listw_sig_sel_pressed(const QModelIndex &index) {
    QStandardItem *p = NULL;
    if(_plistvsig == NULL)
        return;
    if(_plistvsig->model() == dv_lv_model) {
        p = dv_lv_model->itemFromIndex(index);
    } else if(_plistvsig->model() == dv_ao_model) {
        p = dv_ao_model->itemFromIndex(index);
    }
    chSta = p->checkState();
}

/* reset signal dis */
void CMDSimMW::on_action_reset_SigAO_triggered() {
    QString tmpstr(cvcp936("确定重置AO信号列表？"));
    int ret = QMessageBox::warning(this, cvcp936("提示"),
                                   tmpstr,
                                   QMessageBox::Yes | QMessageBox::Cancel,
                                   QMessageBox::Yes);


    if(ret == QMessageBox::Yes) {
        dv_ao_model->clear();
        dv_ao_model->removeRows(0, dv_ao_model->rowCount());
        int tmp = org_dv_ao_model->rowCount();
        for(int i = 0; i < tmp; i++) {
            QStandardItem *p = new QStandardItem(org_dv_ao_model->item(i, 0)->text());
            p->setCheckable(true);
            p->setCheckState(Qt::Unchecked);
            dv_ao_model->setItem(i, 0, p);
        }
        appendtxtStatus(cvcp936("重置AO信号列表!"));
    } else if(ret == QMessageBox::Cancel) {
        //do nothing
    }
}



void CMDSimMW::on_tbl_selres_activated(const QModelIndex &index) {
    QStandardItem *p = tbl_model->itemFromIndex(index);
    qDebug() << "active" << p->text();
}

/* result table clicked */
void CMDSimMW::on_tbl_selres_clicked(const QModelIndex &index) {
   // qbshow("clicked");
    QStandardItem *p = tbl_model->itemFromIndex(index);
    qDebug() << "clicked" << p->text();
}

void CMDSimMW::on_tbl_selres_pressed(const QModelIndex &index) {
    QStandardItem *p = tbl_model->itemFromIndex(index);
    qDebug() << "press" << p->text() ;
}
