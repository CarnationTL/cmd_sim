#include "dlglchset.h"
#include "ui_dlglchset.h"
#include <Qwt/qwt_symbol.h>
#include <QListWidget>


bool firstFlagW = false;

DlgLchSet::DlgLchSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgLchSet)
{
    ui->setupUi(this);


    initpointers();
    plotInit();
    cycleandloop();
}

DlgLchSet::~DlgLchSet()
{
    delete ui;
}

//ch info
QString DlgLchSet::genChInfo(QStringList chlst, QStringList namelist) {

    QString retstr;
    if(chlst.length() > 0 && namelist.length() > 0) {
        int chlen = chlst.length();
        int nlen = namelist.length();
        retstr = QString("CHs: ");
        for(int i = 0; i < chlen; i++) {
            retstr += chlst.at(i) + QString(" | ");
        }
        retstr += QString("\n");
        retstr += QString("CH_INFO: ");
        for(int j = 0; j < nlen; j++) {
            retstr += namelist.at(j) + QString(" | ");
        }
        retstr += QString("\n");
    }
    return retstr;
}

void DlgLchSet::plotInit() {

    plot->setAutoDelete (true);
    plot->setAxisScale(QwtPlot::xBottom, 0, 10.0);
    plot->setAxisScale(QwtPlot::yLeft, -10.0, 10.0);
    grid = new QwtPlotGrid();
    grid->enableXMin (true);
    grid->setMajorPen( Qt::white, 0, Qt::DotLine );
    grid->setMinorPen( Qt::gray, 0 , Qt::DotLine );
    if(plot != NULL) {
            grid->attach (plot);
    }

    plot->setCanvasBackground (QColor(0, 49, 114));
    pc = NULL;

    _pcurve = new CurveDataN(D_PTS);
}

void DlgLchSet::initpointers() {
    plot = ui->plotWhole;
}

void DlgLchSet::cycleandloop() {

    ui->rbclyle_Saw->setChecked(true);
    ui->rbclyle_Sine->setChecked(true);
    ui->rbclyle_Squ->setChecked(true);
    ui->rbclyle_Tri->setChecked(true);

    ui->spcycle_Sine->setValue(1);
    ui->spcycle_Tri->setValue(1);
    ui->spcycle_Saw->setValue(1);
    ui->spcycle_Squ->setValue(1);
}

void DlgLchSet::on_sbAMP_Sine_valueChanged(double arg1) {
    _amp = arg1;
    doPlot(SINE);
}

void DlgLchSet::on_sbTIME_Sine_valueChanged(double arg1) {
    _time = arg1;
    doPlot(SINE);
}

void DlgLchSet::on_sbAMP_Tri_valueChanged(double arg1) {
    _amp = arg1;
    doPlot(TRI);
}


void DlgLchSet::on_sbTIME_Tri_valueChanged(double arg1) {
    _time = arg1;
    doPlot(TRI);
}

void DlgLchSet::on_rbloo_Sine_clicked() {
    if(ui->rbloo_Sine->isChecked() == true) {
        ui->spcycle_Sine->setDisabled(true);
        doPlot(SINE);
    }

}

void DlgLchSet::on_rbclyle_Sine_clicked() {
    if(ui->rbclyle_Sine->isChecked() == true) {
        ui->spcycle_Sine->setDisabled(false);
        doPlot(SINE);
    }
}

void DlgLchSet::on_spcycle_Sine_valueChanged(int arg1) {
    _cycles = arg1;
    doPlot(SINE);
}

void DlgLchSet::on_rbloo_Tri_clicked() {
    if(ui->rbloo_Tri->isChecked() == true) {
        ui->spcycle_Tri->setDisabled(true);
        doPlot(TRI);
    }
}

void DlgLchSet::on_rbclyle_Tri_clicked() {
    if(ui->rbclyle_Tri->isChecked() == true) {
        ui->spcycle_Tri->setDisabled(false);
        doPlot(TRI);
    }

}

void DlgLchSet::on_spcycle_Tri_valueChanged(int arg1) {
    _cycles = arg1;
    doPlot(TRI);
}

void DlgLchSet::on_sbAMP_Saw_valueChanged(double arg1) {
    _amp = arg1;
    doPlot(SAW);
}

void DlgLchSet::on_sbTIME_Saw_valueChanged(double arg1) {
    _time = arg1;
    doPlot(SAW);
}

void DlgLchSet::on_rbloo_Saw_clicked() {
    if(ui->rbloo_Saw->isChecked() == true)
        ui->spcycle_Saw->setDisabled(true);
}

