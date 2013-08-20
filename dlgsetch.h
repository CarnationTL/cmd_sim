#ifndef DLGSETCH_H
#define DLGSETCH_H

#include <QDialog>
#include <QModelIndex>
#include <QTableWidget>

namespace Ui {
class DlgSetCh;
}









class DlgSetCh : public QDialog
{
    Q_OBJECT
    
public:
    explicit DlgSetCh(QWidget *parent = 0);
    ~DlgSetCh();
    
private slots:
    void on_rbCus_clicked();

    void on_rbTri_clicked();

    void on_rbSaw_clicked();

    void on_rbSquare_clicked();

    void on_rbSin_clicked();

    void on_sbAMP_valueChanged(double arg1);

    void on_sbTIME_valueChanged(double arg1);

    void on_sbDUTY_valueChanged(double arg1);

    void on_sbstartTime_valueChanged(double arg1);

    void on_sbStartY_valueChanged(double arg1);

    void on_sbEndTime_valueChanged(double arg1);

    void on_sbEndY_valueChanged(double arg1);

    void on_btnConfirmSeg_clicked();

    void on_lswcurv_clicked(const QModelIndex &index);

    void on_btncurDel_clicked();

    void on_ckbloop_clicked();

private:
    Ui::DlgSetCh *ui;
    QTableWidget *table;
    void initTblchInfo();
};

#endif // DLGSETCH_H
