#include "setwpdlg.h"
#include "ui_setwpdlg.h"
#include <QMessageBox>
#include <qwt_dial_needle.h>
#include <qwt_plot_curve.h>
#include <qwt_point_data.h>
#include <qwt_series_data.h>


class SinusDataT: public QwtSyntheticPointData
{
public:
    SinusDataT():
        QwtSyntheticPointData( 100 )
    {
    }
    virtual double y ( double x ) const
    {
        return qSin( x );
    }
};


SetWPDlg::SetWPDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetWPDlg)
{
    ui->setupUi(this);
    //set dail style
    setdialstyle(ui->dial);
}

/**
  distruct...
*/
SetWPDlg::~SetWPDlg()
{
    delete ui;
}

/**

*/
void SetWPDlg::on_pb_test_clicked() {
    QMessageBox::warning(this, "fdsafdas", "fdsafdsa", QMessageBox::Yes);
}

void SetWPDlg::on_knob_sliderMoved(double value) {
#if 0
    QwtKnob *p = ui->knob;
    QwtTextLabel *l = ui->TextLabel;
    if(p != NULL && l != NULL) {
        QwtText txt;
        txt = QString::number(value);
        l->setText(txt);
        p->setValue(value);
    } else {
        QMessageBox::warning(this, "fsadsa", "fdsfsda", QMessageBox::Yes);
    }
#endif
}

/**
 * set the dial style
**/
void SetWPDlg::setdialstyle(QwtDial *p) {
    p->setTracking(true);
    p->setScaleArc(0, 360);
    p->setScale(-145, 105);
    p->setTotalSteps(200);
    p->setWrapping(false);
    p->setOrigin(100);
    QwtDialSimpleNeedle * nd = new QwtDialSimpleNeedle(QwtDialSimpleNeedle::Arrow);
    p->setScaleMaxMajor(14);
    p->setNeedle(nd);
	p->geometry();
}

void SetWPDlg::on_pb_test2_clicked() {

	QwtDial *p = ui->dial;
	p->setValue(10.0);
	QwtKnob *k = ui->knob;
	k->setValue(10.0);

	QwtPlot *pp = ui->qwtPlot;
    pp->setAxisScale(QwtPlot::xBottom, 0.0, 10.0);
    pp->setAxisScale(QwtPlot::yLeft, -1.0, 1.0);

    pp->setTitle("fsdafdafdafdaadsf");

	QwtPlotCurve *c = new QwtPlotCurve("curve1");
    c->setRenderHint(QwtPlotItem::RenderAntialiased);
    c->setPen(QPen(Qt::red));
    c->setData(new SinusDataT());
    c->attach(pp);
    pp->show();

}
