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
#include "dlgsetch.h"
#include "exttools.h"
#include "cmddefs.h"
#include "dlgrfmdebug.h"
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
#include <QMenu>
#include <QProcess>

#include <oscilloscope/samplingthread.h>
#include <oscilloscope/qwtoscmain.h>

typedef int(* funca )(int);
int chSta = -1;
#define TBL_COL 4
#define TBL_ROW 20
#define MUL_SEL 2

#ifdef D_PTS
#define D_PTS 256
#endif

#ifdef PI
#define PI 3.1415927
#endif


CMDSimMW::CMDSimMW(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CMDSimMW) {

    SIG_LVDT    = new QString(cvcp936("LVDT"));
    SIG_AO      = new QString(cvcp936("AO"));
    _pSigMaper  = new QSignalMapper();           /* init sigmaper for all */
    connect(this, SIGNAL(msig_delIndex(QModelIndex&)), this, SLOT(m_delItem(QModelIndex&)));

    empty_model = new QStandardItemModel();
    ui->setupUi(this);


    initWidgetsPointer();

    initlistvChModel ();
    initdelsaveModel ();

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

    //LVDTCh *ptrLch = new LVDTCh(1, "lvdt_ch1");
    //initAOList();
    //initLchList();
    
    initInsView();

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


    mainPlotInit();
    //_pcbxCh->clear();
    //_pcbxCh->setModel(ach_model);
    _mainPlot = ui->qwtPlot;
    mainPlotInit();
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

#elif defined(Q_OS_DARWIN)
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





///* bind  to lch model listview Control */
///**
//  default to init lchlist and map clicked sig to Sigmapper
//  default to init lchlist with checkbox
//*/
void CMDSimMW::initlistvChModel () {

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
   // _plistvch->setEditTriggers (QAbstractItemView::NoEditTriggers);
   // _plistvch->setModel (lch_model);

    lch_model = new QStandardItemModel();
    ach_model = new QStandardItemModel();

    for(int i = 0; i < MAX_LVDT_CH; i++) {
        QStandardItem *p = new QStandardItem("");
        lch_model->appendRow (p);
    }
    for(int i = 0; i < MAX_AO_CH; i++) {
        QStandardItem *p = new QStandardItem("");
        ach_model->appendRow (p);
    }

#endif
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
        while(rechkItemSel(E_CHK, NULL,  dv_lv_model)) {
            for(int i = 0; i < dv_lv_model->rowCount(); i++) {
                if(dv_lv_model->item(i, 0)->checkState() == Qt::Checked) {
                    indx_ = dv_lv_model->index(i, 0);
                    emit(msig_delIndex(indx_));
                }
            }
        }
    } else if(_plistvsig->model() == dv_ao_model) {
        while(rechkItemSel(E_CHK, NULL, dv_ao_model)) {
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
    QString _sLVDT(cvcp936("LVDT"));
    QString _sAO(cvcp936("AO"));

    if(arg1.compare(_sLVDT, Qt::CaseInsensitive) == 0) {
        changeChListModelBind (E_LV_CH, E_CHK);
        resetModelChkStatus (dv_lv_model);
        _plistvsig->setModel(dv_lv_model);
    } else if(arg1.compare (_sAO, Qt::CaseInsensitive) == 0) {
        changeChListModelBind (E_AO_CH, E_CHK);
        resetModelChkStatus (dv_ao_model);
        _plistvsig->setModel(dv_ao_model);
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
    //extTools dig;
    //dig.exec ();
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
  信号确认按钮
*/
void CMDSimMW::on_btn_sigSel_ok_clicked() {
    //TODO get the sel result and put them input tbl !!!!

    QStringList lsigsel, lchsel, asigsel, achsel;
    if(_plistvsig->model () == dv_lv_model || _plistvch->model () == lch_model) {

        if(org_lch_list->length () <= 0) {
            return;
        }

        for(int i = 0; i < dv_lv_model->rowCount (); i++) {
            if(dv_lv_model->item (i, 0)->checkState () == Qt::Checked) {
                lsigsel << dv_lv_model->item (i, 0)->text ();
            }
        }
        //test the widget
        QString cls = _plistvch->indexWidget (lch_model->index (0, 0))->metaObject ()->className ();
        if(cls.compare (QString("QCheckBox")) == 0) {
            QCheckBox *pitem = NULL;
            for(int i = 0; i < lch_model->rowCount (); i++) {
                pitem = dynamic_cast <QCheckBox*> (_plistvch->indexWidget (lch_model->index (i, 0)));
                if(pitem == NULL)
                    continue;
                if(pitem->checkState () == Qt::Checked) {
                    lchsel << pitem->text ();
                }
            }

            //TODO to be test for
            
#if 0
            //TODO del rows
            while(rechkItemSel (E_CHK, NULL, lch_model)) {
                QCheckBox *_pchk = NULL;
                for(int i = 0; i < lch_model->rowCount (); i++) {
                    _pchk = dynamic_cast <QCheckBox*>(_plistvch->indexWidget (lch_model->index (i, 0)));
                    if(_pchk != NULL) {
                        if(_pchk->isCheckable () == Qt::Checked) {
                            lch_model->removeRow (i);
                        }
                    }
                }
            }
#endif

        } else if(cls.compare (QString("QRadioButton")) == 0) {
            QRadioButton *pitem = NULL;
            for(int i = 0; i < lch_model->rowCount (); i++) {
                pitem = dynamic_cast <QRadioButton*> (_plistvch->indexWidget (lch_model->index (i, 0)));
                if(pitem == NULL)
                    continue;
                if(pitem->isChecked () == true) {
                    lchsel << pitem->text ();
                }
            }
        }

    } else if (_plistvsig->model () == dv_ao_model || _plistvch->model () == ach_model){
        if(org_ach_list->length () <= 0) {
            return;
        }
        for(int i = 0; i < dv_ao_model->rowCount (); i++) {
            if(dv_ao_model->item (i, 0)->checkState () == Qt::Checked) {
                asigsel << dv_ao_model->item (i, 0)->text ();
            }
        }
        QString cls = _plistvch->indexWidget (ach_model->index (0, 0))->metaObject ()->className ();
        if(cls.compare (QString("QCheckBox")) == 0) {
            QCheckBox *pitem = NULL;
            for(int i = 0; i < ach_model->rowCount (); i++) {
                pitem = dynamic_cast <QCheckBox*> (_plistvch->indexWidget (ach_model->index (i, 0)));
                if(pitem->checkState () == Qt::Checked) {
                    achsel << pitem->text ();
                }
            }
        } else if(cls.compare (QString("QRadioButton")) == 0) {
            QRadioButton *pitem = NULL;
            for(int i = 0; i < ach_model->rowCount (); i++) {
                pitem = dynamic_cast <QRadioButton*> (_plistvch->indexWidget (ach_model->index (i, 0)));
                if(pitem->isChecked () == true) {
                    achsel << pitem->text ();
                }
            }
        }

    } else {
        return;
    }

#if 0
    qDebug () << lchsel <<"lch sel";
    qDebug () << achsel <<"ach sel";
    qDebug () << lsigsel <<"lsig sel";
    qDebug () << asigsel << "asig sel";
#endif

    //LVDT sig
    if(lsigsel.length () > 0 && lchsel.length () > 0) {

        findrmModelRow(dv_lv_model, lsigsel);

        //findrmModelRow(lch_model, lchsel);
        findrmRowWithWidget (lch_model, lchsel);
    }
    //AO sig
    if(asigsel.length () > 0 && achsel.length() > 0) {

        findrmModelRow(dv_ao_model, asigsel);
        //findrmModelRow(ach_model, achsel);
        findrmRowWithWidget (ach_model, achsel);
    }
}


void CMDSimMW::on_tmpdel_clicked() {
    return;
}

/* listw_sig_sel checkState  */
void CMDSimMW::on_listw_sig_sel_clicked(const QModelIndex &index) {
     QStandardItem *pf = NULL;
    if(_plistvsig->model() == dv_lv_model) {
        pf = dv_lv_model->itemFromIndex(index);
        QModelIndex pidx;
        if(lch_model->rowCount () > 0) {
            pidx = lch_model->index (0, 0);
        }else {
            QMessageBox::warning (this, "information", "ch empty!", QMessageBox::Yes);
            return;
        }
        QString precls =_plistvch->indexWidget (pidx)->metaObject ()->className ();
        if(chkItemSelMul (dv_lv_model) >= MUL_SEL) {
            if(precls.compare (QString("QCheckBox")) == 0) {
                changeChListModelBind (E_LV_CH, E_RADIO);
            }
        } else {
            if(precls.compare(QString("QRadioButton")) == 0) {
                changeChListModelBind (E_LV_CH, E_CHK);
            }
        }
    } else if(_plistvsig->model() == dv_ao_model) {
        pf = dv_ao_model->itemFromIndex(index);
        QModelIndex pidx ;
        if(ach_model->rowCount () > 0) {
            pidx = ach_model->index (0, 0);
        } else {
            QMessageBox::warning (this, "information", "ch empty!", QMessageBox::Yes);
            return;
        }
        QString precls =_plistvch->indexWidget (pidx)->metaObject ()->className ();
        if(chkItemSelMul (dv_ao_model) >= MUL_SEL) {
            if(precls.compare (QString("QCheckBox")) == 0) {
                changeChListModelBind (E_AO_CH, E_RADIO);
            }
        } else {
            if(precls.compare (QString("QRadioButton")) == 0) {
                changeChListModelBind (E_AO_CH, E_CHK);
            }
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
int CMDSimMW::rechkItemSel(int type, QWidget *widget, QStandardItemModel *model) {

    if(type == E_CHK) {
        int tmp = model->rowCount();
        for(int i = 0; i < tmp; i++) {
            if(model->item(i)->checkState() == Qt::Checked){
                return 1;
            }
        }
    } else if(type == E_RADIO && widget != NULL) {
        QListView *pid = NULL;
        pid = dynamic_cast <QListView*>(widget);
        QRadioButton *pradio = NULL;
        if(pid != NULL) {
            int tmp = model->rowCount ();
            for(int i = 0; i < tmp; i++) {
                pradio = dynamic_cast <QRadioButton*> (pid->indexWidget (model->index (i, 0)));
                if(pradio != NULL) {
                    if(pradio->isCheckable () == true)
                        return 1;
                }
            }
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
#if 0
    QMenu *con = new QMenu(this);
    con->addAction ("delte");
    con->exec ();
#endif
}

void CMDSimMW::on_tbl_selres_pressed(const QModelIndex &index) {
    QStandardItem *p = tbl_model->itemFromIndex(index);
    qDebug() << "press" << p->text() ;
}

void CMDSimMW::mslot_tableClick(int row) {
    QMessageBox::warning (this, "run", QString::number (row, 10), QMessageBox::Yes);
}



/* list of chs clicked function */
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
    str = "";
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

void CMDSimMW::mslot_tblContextMenu(QAction *action) {
    QVariant var =action->data ();
    QPoint pp = var.toPoint ();

    QModelIndex idx = _ptbl->indexAt (pp);
    QStandardItem *item = tbl_model->itemFromIndex (idx);
    qbshow (item->text ());
}

void CMDSimMW::on_cbx_sigts_activated(int index) {

    index = 0;
    index += 0;
}


void CMDSimMW::on_tbl_selres_customContextMenuRequested(const QPoint &pos) {
    //TODO 过滤右键菜单坐标，不是每次都弹出
#if 0
    QRect rect = _ptbl->geometry ();
    int top = rect.top ();
    int right = rect.right ();
    int left = rect.left ();
    left += _ptbl->columnWidth (0);
    left += _ptbl->columnWidth (1);
    left += _ptbl->columnWidth (2);
#endif

    QRect rect = _ptbl->contentsRect ();
    if(pos.x () >= rect.left () && pos.x () <= rect.right ()) {
        if(pos.y () >= rect.top () && pos.y () <= rect.bottom ()) {
            QMenu *con = new QMenu(ui->tbl_selres);
            qDebug () << pos.x () << pos.y () <<" the pos::";
            qDebug () << QCursor::pos ().x(), QCursor::pos ().y();
            //QAction *paction = new QAction(cvcp936 ("删除通道"));
            QAction *paction =  con->addAction (cvcp936 ("删除通道"));
            paction->setData (pos);
            connect (con, SIGNAL(triggered(QAction*)), this, SLOT(mslot_tblContextMenu(QAction*)));
            con->exec (QCursor::pos ());
        }
    }

}

/*
 *show wave
  */
void CMDSimMW::on_btnViewOsc_clicked() {

#if 1
    window = new QwtOSCMain();
    window->setAttribute (Qt::WA_DeleteOnClose);

    window->resize( 800, 400 );
    window->clearData ();

    window->samplingThread = new SamplingThread();

    window->samplingThread->setFrequency( window->frequency() );
    window->samplingThread->setAmplitude( window->amplitude() );
    window->samplingThread->setInterval( window->signalInterval() );

    window->connect( window, SIGNAL( frequencyChanged( double ) ),
            window->samplingThread, SLOT( setFrequency( double ) ) );
    window->connect( window, SIGNAL( amplitudeChanged( double ) ),
            window->samplingThread, SLOT( setAmplitude( double ) ) );
    window->connect( window, SIGNAL( signalIntervalChanged( double ) ),
            window->samplingThread, SLOT( setInterval( double ) ) );

    window->show ();
    window->samplingThread->start();
    window->start();
#endif
}


/* pushInStrList for stringlist*/
bool CMDSimMW::pushInStrList(QStringList *list, QString elem) {
    if(list == NULL)
        return false;
    if(list->length() >= 0) {
        list->append(elem);
        //list->sort();
        return true;
    }
    return false;
}


/* removeStrList for stringlist */
bool CMDSimMW::removeStrList(QStringList *list, QString elem) {
    if(list == NULL)
        return false;
    if(list->length() > 0) {
        for(;;) {
            if(list->removeOne(elem) == false) {
                break;
            }
        }
        //list->sort();
        return true;
    }
    return false;
}

void CMDSimMW::mainPlotInit() {
    if(_mainPlot != NULL && _mainCurve != NULL) {
        _mainPlot->setAutoDelete (true);
        _mainPlot->setAxisScale(QwtPlot::xBottom, 0, 10.0);
        _mainPlot->setAxisScale(QwtPlot::yLeft, -10.0, 10.0);
        _mainGrid = new QwtPlotGrid();
        _mainGrid->enableXMin (true);
        _mainGrid->setMajorPen( Qt::white, 0, Qt::DotLine );
        _mainGrid->setMinorPen( Qt::gray, 0 , Qt::DotLine );
        if(_mainPlot != NULL) {
            _mainGrid->attach (_mainPlot);
        }

        _mainPlot->setCanvasBackground (QColor(0, 49, 114));
    }
}

//工具action
void CMDSimMW::on_action_tools_triggered() {
    extTools dlg;
    dlg.exec ();
}

void CMDSimMW::on_cbxCtl_clicked() {
    if (ui->cbxCtl->isChecked () == true) {
        //外部
        //禁用不必要的控件,table设置等,只留出反射内存接口
        //调用反射内存接口
    } else {
        //内部
    }
}


void CMDSimMW::on_action_rfm_triggered() {
    DlgRFMDebug rfm;
    rfm.exec();

}