void DlgLchSet::on_rbclyle_Saw_clicked() {
    if(ui->rbclyle_Saw->isChecked() == true)
        ui->spcycle_Saw->setDisabled(false);
}

void DlgLchSet::on_spcycle_Saw_valueChanged(int arg1) {

}

void DlgLchSet::on_sbAMP_Squ_valueChanged(double arg1) {
    _amp = arg1;
    doPlot(SQU);
}

void DlgLchSet::on_sbTIME_Squ_valueChanged(double arg1) {
    _time = arg1;
    doPlot(SQU);
}

void DlgLchSet::on_sbDUTY_Squ_valueChanged(double arg1) {
    _dutyc = arg1;
    doPlot(SQU);
}

void DlgLchSet::on_rbloo_Squ_clicked() {
    if(ui->rbloo_Squ->isChecked() == true)
        ui->spcycle_Squ->setDisabled(true);
}

void DlgLchSet::on_rbclyle_Squ_clicked() {
    if(ui->rbclyle_Squ->isChecked() == true)
        ui->spcycle_Squ->setDisabled(false);
}

void DlgLchSet::on_spcycle_Squ_valueChanged(int arg1) {
    _cycles = arg1;
    doPlot(SQU);
}

void DlgLchSet::on_sbstartTime_valueChanged(double arg1) {

}

void DlgLchSet::on_sbEndTime_valueChanged(double arg1) {

}

void DlgLchSet::on_sbStartY_valueChanged(double arg1) {

}

void DlgLchSet::on_sbEndY_valueChanged(double arg1)
{

}

void DlgLchSet::on_btnConfirmSeg_clicked() {

    double xs = ui->sbstartTime->value ();
    double ys = ui->sbStartY->value ();

    double xe = ui->sbEndTime->value ();
    double ye = ui->sbEndY->value ();

    if(_pcurve != NULL) {
        if(firstFlagW == false) {
            //first
            _pcurve->appendP (xs, ys);
            QString ptsStr = QString("x: ") + QString::number (xs, 'g', 3) +
                    QString("    ") + QString("y: ") + QString::number (ys, 'g', 3);
            ui->lswcurv->addItem (ptsStr);
            _pcurve->appendP (xe, ye);
            QString ptsEnd = QString("x: ") + QString::number (xe, 'g', 3) +
                    QString("    ") + QString("y: ") + QString::number (ye, 'g', 3);
            ui->lswcurv->addItem (ptsEnd);
            doPlotCus();
            ui->sbStartY->setEnabled (false);
            ui->sbstartTime->setEnabled (false);
            ui->sbStartY->setValue (ye);
            ui->sbstartTime->setValue (xe);
            ui->sbEndTime->setMinimum (xe);
        } else {
            _pcurve->appendP (xe, ye);
            QString ptsEnd = QString("x: ") + QString::number (xe, 'g', 3) +
                    QString("    ") + QString("y: ") + QString::number (ye, 'g', 3);
            ui->lswcurv->addItem (ptsEnd);
            doPlotCus();
            ui->sbStartY->setValue (ye);
            ui->sbstartTime->setValue (xe);
            ui->sbEndTime->setMinimum (xe);
        }
        firstFlagW = true;
    }

    _lasttime = ui->sbstartTime->value ();
   // ui->sbstartTime->setMinimum (_lasttime);


}

void DlgLchSet::on_lswcurv_clicked(const QModelIndex &index) {

}

void DlgLchSet::on_cbloop_Cur_clicked() {
   if (ui->cbloop_Cur->isChecked() == true) {

   } else {

   }
}

void DlgLchSet::on_btncurDel_clicked() {
    if(ui->lswcurv->count () > 0) {
        QString t = ui->lswcurv->selectedItems ().at (0)->text ();
        QStringList list = t.split ("    ");
        double x = list.at (0).split ("x:").at (1).trimmed ().toDouble ();
        double y = list.at (1).split ("y:").at (1).trimmed ().toDouble ();
        QPointF p(x,y);
        _pcurve->delSpcPts (p);
        int row = ui->lswcurv->row (ui->lswcurv->selectedItems ().at (0));
        ui->lswcurv->takeItem (0);
        if(ui->lswcurv->count () != 0) {
            doPlotCus ();
        } else {

        }
    }
}

