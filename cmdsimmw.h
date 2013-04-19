#ifndef CMDSIMMW_H
#define CMDSIMMW_H

#include <QMainWindow>
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
private slots:
    void on_actionSetBrd_triggered();

    void on_bbx_sig_sel_accepted();

    void on_bbx_sig_sel_rejected();

    void on_cbx_sigts_currentIndexChanged(const QString &arg1);

private:
    enum {LVDTBrds = 4};
    Ui::CMDSimMW *ui;
    int initrfm(void);
    int init75c3(void);

    QStringList *ps_ins_v;
    QStandardItemModel *dv_model;
    QStandardItemModel *lch_model;
    QStandardItemModel *ach_model;
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
};

#endif // CMDSIMMW_H
