﻿#ifndef CMDSIMMW_H
#define CMDSIMMW_H

#include <QMainWindow>
#include <QString>
#include <QList>
#include <QStringList>
#include <QListView>
#include <QStandardItemModel>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QDialog>
#include <QComboBox>
#include <QTableView>
#include <QPlainTextEdit>
#include <QDialogButtonBox>
#include <QSignalMapper>
#include <QRadioButton>
#include <QCheckBox>
#include <QMap>
#include <oscilloscope/qwtoscmain.h>
#include <oscilloscope/samplingthread.h>
#include <Qwt/qwt_plot.h>
#include <Qwt/qwt_plot_curve.h>
#include <Qwt/qwt_plot_grid.h>
#include <lvdtch.h>

namespace Ui {
class CMDSimMW;
}

class CMDSimMW : public QMainWindow {
    Q_OBJECT
    
public:
    explicit CMDSimMW(QWidget *parent = 0);
    ~CMDSimMW();
    int initLvInstructs();
    int initAoInstructs();
    void qbshow(QString str);

signals:
    int msig_delIndex(QModelIndex &index);
private slots:
    void on_actionSetBrd_triggered();

    void on_bbx_sig_sel_accepted();

    void on_bbx_sig_sel_rejected();

    void on_cbx_sigts_currentIndexChanged(const QString &arg1);

    void on_btn_setwp_clicked();

	void myBtnSlot();


    void on_pushButton_4_clicked();

    void on_btn_sigSel_ok_clicked();            /* sigsel ok */

    void on_listw_sig_sel_clicked(const QModelIndex &index); /* sig list view*/

    void m_delItem(QModelIndex &index);

    void on_action_reset_sigDis_triggered();

    void on_listw_sig_sel_pressed(const QModelIndex &index);

    void on_action_reset_SigAO_triggered();

    void on_tbl_selres_activated(const QModelIndex &index);

    void on_tbl_selres_clicked(const QModelIndex &index);

    void on_tbl_selres_pressed(const QModelIndex &index);

    void mslot_tableClick(int row);
    void mslot_CHradioClick(QString str);
    void mslot_CHcheckClick(QString str);
    void mslot_tblContextMenu(QAction* action);
    void on_listv_ch_clicked(const QModelIndex &index);

    void on_cbx_sigts_activated(int index);

    void on_tbl_selres_customContextMenuRequested(const QPoint &pos);

    void on_btnViewOsc_clicked();

    void on_tmpdel_clicked();

    void on_action_tools_triggered();

    void on_cbxCtl_clicked();

    void on_action_rfm_triggered();

    void on_btnStart_clicked();

    void on_btnStop_clicked();

private:
    enum {LVDTBrds = 4};
    enum {E_DV_LV_MODEL, E_DV_AO_MODEL};
    enum {E_LV_CH, E_AO_CH, E_CHK, E_RADIO};
    QString *SIG_LVDT;
    QString *SIG_AO;
    enum {T_L, T_A};
    Ui::CMDSimMW *ui;
    int initrfm(void);
    int init75c3(void);

    QStringList *ps_ins_v;
    QStringList *ps_ao_ins_v;
    QStandardItemModel *org_dv_lv_model;        /* the copy of dv_lv_model */
    QStandardItemModel *dv_lv_model;

    QStandardItemModel *org_dv_ao_model;        /* the copy of dv_ao_model */
    QStandardItemModel *dv_ao_model;

    QStandardItemModel *lch_model;              /* the lch list model */
    QStandardItemModel *ach_model;              /* the ach list model */

    QStandardItemModel *rlch_model;             
    QStandardItemModel *rach_model;

    QStandardItemModel *tbl_model;              /* the set table model */
    QStandardItemModel *empty_model;


    QStringList *del_ch_list;
    QStringList *del_sig_list;
    QStringList *org_lch_list;
    QStringList *org_ach_list;

    QDialog     *_pdlg;

    QDialog     *_psetwpdlg;
    QDialog     *_psetChdlg;
//    QGridLayout *_pMainLay;
    QGridLayout *_pLeftLay;
    QLineEdit   *_pSeachEdit;              /* sreach edit for signal name*/
    QLineEdit   *_pNewSigEdit;             /* new  sig edit*/
    QCompleter  *_pCompleter;              /* auto complete */
    QComboBox   *_pcbxSigSel;              /* select sig */
    //QComboBox *_pcbxCh;                   /* select channel */
    QTableView *_ptbl;                     /* show set result */

    QPlainTextEdit *_ppl;                       /* show status */
    QListView *_plistvsig;                      /* the list view for sigsel */
    QListView *_plistvch;                       /* the list view for chs */
    QDialogButtonBox *_pbtnBoxSigSel;           /* button box for sig accept and 
                                                   reject(delete) */
    QSignalMapper *_pSigMaper;

    QString cvcp936(const char str[]);

    void initInsView();
    void initSeachLE();
    void initCHModel();

    void initlistvChModel();

    void initcbxsigts();
    void initTbl();                             /* init result table for set  */
    void initLvsigNameModel(int cnt);
    void initAOsigNameModel(int cnt);
    void initdelsaveModel();
    void addtblRow(const QList <QStandardItem *> &item);
    void deltblRow(int row);

    int  warningTextInfo(QPlainTextEdit &p);
    int  showWarning();
    void initoptLog();
    void initTblConTextMenu();

	void addtionSetUi();
    void addtionSigSlotsMVC();
    void appendtxtStatus(QString &str);         /* append status plainEdit ctl */
    void initWidgetsPointer();                  /* init widget pointer */
    int  addItemToModel(QStandardItemModel* model, QString &newItem);
    int  delItemFromModel(QStandardItemModel* model);
    int  rechkItemSel(int type, QWidget *p, QStandardItemModel* model);
    int  checkListSigSel(int type);                      /* multi check */
    int  changeRCstyle(int type);
    int  chkItemSelMul(QStandardItemModel* model);

    bool changeChListModelBind(int type, int ctl_type);
    int  rmModelCheck(QStandardItemModel *p);
    bool resetModelChkStatus(QStandardItemModel *p);
    bool findrmModelRow(QStandardItemModel *model, QStringList list);
    bool findrmRowWithWidget(QStandardItemModel *model, QStringList list);
    bool pushInStrList(QStringList *list, QString elem);
    bool removeStrList(QStringList *list, QString elem);

    void mainPlotInit();
    QwtPlot *_mainPlot;
    QwtPlotCurve *_mainCurve;
    QwtPlotGrid *_mainGrid;

    QwtOSCMain *window;

    QList <int> lvChSList;
    QList <int> getLvChStartlist();
    QList <LVDTCh *> LCHs;

};

#endif // CMDSIMMW_H