void DlgLchSet::doPlot(int t) {

    if(pc == NULL) {
        pc = new QwtPlotCurve("curve");
        pc->setPen (QPen(Qt::green));
        //pc->setSymbol (new QwtSymbol(QwtSymbol::Triangle, Qt::yellow, QPen(Qt::blue), QSize(5, 5)));
        pc->setSymbol(NULL);
    }

    int a, ti;
    if(_amp < 0)
        a = -_amp;
    else
        a = _amp;
    if(_time < 0)
        ti = -_time;
    else
        ti = _time;

    if(a == 0.0) {
        plot->setAxisScale(QwtPlot::yLeft, -10.0, 10.0);
    } else {
        if(t == SP) {
            plot->setAxisScale(QwtPlot::yLeft, -a * 2, a * 2);
        } else {
            plot->setAxisScale (QwtPlot::yLeft, -a, a);
        }
    }

    if(ti == 0.0) {
        plot->setAxisScale(QwtPlot::xBottom, 0, 10.0);
    } else {
        plot->setAxisScale (QwtPlot::xBottom, 0, ti);
    }

   // plot->setAxisScale (QwtPlot::xBottom, 0.0, 10.0);
   // plot->setAxisScale (QwtPlot::yLeft, -1.0, 1.0);

    if(pc != NULL) {
        switch (t) {
        case SINE:
            if(ui->rbclyle_Sine->isChecked() == true) {
                _cycles = (double)ui->spcycle_Sine->value();
            } else {
                _cycles = 1.0;
            }
            pc->setData (new SinusData(a, ti, _cycles));
            break;
        case TRI:
            if(ui->rbclyle_Tri->isChecked() == true) {
                _cycles = (double)ui->spcycle_Tri->value();
            } else {
                _cycles = 1.0;
            }
            pc->setData (new TriData(a, ti, _cycles));
            break;
        case SAW:
            if(ui->rbclyle_Saw->isChecked() == true) {
                _cycles = (double) ui->spcycle_Saw->value();
            } else {
                _cycles = 1.0;
            }
            pc->setData (new SawData(a, ti, _cycles));
            break;
        case SQU:
            if(ui->rbclyle_Squ->isChecked() == true) {
                _cycles = (double)ui->spcycle_Squ->value();
            } else {
                _cycles = 1.0;
            }
            pc->setData (new SquData(a, _dutyc, ti, _cycles));
            break;
        case CUS:
            break;
        case SP:    //add setting
//            if(ui->rbloo_Sp->isChecked() == true) {
//            }
            pc->setData(new SpData(a, ti));
            break;
        default:
            break;
        }
        //QwtSetSeriesData *sdata;
    }
    pc->attach (plot);
    plot->show ();
    plot->replot ();
}


void DlgLchSet::doPlotCus() {
    if(pc == NULL) {
        pc = new QwtPlotCurve("curve");
        pc->setPen (QPen(Qt::green));
        pc->setSymbol (new QwtSymbol(QwtSymbol::Triangle, Qt::yellow, QPen(Qt::blue), QSize(5, 5)));
    }
    //QwtSetSeriesData *sdata;
    //找出最小bottom
    //plot->setAxisScale (QwtPlot::xBottom, 0, _time);
    //plot->setAxisScale (QwtPlot::yLeft, -_amp, _amp);
    //    CusData *cusdata = new CusData(0.0, 0.0, 100);
    //    cusdata->appendP(4.0, 3.0);
    //    cusdata->appendP(6.0, 10.0);

    if(_pcurve != NULL) {

        //_pcurve->appendP (0.0, 4.4);
        //_pcurve->appendP (0.5, 4.4);
        //_pcurve->appendP (1.0, -4.4);
        //_pcurve->appendP (2.0, -14.4);
        //_pcurve->appendP (3.0, 24.4);
        //_pcurve->appendP (4.0, -40.4);
        //_pcurve->appendP (5.0, 54.4);

        pc->setSamples( _pcurve->getpts ());
        plot->setAxisScale (QwtPlot::xBottom, 0, _pcurve->getXRgn ());
        plot->setAxisScale (QwtPlot::yLeft, -_pcurve->getYRgn (), _pcurve->getYRgn ());
        pc->attach (plot);
        plot->show ();
        plot->replot ();
    }
}

