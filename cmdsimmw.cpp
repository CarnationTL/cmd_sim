#define WIN32_LEAN_AND_MEAN
#include <qglobal.h>
#include <QMessageBox>
#include "cmdsimmw.h"
#include "ui_cmdsimmw.h"

#if defined(Q_OS_WIN)
#include "rfm2gse.h"
#include "C75C3Expls.h"
#include "c75c3dllencap.h"
#endif

#include "lvdtch.h"
#include <QStringList>
#include <QTextCodec>
#include <QDialog>
#include <QLayout>
#include "setbrddlg.h"
#include "setwpdlg.h"
#include "cmddefs.h"
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
#include <QCheckBox>
#include <QRadioButton>
#include <QDebug>

typedef int(* funca )(int);
int chSta = -1;
#define TBL_COL 4
#define TBL_ROW 20
#define MUL_SEL 2


CMDSimMW::CMDSimMW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMDSimMW) {

    _pSigMaper = new QSignalMapper();           /* init sigmaper for all */
    connect(this, SIGNAL(msig_delIndex(QModelIndex&)), this, SLOT(m_delItem(QModelIndex&)));

    SIG_LVDT = new QString(cvcp936("LVDT"));
    SIG_AO = new QString(cvcp936("AO"));

    empty_model = new QStandardItemModel();
    ui->setupUi(this);


    initWidgetsPointer();


    addtionSetUi();


#if 0                                   /* init rfm lib */
	if (initrfm() != EXE_SUCCESS) {
		QMessageBox::warning(NULL, "lib_load", "lib_load", QMessageBox::Yes);
	}
#endif

#if 0                                   /* init 75c3 when hardware install */
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
    //initAOList();
    //initLchList();
    initInsView();

    initLAchWidgetLs ();
    initSeachLE();
    initcbxsigts ();
    initCHModel();

    initTbl();
    initoptLog();

    //initlistvCh ();                             /* bind model to listview */

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




void CMDSimMW::qbshow(QString str) {
    QMessageBox::warning(this, str, str, QMessageBox::Yes);
}

int CMDSimMW::initrfm() {
#if defined(Q_OS_WIN)
    RFM2gSE se;
    return se.open();
#elif defined(Q_OS_LINUX)
    return 0;
#endif

}

int CMDSimMW::init75c3() {
    return 0;
}
/**
  convert cp936 to unicode
*/
#if defined(Q_OS_WIN)

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

#elif defined(Q_OS_LINUX)
//do nothing
QString CMDSimMW::cvcp936(const char str[]) {
    if((sizeof(str) /sizeof(char)) <= 0)
        return QString("");
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    if(codec != NULL) {
        QString ret = codec->toUnicode(str);
        return ret;
    }
    return QString("");
}
#endif




/* bind  to lch model listview Control */
/**
  default to init lchlist and map clicked sig to Sigmapper
  default to init lchlist with checkbox
*/
void CMDSimMW::initlistvCh() {
#if !defined(T_CODE)
    _plistvch->setEditTriggers (QAbstractItemView::NoEditTriggers);
    int row = lch_model->rowCount ();
    QCheckBox *chk = NULL;
    QModelIndex pindx;
    QStandardItem *pitem = NULL;
    _plistvch->setModel (empty_model);
    _plistvch->setModel (lch_model);
    for(int i = 0; i < row; i++) {
        pindx = lch_model->index (i, 0);
        pitem = lch_model->itemFromIndex (pindx);
        //chk = new QCheckBox(pitem->text ());        /* init text with  lch_model item text*/
        chk = new QCheckBox();        /* init text with  lch_model item text*/
        _plistvch->setIndexWidget (pindx, chk);
    }
#else
    _plistvch->setEditTriggers (QAbstractItemView::NoEditTriggers);
    _plistvch->setModel (lch_model);
#endif
}

#if 0
void CMDSimMW::initLchList() {
    lch_model = new QStandardItemModel();
    for(int i = 0; i < MAX_LVDT_CH; i++) {
        QStandardItem *item = new QStandardItem(cvcp936("LVDT") + QString::number(i, 10));
        item->setCheckable (true);
        item->setCheckState (Qt::Unchecked);
        lch_model->appendRow(item);
    }
    rlch_model = new QStandardItemModel();
}
#endif

#if 0
void CMDSimMW::initAOList() {
    ach_model = new QStandardItemModel();
    for(int i = 0; i < MAX_AO_CH; i++) {
        QStandardItem *item = new QStandardItem(cvcp936("AO") + QString::number(i, 10));
        item->setCheckable (true);
        item->setCheckState (Qt::Unchecked);
        ach_model->appendRow(item);
    }
    rach_model = new QStandardItemModel();
}
#endif

void CMDSimMW::initcbxsigts() {
    _pcbxSigSel->insertItem (0, cvcp936 ("LVDT"));
    _pcbxSigSel->insertItem (1, cvcp936 ("AO"));
}

//
//void CMDSimMW::InitLchListWidget() {
//    lch_model = new QStandardItemModel();
//    for(int i = 0; i < MAX_LVDT_CH; i++) {
//        //QStandardItem *item = new QStandardItem("QString::number (i + 1, 10)");
//        QStandardItem *item = new QStandardItem("");
//        lch_model->appendRow (item);
//    }
////    int len = lch_model->rowCount ();
////   // QRadioButton *rad = NULL;
////    _plistvch->setModel (lch_model);
////    for(int i = 0; i < len; i++) {
////        QModelIndex idx = lch_model->index (i, 0);
////        //rad = new QRadioButton(cvcp936 ("LVDT") + QString::number (i, 10));
////      //  _plistvch->setIndexWidget (idx, _lslvchk.at (i));
////    }
//}

//void CMDSimMW::InitAOListWidget() {
//    ach_model = new QStandardItemModel();
//    for (int i = 0; i < MAX_AO_CH; ++i) {
//        QStandardItem *it = new QStandardItem("");
//        ach_model->appendRow (it);
//    }
//}


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
    QModelIndex indx_;
    if(_plistvsig->model() == dv_lv_model) {
        while(rechkItemSel(dv_lv_model)) {
            for(int i = 0; i < dv_lv_model->rowCount(); i++) {
                if(dv_lv_model->item(i, 0)->checkState() == Qt::Checked) {
                    indx_ = dv_lv_model->index(i, 0);
                    emit(msig_delIndex(indx_));
                }
            }
        }
    } else if(_plistvsig->model() == dv_ao_model) {
        while(rechkItemSel(dv_ao_model)) {
            for(int i = 0; i < dv_ao_model->rowCount(); i++) {
                if(dv_ao_model->item(i, 0)->checkState() == Qt::Checked) {
                    indx_ = dv_ao_model->index(i, 0);
                    emit(msig_delIndex(indx_));
                }
            }
        }
    }

}

