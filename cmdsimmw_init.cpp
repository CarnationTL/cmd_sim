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


#define TBL_COL 4
#define TBL_ROW 20
#define MUL_SEL 2



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
  diff type with diff models
*/

void CMDSimMW::initCHModel() {
    QString _tmpStr;
    QString _sLVDT(cvcp936("LVDT"));
    QString _sAO(cvcp936("AO"));
    //_pcbxCh = ui->cbx_ch;
    if(_pcbxSigSel != NULL) {
        _tmpStr = _pcbxSigSel->currentText();
        if(_tmpStr.compare(_sLVDT, Qt::CaseInsensitive) == 0) {
            //bind model
            if(lch_model != NULL) {
                _plistvsig->setModel(dv_lv_model);
                _plistvch->setModel (lch_model);
                for(int i = 0; i < lch_model->rowCount (); i++) {
                    _plistvch->setIndexWidget (lch_model->index (i, 0),
                                new QCheckBox(cvcp936 ("LVDT") + QString::number (i)));
                }

            }
        } else if(_tmpStr.compare(_sAO, Qt::CaseInsensitive) == 0) {
            //bind model
            if(ach_model != NULL) {
                _plistvsig->setModel(dv_ao_model);
                _plistvch->setModel (ach_model);
                for(int i = 0; i < ach_model->rowCount (); i++) {
                    _plistvch->setIndexWidget (ach_model->index (i, 0),
                                new QCheckBox(cvcp936 ("AO") + QString::number (i)));
                }
            }
        }
    }
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
        return -1;

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
        return -1;

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



/**
  init Qtextbrowser and QPlainTextEdit
*/
void CMDSimMW::initoptLog() {

    //_ppl = ui->pploptStatus;
    QPalette pal;
    pal.setColor(QPalette::WindowText, Qt::blue);
    pal.setColor(QPalette::Text, Qt::blue);
    pal.setColor(QPalette::Active, QPalette::Base, Qt::white);
    pal.setColor(QPalette::Inactive, QPalette::Base, Qt::white);
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

/**
 init tbl and table model and attch to tableview
*/
void CMDSimMW::initTbl() {
    //set table sytle
    if(_ptbl == NULL) {
        return;
    }
    QPushButton *tbtn;
    tbl_model = new QStandardItemModel(TBL_ROW, TBL_COL);
    _ptbl->setModel(tbl_model);

    tbl_model->setHeaderData(0, Qt::Horizontal, cvcp936("类型"));
    tbl_model->setHeaderData(1, Qt::Horizontal, cvcp936("名称"));
    tbl_model->setHeaderData(2, Qt::Horizontal, cvcp936("关联通道号"));
    tbl_model->setHeaderData(3, Qt::Horizontal, cvcp936("设置"));

    _ptbl->setEditTriggers (QAbstractItemView::NoEditTriggers);
    QHeaderView *header = new QHeaderView(Qt::Horizontal, _ptbl);
    header->setMovable (true);                  /* move cols */
    _ptbl->setHorizontalHeader (header);
    //_ptbl->horizontalHeader ()->setStretchLastSection ();
    int trow = tbl_model->rowCount() ,tcol = tbl_model->columnCount();
    for(int i = 0; i < trow; i++) {
        for(int j = 0; j < tcol; j++) {
            QModelIndex idx = tbl_model->index(i, j);
            //test the first col...
            if(j == tcol - 1) {
                tbl_model->setData(idx, "btncol");
                tbtn = new QPushButton(cvcp936 ("设置"));
                _ptbl->setIndexWidget(tbl_model->index(i, j), tbtn);
                connect (tbtn, SIGNAL(clicked()), _pSigMaper, SLOT(map()));
                _pSigMaper->setMapping (tbtn, i + 1); /* row start 0 */
            } else {
                tbl_model->setData(idx, "test");
            }
        }
    }
    connect (_pSigMaper, SIGNAL(mapped(int)), this, SLOT(mslot_tableClick(int)));
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

/* init pointers of main Widget.. */
void CMDSimMW::initWidgetsPointer() {

    _pMainLay = NULL;
    _pLeftLay = NULL;
    _pLeftLay = NULL;
    _pCompleter = NULL;
    _pcbxSigSel = NULL;
    _ptbl = NULL;
    _psetwpdlg = NULL;
    _ppl = NULL;
    _ptbl = NULL;
    _pbtnBoxSigSel = NULL;

    _pbtnBoxSigSel = ui->bbx_sig_sel;

    _pSeachEdit = ui->edit_search;
    _plistvsig = ui->listw_sig_sel;
    _plistvch = ui->listv_ch;
    _pNewSigEdit = ui->edit_newSig;
    _ppl = ui->pploptStatus;
    _pcbxSigSel = ui->cbx_sigts;
    _ptbl = ui->tbl_selres;
    _psetwpdlg = new SetWPDlg();
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




void CMDSimMW::initcbxsigts() {
    _pcbxSigSel->insertItem (0, cvcp936 ("LVDT"));
    _pcbxSigSel->insertItem (1, cvcp936 ("AO"));



}


/* change the model bind ctl */
bool CMDSimMW::changeChListModelBind(int type, int ctl_type) {

    if(_plistvch == NULL) {
        return false;
    }
    if(type == E_LV_CH) {
        int len = lch_model->rowCount ();
        _plistvch->setModel (lch_model);
        if(ctl_type == E_CHK) {
            for (int i = 0; i < len; ++i) {
                //_plistvch->setIndexWidget (lch_model->index (i, 0), _lslvchk.at (i));
                _plistvch->setIndexWidget (lch_model->index (i, 0),
                        new QCheckBox(cvcp936 ("LVDT") + QString::number (i)));
            }
            return true;
        } else if(ctl_type == E_RADIO) {
            for (int i = 0; i < len; ++i) {
                //_plistvch->setIndexWidget (lch_model->index (i, 0), _lslvradio.at (i));
                _plistvch->setIndexWidget (lch_model->index (i, 0),
                        new QRadioButton(cvcp936 ("LVDT") + QString::number (i)));
            }
            return true;
        }
    } else if(type == E_AO_CH) {
        int len = ach_model->rowCount ();
        _plistvch->setModel (ach_model);
        if(ctl_type == E_CHK) {
            for (int i = 0; i < len; ++i) {
                //_plistvch->setIndexWidget (ach_model->index (i, 0), _lsaochk.at (i));
                _plistvch->setIndexWidget (ach_model->index (i, 0), 
                        new QCheckBox(cvcp936("AO") + QString::number(i)));
            }
            return true;
        } else if(ctl_type == E_RADIO) {
            for (int i = 0; i < len; ++i) {
                //_plistvch->setIndexWidget (ach_model->index (i, 0), _lsaoradio.at (i));
                _plistvch->setIndexWidget (ach_model->index (i, 0), 
                        new QRadioButton(cvcp936("AO") + QString::number(i)));
            }
            return true;
        }
    }
    return false;
}