void DlgLchSet::on_lswcurv_itemClicked(QListWidgetItem *item) {
    qDebug () << item->text ();
    QString t = item->text ().trimmed ();
    QStringList list = t.split ("    ");
    double x = list.at (0).split ("x:").at (1).trimmed ().toDouble ();
    double y = list.at (1).split ("y:").at (1).trimmed ().toDouble ();
    //起点
    qDebug () << x << y;
    QPointF point(x, y);
    QPolygonF pts = _pcurve->findpoint (point);

    sm.setValue(pts.at (0).x (), pts.at (0).y ());
    sm.setLineStyle (QwtPlotMarker::VLine);
    sm.setLinePen (Qt::red, 1.5, Qt::DashDotLine);
    sm.setLabelAlignment (Qt::AlignRight | Qt::AlignTop);

    QwtText txt(QString("time_s: ") + QString::number (pts.at (0).x (), 'g', 3) +
                QString("----") + QString("y: ") + QString::number (pts.at (0).y (), 'g',3));
    sm.setLabel (txt);
    em.setValue(pts.at (1).x (), pts.at (1).y ());

    QwtText txt1(QString("time_e: ") + QString::number (pts.at (1).x (), 'g', 3) +
                 QString("----") + QString("y: ") + QString::number (pts.at (1).y (), 'g',3));
    em.setLineStyle (QwtPlotMarker::VLine);
    em.setLinePen (Qt::red, 1.5, Qt::DashDotLine);
    em.setLabelAlignment (Qt::AlignRight | Qt::AlignBottom);
    em.setLabel (txt1);
    sm.attach (plot);
    em.attach (plot);
    qDebug () << pts;

    //qDebug () << _pcurve->genWriteData ();

#if 0
    //_sym.drawSymbol (NULL, _pcurve->getpts ().at (0));
    //_sym.setPen (QPen(Qt::blue));
    //_sym.setStyle (QwtSymbol::Ellipse);
    //_sym.setSize (10, 10);
    //_sym.setPinPoint (_pcurve->getpts ().at (0));
    //pc->setSymbol (&_sym);
#endif
    plot->replot ();
    //高亮
}

void DlgLchSet::on_tabWidget_currentChanged(int index) {

    qDebug() << index << "table index";


    switch (index) {
    case 0:
        _amp = ui->sbAMP_Sp->value();
        _time = ui->sbTIME_Sp->value();
        doPlot(SP);
        break;
    case 1: /*sine*/
        _amp = ui->sbAMP_Sine->value();
        _time = ui->sbTIME_Sine->value();
        _cycles = ui->spcycle_Sine->value();
        doPlot(SINE);
        break;
    case 2:
        _amp = ui->sbAMP_Tri->value();
        _time = ui->sbTIME_Tri->value();
        _cycles = ui->spcycle_Tri->value();
        doPlot(TRI);
        break;
    case 3:
        _amp = ui->sbAMP_Saw->value();
        _time = ui->sbTIME_Saw->value();
        _cycles = ui->spcycle_Saw->value();
        doPlot(SAW);
        break;
    case 4:
        _amp = ui->sbAMP_Squ->value();
        _time = ui->sbTIME_Squ->value();
        _cycles = ui->spcycle_Squ->value();
        _dutyc = ui->sbDUTY_Squ->value();
        doPlot(SQU);
        break;
    case 5:
        doPlotCus();
        break;
    default:
        break;
    }
}

//get set info and apply to lchs
void DlgLchSet::on_buttonBox_accepted() {

    int index = ui->tabWidget->currentIndex();
    int size_ = pc->data()->size();
    switch (index) {
    case 0:
        // sp plot
        qDebug() << "the sp points" << endl;
        break;
    case 1: /*sine*/
        _amp = ui->sbAMP_Sine->value();
        _time = ui->sbTIME_Sine->value();
        _cycles = ui->spcycle_Sine->value();

        for(int i = 0; i < size_; i++) {
            //replace the QployF to lchd pts
            _pts << pc->data()->sample(i);
        }
        break;
    case 2:
        _amp = ui->sbAMP_Tri->value();
        _time = ui->sbTIME_Tri->value();
        _cycles = ui->spcycle_Tri->value();

        for(int i = 0; i < size_; i++) {
            //replace the QployF to lchd pts
            _pts << pc->data()->sample(i);
        }
        break;
    case 3:
        _amp = ui->sbAMP_Saw->value();
        _time = ui->sbTIME_Saw->value();
        _cycles = ui->spcycle_Saw->value();

        for(int i = 0; i < size_; i++) {
            //replace the QployF to lchd pts
            _pts << pc->data()->sample(i);
        }
        break;
    case 4:
        _amp = ui->sbAMP_Squ->value();
        _time = ui->sbTIME_Squ->value();
        _cycles = ui->spcycle_Squ->value();
        _dutyc = ui->sbDUTY_Squ->value();

        for(int i = 0; i < size_; i++) {
            //replace the QployF to lchd pts
            _pts << pc->data()->sample(i);
        }
        break;
    case 5:
        //curve plot
        break;
    default:
        break;
    }
}

void DlgLchSet::on_buttonBox_rejected() {

}


void DlgLchSet::on_btnApplyChangeSp_clicked() {
    double spvalue = ui->sbAMP_Sp->value();
    double spTime = ui->sbTIME_Sp->value();

}