/**
  bind the model when indx changed..
*/
void CMDSimMW::on_cbx_sigts_currentIndexChanged(const QString &arg1) {

    if(_pcbxSigSel->count () < 2) {
        return;
    }

    qDebug () << lch_model->rowCount () << ach_model->rowCount () ;
    if(lch_model->rowCount() < 0 || ach_model->rowCount() < 0) {
        return;
    }

    QString _sLVDT(cvcp936("LVDT"));
    QString _sAO(cvcp936("AO"));
    //_pcbxCh = ui->cbx_ch;
    //_pcbxCh->clear();
    //band model
    if(arg1.compare(_sLVDT, Qt::CaseInsensitive) == 0) {
        _plistvsig->setModel(dv_lv_model);
        _plistvch->setModel (lch_model);
        qDebug () << _lslvchk.size () << "|||" << _lslvradio.size ();
        for(int i = 0; i < lch_model->rowCount (); i++) {
            _plistvch->setIndexWidget (lch_model->index (i, 0), _lslvradio.at (i));
            //_plistvch->setIndexWidget (lch_model->index (i, 0), new QCheckBox("aa"));
        }
    } else if(arg1.compare(_sAO, Qt::CaseInsensitive) == 0) {
        _plistvsig->setModel(dv_ao_model);
        _plistvch->setModel (ach_model);
        qDebug () << _lsaochk.size () << "|||" << _lsaoradio.size ();
        for(int i = 0 ; i < ach_model->rowCount (); i++) {
            _plistvch->setIndexWidget (ach_model->index (i, 0), _lsaoradio.at (i));
            //_plistvch->setIndexWidget (ach_model->index (i, 0), new QCheckBox("Bb"));


        }
    }

}

void CMDSimMW::on_btn_setwp_clicked() {
//	QDialog *p = new SetWPDlg();
    ///if(p != NULL) {
    ///	p->show();
    ///}

    if(_psetwpdlg != NULL) {
        _psetwpdlg->exec ();
    }
}

void CMDSimMW::myBtnSlot() {
	qbshow("test my own slot");
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
#if defined(T_CODE)
    //get the select lvdt ch number and relate channel number
    QString _ctxt1, _ctxt2;
    QStandardItemModel *p = (QStandardItemModel *)_plistvch->model ();
    QModelIndex pindx = _plistvch->currentIndex ();
    if(p == lch_model) {

    } else if( p == ach_model) {

    } else {
        QMessageBox::warning (this, cvcp936 ("警告"), cvcp936 ("关联模块出错，请重新启动应用程序"), QMessageBox::Yes);
        return;
    }
//_pcbxCh = ui->cbx_ch;
    //_pcbxSigSel = ui->cbx_sigts;
//    QString _curText, _curText2;
//    _curText = _pcbxCh->currentText();
//    _curText2 = _pcbxSigSel->currentText();
//
//    QList <QStandardItem *> findres;
//    findres = lch_model->findItems(_curText);
//    if(findres.size() == 1) {
//       qbshow( QString::number(findres.at(1)->row(), 10));
//    }
#endif

}


