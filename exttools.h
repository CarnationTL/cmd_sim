#ifndef EXTTOOLS_H
#define EXTTOOLS_H

#include <QDialog>
#include <QMessageBox>
#include <QPushButton>
#include <qwt_plot.h>
#include <QFile>
#include <QString>
#include <QStringList>
#include <QFileDialog>
#include <QDir>
#include <Qwt/qwt_plot_curve.h>
#include <Qwt/qwt_point_data.h>
#include <Qwt/qwt_series_data.h>
#include <Qwt/qwt_plot.h>
#include <Qwt/qwt_symbol.h>
#include <Qwt/qwt_plot_marker.h>
#include <Qwt/qwt_painter.h>
#include <Qwt/qwt_plot_grid.h>
#include <QListWidgetItem>
#include <QButtonGroup>
#include "sigGen/curvedatan.h"
#include "sigGen/sawdata.h"
#include "sigGen/sinusdata.h"
#include "sigGen/squdata.h"
#include "sigGen/tridata.h"

#ifdef PI
#define PI 3.1415927
#endif

#ifdef D_PTS
#define D_PTS 256
#endif


namespace Ui {
class extTools;
}

class extTools : public QDialog
{
    Q_OBJECT
    
public:
    explicit extTools(QWidget *parent = 0);
    ~extTools();

private slots:

    void on_btnGenWData_clicked();

    void on_btnClose_clicked();

    void on_rbSin_clicked();

    void on_rbSquare_clicked();

    void on_rbSaw_clicked();

    void on_rbTri_clicked();

    void on_rbCus_clicked();

    void on_sbAMP_valueChanged(double arg1);

    void on_sbTIME_valueChanged(double arg1);

    void on_sbDUTY_valueChanged(double arg1);

    void on_btnLoad_clicked();

    void on_sbstartTime_valueChanged(double arg1);

    void on_sbEndTime_valueChanged(double arg1);

    void on_sbStartY_valueChanged(double arg1);

    void on_sbEndY_valueChanged(double arg1);

    void on_btnConfirmSeg_clicked();

    void on_lswcurv_itemClicked(QListWidgetItem *item);

    void on_btncurDel_clicked();

    void on_ckbloop_clicked();

    void on_rbvoltage_clicked();

    void on_rbphy_clicked();

    void on_spVoltage_valueChanged(double arg1);

    void on_spphysic_valueChanged(double arg1);






private:
    Ui::extTools *ui;
    int _dcnt;
    enum {SINE, SAW, TRI, SQU, CUS };
    enum {VOL, PHY};
    int _type;
    void toggleDutycHide(bool f);
    QwtPlot *plot;
    QwtPlotCurve *pc;
    void doPlot(int t);
    void doPlot(QStringList strdata);
    void doPlotCus();

    double _amp;
    double _time;
    double _dutyc;
    void readSetting(QString fn);
    void setrbCheck(int t);
    void setTimeSp(double time);

    QString consSdata(QString x, QString y);
    QStringList deconsSdata(QString xy);
    CurveDataN *_pcurve;
    QwtSymbol _sym;
//    QwtPlotMarker *_hmarker;
//    void markerinit();
    QwtPlotGrid *grid;
    void gridinit();
    double _lasttime;
    QwtPlotMarker sm;
    QwtPlotMarker em;
    void initSwitchPara(bool flag);
    void switchWvRbs(int type, bool flag);
    bool _loop;
    QString _vpstr;
    double vpfactor;
    double pvfactor;
    bool vpflag;    //voltage = true

    int getvpSet();
    void vpSet(int t);
    double phyfac;
    double volfac;
    void changePRgn(double v);

    QButtonGroup gpvp;

};

#endif // EXTTOOLS_H
