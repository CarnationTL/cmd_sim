#ifndef CMDSIMMW_H
#define CMDSIMMW_H

#include <QMainWindow>
#include <QString>
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

namespace Ui {
class CMDSimMW;
}

class CMDSimMW : public QMainWindow {
    Q_OBJECT
    
public:
    explicit CMDSimMW(QWidget *parent = 0);
    ~CMDSimMW();
    int initInstructs();
    void qbshow(QString str);

private slots:
    void on_actionSetBrd_triggered();

    void on_bbx_sig_sel_accepted();

    void on_bbx_sig_sel_rejected();

    void on_cbx_sigts_currentIndexChanged(const QString &arg1);

    void on_commandLinkButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_btn_setwp_clicked();

	void myBtnSlot();


    void on_pushButton_4_clicked();

    void on_btn_sigSel_ok_clicked();            /* sigsel ok */

//    void on_sigLv_clickEd(const QModelIndex &index);

    void on_listw_sig_sel_clicked(const QModelIndex &index);

    void on_listw_sig_sel_entered(const QModelIndex &index);

private:
    enum {LVDTBrds = 4};
    QString *SIG_LVDT;
    QString *SIG_AO;
    enum {T_L, T_A};
    Ui::CMDSimMW *ui;
    int initrfm(void);
    int init75c3(void);

    QStringList *ps_ins_v;
    QStandardItemModel *dv_model;
    QStandardItemModel *lch_model;
    QStandardItemModel *ach_model;
    QStandardItemModel *rlch_model;
    QStandardItemModel *rach_model;
    QStandardItemModel *tbl_model;
    QString cvcp936(const char str[]);
    void initInsView();
    void initSeachLE();
    void initHWSel();
    void initCHModel();
    QDialog *_pdlg;
    QGridLayout *_pMainLay;                     
    QGridLayout *_pLeftLay;
    QLineEdit *_pSeachEdit;                     /* sreach edit for signal name*/
    QLineEdit *_pNewSigEdit;                    /* new  sig edit*/
    QCompleter *_pCompleter;                    /* auto complete */
    QComboBox *_pcbxSigSel;                     /* select sig */
    QComboBox *_pcbxCh;                         /* select channel */
    QTableView *_ptbl;                          /* show set result */
    QDialog *_pqwtdlg;
    QPlainTextEdit *_ppl;                       /* show status */
    QListView *_plistvsig;                      /* the list view for sigsel */
    void initLchList();                         
    void initAOList();
    void initTbl();                             /* init result table for set  */

    int warningTextInfo(QPlainTextEdit &p);
    int showWarning();
    void initoptLog();
    bool switchtoRmodel(QStandardItem *item, int type);
    bool switchtoUmodel(QStandardItem *item, int type);

	void addtionSetUi();
    void addtionSigSlotsMVC();
    void appendtxtStatus(QString &str);         /* append status plainEdit ctl */
    void initWidgetsPointer();                  /* init widget pointer */
};

#endif // CMDSIMMW_H