//void  CMDSimMW::on_sigLv_clicked(const QModelIndex &index) {
//
//}
/* listw_sig_sel checkState  */
void CMDSimMW::on_listw_sig_sel_clicked(const QModelIndex &index) {
     QStandardItem *pf = NULL;
    if(_plistvsig->model() == dv_lv_model) {
        pf = dv_lv_model->itemFromIndex(index);
        if(chkItemSelMul (dv_lv_model) >= MUL_SEL) {
            //TODO change to radio button
        }
    } else if(_plistvsig->model() == dv_ao_model) {
        pf = dv_ao_model->itemFromIndex(index);
        if(chkItemSelMul (dv_ao_model) >= MUL_SEL) {
            //TODO change to radio button
        }
    }
    if(pf == NULL) {
        return;
    }
    QString tmp("");
    if(pf->isCheckable() == false) {
        return;
    }
    /* append to status text */
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

/* recheck item sel for delete function */
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
        QString tmp_(cvcp936("重置LVDT信号列表!"));
        appendtxtStatus(tmp_);
        //_plistvsig->setModel(dv_model);           /* already bind model to Widget  */
    } else if(ret == QMessageBox::Cancel) {
        //do nothing
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
        QString tmp_(cvcp936("重置AO信号列表!"));
        appendtxtStatus(tmp_);
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

void CMDSimMW::mslot_tableClick(int row) {
    QMessageBox::warning (this, "run", QString::number (row, 10), QMessageBox::Yes);
}


void CMDSimMW::on_listv_ch_clicked(const QModelIndex &index) {

#if defined(T_CODE)
    int a = index.data ().toInt ();
    qDebug () << a;
#endif

#ifdef QT_DEBUG
    qDebug () << "debug" ;
#elif QT_NO_DEBUG
    qDebug () << "no debug" ;
#endif
}


/* check the multcheck */
/**
  return dv_lv_model check cnt
*/
int CMDSimMW::checkListSigSel(int type) {

    int cnt = 0;
    if(type == E_DV_AO_MODEL) {
        int row = dv_ao_model->rowCount ();
        for(int i = 0; i < row; i++) {
            QModelIndex pindx = dv_ao_model->index (i, 0);
            QStandardItem *p = dv_ao_model->itemFromIndex (pindx);
            if(p != NULL) {
                if(p->checkState () == Qt::Checked) {
                    cnt++;
                }
            }
        }
    } else if(type == E_DV_LV_MODEL) {
        int row = dv_lv_model->rowCount();
        for(int i = 0; i < row; i++) {
            QModelIndex pindx = dv_lv_model->index (i, 0);
            QStandardItem *p = dv_lv_model->itemFromIndex (pindx);
            if(p != NULL) {
                if( p->checkState () == Qt::Checked) {
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

/* change rc style for chs list */
int CMDSimMW::changeRCstyle (int type) {
#if defined(T_CODE)
    if(type == E_DV_LV_MODEL) {
        return EXE_SUCCESS;
    } else if(type == E_DV_AO_MODEL) {
        return EXE_SUCCESS;
    }
    return EXE_FAIL;
#else
    return;
#endif
    
}
/* checkState for sel */
int CMDSimMW::chkItemSelMul(QStandardItemModel *model) {
    if(model == NULL) {
        return EXE_FAIL;
    }
    int len = model->rowCount ();
    int cnt = 0;
    QModelIndex ind;
    for (int i = 0; i < len; ++i) {
        ind = model->index (i, 0);
        if(model->itemFromIndex (ind)->checkState () == Qt::Checked) {
            cnt++;
            if(cnt >= 2) {
                return cnt;
            }
        }
    }
    return cnt;
}


/* for the rd button click  */
/**
 * Sigmaper call back function
 */
void CMDSimMW::mslot_CHradioClick(QString str) {
    //TODO the radio button call back funtion
    return;
}

/*for the check box click*/
/** 
 * Sigmapper call back function
 */
void CMDSimMW::mslot_CHcheckClick(QString str) {
    //TODO the check box callback function

    if(str.length () <= 0) {
        return;
    }

    return;
}

void CMDSimMW::on_cbx_sigts_activated(int index) {

}
