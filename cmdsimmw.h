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
namespace Ui {
class CMDSimMW;
}

class CMDSimMW : public QMainWindow
{
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

    void on_pushButton_clicked();

    void on_commandLinkButton_clicked();

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
    QLineEdit *_pSeachEdit;
    QCompleter *_pCompleter;
    QComboBox *_pcbxSigSel;
    QComboBox *_pcbxCh;
    QTableView *_ptbl;
    QDialog *_pqwtdlg;

    void initLchList();
    void initAOList();
    void initTbl();

    bool switchtoRmodel(QStandardItem *item, int type);
    bool switchtoUmodel(QStandardItem *item, int type);
};

#endif // CMDSIMMW_H
