#ifndef DLGLCHSET_H
#define DLGLCHSET_H

#include <QDialog>
#include <Qwt/qwt_plot.h>
#include <Qwt/qwt_plot_curve.h>
#include <Qwt/qwt_plot_grid.h>

#include <sigGen/sinusdata.h>
#include <sigGen/tridata.h>
#include <sigGen/sawdata.h>
#include <sigGen/squdata.h>
#include <sigGen/curvedatan.h>
#include <QModelIndex>
#include <QListWidgetItem>
#include <Qwt/qwt_plot_marker.h>

namespace Ui {
class DlgLchSet;
}

class DlgLchSet : public QDialog
{
    Q_OBJECT
    
public:

    explicit DlgLchSet(QWidget *parent = 0);
    ~DlgLchSet();
    
private slots:
    void on_sbAMP_Sine_valueChanged(double arg1);

    void on_sbTIME_Sine_valueChanged(double arg1);

    void on_sbAMP_Tri_valueChanged(double arg1);

    void on_sbTIME_Tri_valueChanged(double arg1);

    void on_rbloo_Sine_clicked();

    void on_rbclyle_Sine_clicked();

    void on_spcycle_Sine_valueChanged(int arg1);

    void on_rbloo_Tri_clicked();

    void on_rbclyle_Tri_clicked();

    void on_spcycle_Tri_valueChanged(int arg1);

    void on_sbAMP_Saw_valueChanged(double arg1);

    void on_sbTIME_Saw_valueChanged(double arg1);

    void on_rbloo_Saw_clicked();

    void on_rbclyle_Saw_clicked();

    void on_spcycle_Saw_valueChanged(int arg1);

    void on_sbAMP_Squ_valueChanged(double arg1);

    void on_sbTIME_Squ_valueChanged(double arg1);

    void on_sbDUTY_Squ_valueChanged(double arg1);

    void on_rbloo_Squ_clicked();

    void on_rbclyle_Squ_clicked();

    void on_spcycle_Squ_valueChanged(int arg1);

    void on_sbstartTime_valueChanged(double arg1);

    void on_sbEndTime_valueChanged(double arg1);

    void on_sbStartY_valueChanged(double arg1);

    void on_sbEndY_valueChanged(double arg1);

    void on_btnConfirmSeg_clicked();

    void on_lswcurv_clicked(const QModelIndex &index);

    void on_cbloop_Cur_clicked();

    void on_btncurDel_clicked();

    void on_lswcurv_itemClicked(QListWidgetItem *item);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::DlgLchSet *ui;
    QString genChInfo(QStringList chlst, QStringList namelist);
    void plotInit();
    void initpointers();
    QwtPlot *plot;
    QwtPlotGrid *grid;
    QwtPlotCurve *pc;

    QwtPlotMarker sm;
    QwtPlotMarker em;

    CurveDataN *_pcurve;
    void doPlot(int);
    void doPlotCus();
    void cycleandloop();
private:
    enum {SINE, SAW, TRI, SQU, CUS };
    enum {VOL, PHY};

    double _amp;
    double _dutyc;
    double _time;
    double _lasttime;
    int _cycles;
};

#endif // DLGLCHSET_H
