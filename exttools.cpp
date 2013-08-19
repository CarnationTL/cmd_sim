#include "exttools.h"
#include "ui_exttools.h"

#include <QSettings>
#include <QProgressDialog>
#include <Qwt/qwt_series_store.h>
#define D_CNT 256
#define INVALUE -1
#define S_ITEM_AMP "amp"
#define S_ITEM_TIME "time"
#define S_ITEM_DATA "data"
#define S_ITEM_DUYC "dutyc"
#define S_ITEM_TYPE "type"
#define S_ITEM_LOOP "loop"
#define S_ITEM_VP "vpset"
//#define S_ITEM_VPV "vpvalue"
#define S_ITEM_VPPHY "vpphy"
#define S_ITEM_VPVOL "vpvol"


bool firstFlag = false;

extTools::extTools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::extTools)
{
    ui->setupUi(this);

    _dcnt = D_CNT;
    plot = ui->qwtPlot;
    plot->setAutoDelete (true);
    plot->setAxisScale(QwtPlot::xBottom, 0, 10.0);
    plot->setAxisScale(QwtPlot::yLeft, -10.0, 10.0);
    ui->rbSin->setChecked (true);
    _type = SINE;
    toggleDutycHide (false);
    pc = NULL;
    _amp = 0.0;
    _time = 0.0;
    _dutyc = 50;
    ui->sbDUTY->setValue(50.0);
    _pcurve = new CurveDataN(D_PTS);
    //markerinit();
    gridinit ();
    //plot->setCanvasBackground (QColor("MidnightBlue"));
    plot->setCanvasBackground (QColor(0, 49, 114));
    initSwitchPara (false);
    _loop = false;
    vpfactor = 1.0;
    pvfactor = 1.0;
    ui->spVoltage->setValue (1.0);
    ui->spphysic->setValue (1.0);
    ui->rbphy->setChecked (true);
    ui->lbamp_end->setText ("MM/C");
    ui->spphysic->setValue (100.0);
    ui->spVoltage->setValue (10.0);
    ui->sbAMP->setMaximum (100.0);



}

extTools::~extTools()
{
    delete ui;
}

void extTools::on_btnGenWData_clicked() {

    if(_type == INVALUE) {
        QMessageBox::warning (this, "INFO", "please select the wave type, thanks!");
        return;
    }

    QFileDialog fp;
    QString fn = fp.getSaveFileName (this, "Save Data File", ".", "Data (*.wdata)");
    if(fn.isEmpty())
        return;
    if(!fn.endsWith ("*.wdata")) { fn.append (".wdata");
    }

    QSettings set(fn, QSettings::IniFormat);

    QStringList slx;
    QStringList sly;
    QStringList txy;
    int size = pc->data ()->size ();
    for(int i = 0; i < size; i++) {
        QPointF pint = pc->data ()->sample (i);
        slx << QString::number (pint.x (), 'g', 3);
        sly << QString::number (pint.y (), 'g', 3);
        txy << consSdata (QString::number (pint.x (), 'g', 3), QString::number (pint.y (), 'g', 3));
    }

    switch (_type) {
    case SINE:
        set.setValue (S_ITEM_TYPE, "SINE");
        break;
    case SAW:
        set.setValue (S_ITEM_TYPE, "SAW");
        break;
    case SQU:
        set.setValue (S_ITEM_TYPE, "SQU");
        set.setValue (S_ITEM_DUYC, QString::number (ui->sbDUTY->value (), 'g', 3));
        break;
    case TRI:
        set.setValue (S_ITEM_TYPE, "TRI");
        break;
    case CUS:
        set.setValue (S_ITEM_TYPE, "CUS");
        break;
    default:
        break;
    }

    if(_type != CUS) {
        //AMP
        set.setValue (S_ITEM_AMP, QString::number (ui->sbAMP->value (), 'g', 3));
        //TIME
        set.setValue (S_ITEM_TIME, QString::number (ui->sbTIME->value (), 'g', 3));
    } else {
        set.setValue(S_ITEM_AMP, QString::number(_pcurve->getYRgn(), 'g', 3));
        set.setValue(S_ITEM_TIME, QString::number(_pcurve->getXRgn(), 'g', 3));
    }
    //CURVE data
   // set.setValue(S_ITEM_DATA_X, slx);
   // set.setValue(S_ITEM_DATA_Y, sly);
    if(getvpSet () == PHY || getvpSet () == -1) {
        set.setValue (S_ITEM_VP, QString("PHY"));
   //     set.setValue (S_ITEM_VPV, QString::number (pvfactor, 'g', 3));
    } else if(getvpSet () == VOL) {
        set.setValue (S_ITEM_VP, QString("VOL"));
   //     set.setValue (S_ITEM_VPV, QString::number (vpfactor, 'g', 3));
    }

    double phy = ui->spphysic->value ();
    set.setValue (S_ITEM_VPPHY, QString::number (phy, 'g', 3));
    double vol = ui->spVoltage->value ();
    set.setValue (S_ITEM_VPVOL, QString::number (vol, 'g', 3));

    set.setValue (S_ITEM_LOOP, _loop);

    set.setValue (S_ITEM_DATA, txy);

#if 0
    QStringList list =  set.value (S_ITEM_DATA).toStringList ();
    for(int i = 0; i < list.length (); i++) {
        qDebug () << list.at (i).toDouble ();
    }

    qDebug () << fn ;

    //read form file
    QSettings setread(fn);
    qDebug () << setread.value (S_ITEM_AMP).toDouble ();

#endif

}


void extTools::on_btnClose_clicked() {
    QApplication::closeAllWindows ();
}

void extTools::on_rbSin_clicked() {
    _type = SINE;
    toggleDutycHide (false);
    initSwitchPara(false);
    switchWvRbs (SINE, true);
    doPlot (SINE);
}

void extTools::on_rbSquare_clicked() {
    _type = SQU;
    toggleDutycHide (true);
    initSwitchPara(false);
    switchWvRbs (SQU, true);
    doPlot (SQU);
}

void extTools::on_rbSaw_clicked() {
    _type = SAW;
    toggleDutycHide (false);
    initSwitchPara(false);
    switchWvRbs (SAW, true);
    doPlot (SAW);
}

void extTools::on_rbTri_clicked() {
    _type = TRI;
    toggleDutycHide (false);
    initSwitchPara(false);
    switchWvRbs (TRI, true);
    doPlot (TRI);
}

void extTools::on_rbCus_clicked() {
    _type = CUS;
    initSwitchPara(true);
    toggleDutycHide(false);
    switchWvRbs (SQU, false);
}

void extTools::toggleDutycHide(bool f) {
    if(f == true) {
        ui->lbDUTY->show ();
        ui->sbDUTY->show ();
    } else {
        ui->lbDUTY->hide ();
        ui->sbDUTY->hide ();
    }
}


//do plot for regular curves
void extTools::doPlot(int t) {

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
        plot->setAxisScale (QwtPlot::yLeft, -a, a);
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
            pc->setData (new SinusData(a, ti));
            break;
        case TRI:
            pc->setData (new TriData(a, ti));
            break;
        case SAW:
            pc->setData (new SawData(a, ti));
            break;
        case SQU:
            if(_dutyc)
            pc->setData (new SquData(a, _dutyc, ti));
            break;
        case CUS:
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

void extTools::doPlot(QStringList strdata) {
    if(strdata.length () > 0) {
        QPointF point;
        QVector <QPointF> vec;
        for(int i = 0; i < strdata.length (); i++) {
            point.setX (deconsSdata (strdata.at (i)).at (0).toDouble ());
            point.setY (deconsSdata (strdata.at (i)).at (1).toDouble ());
            vec.append (point);
        }
        if(pc == NULL) {
            pc = new QwtPlotCurve("curve");
            pc->setPen (QPen(Qt::green));
            if(_type == CUS) {
                pc->setSymbol (new QwtSymbol(QwtSymbol::Triangle, Qt::yellow, QPen(Qt::blue), QSize(5, 5)));
            } else {
                pc->setSymbol (NULL);
            }

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
            plot->setAxisScale (QwtPlot::yLeft, -a, a);
        }

        if(ti == 0.0) {
            plot->setAxisScale(QwtPlot::xBottom, 0, 10.0);
        } else {
            plot->setAxisScale (QwtPlot::xBottom, 0, ti);
        }



        if(pc != NULL) {
            pc->setSamples (vec);
#if 0
            switch (t) {
            case SINE:
                pc->setData (new SinusData(a));
                break;
            case TRI:
                pc->setData (new TriData(a));
                break;
            case SAW:
                pc->setData (new SawData(a));
                break;
            case SQU:
                if(_dutyc)
                    pc->setData (new SquData(a, _dutyc));
                break;
            case CUS:
                break;
            default:
                break;

        }
#endif
            //QwtSetSeriesData *sdata;

        }
        pc->attach (plot);
        plot->show ();
        plot->replot ();
    }
}


//do plot for cus curves
void extTools::doPlotCus() {
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

void extTools::readSetting(QString fn) {
    if(fn.length () > 0) {
        QSettings set(fn);
        int t = set.value (S_ITEM_TYPE).toInt ();
        switch (t) {
        case SINE:
            {
                setrbCheck (SINE);
                double time = set.value (S_ITEM_TIME).toDouble ();
                setTimeSp (time);
            }

            break;
        case TRI:
            setrbCheck (TRI);
            break;
        case SAW:
            setrbCheck (SAW);
            break;
        case SQU:
            setrbCheck (SQU);
            break;
        case CUS:
            setrbCheck (CUS);
            break;
        default:
            break;
        }
    }
    QMessageBox::warning (this, "waring", "settings file empty!", QMessageBox::Yes);
}

void extTools::setrbCheck(int t) {
    if(t == -1)
        return;
    bool val = true;
    switch (t) {
    case SINE:
        ui->rbSin->setChecked (val);
        ui->rbTri->setChecked (!val);
        ui->rbSaw->setChecked (!val);
        ui->rbSquare->setChecked (!val);
        ui->rbCus->setChecked (!val);
        break;
    case TRI:
        ui->rbSin->setChecked (!val);
        ui->rbTri->setChecked (val);
        ui->rbSaw->setChecked (!val);
        ui->rbSquare->setChecked (!val);
        ui->rbCus->setChecked (!val);
        break;
    case SAW:
        ui->rbSin->setChecked (!val);
        ui->rbTri->setChecked (!val);
        ui->rbSaw->setChecked (val);
        ui->rbSquare->setChecked (!val);
        ui->rbCus->setChecked (!val);
        break;
    case SQU:
        ui->rbSin->setChecked (!val);
        ui->rbTri->setChecked (!val);
        ui->rbSaw->setChecked (!val);
        ui->rbSquare->setChecked (val);
        ui->rbCus->setChecked (!val);
        break;
    case CUS:
        ui->rbSin->setChecked (!val);
        ui->rbTri->setChecked (!val);
        ui->rbSaw->setChecked (!val);
        ui->rbSquare->setChecked (!val);
        ui->rbCus->setChecked (val);
        break;
    default:
        break;
    }
}

void extTools::setTimeSp(double time) {
    if(time < 0.0)
        return;
    if(time < 0) {
        ui->sbTIME->setValue (0.0);
    } else if(time > 0) {
        ui->sbTIME->setValue (time);
    }
}

QString extTools::consSdata(QString x, QString y) {
    return QString("(") + x + QString(",") + y + QString(")");
}

QStringList extTools::deconsSdata(QString xy) {
    if(xy.size () < 5)
        return QStringList("");
    QStringList strl = xy.split (",");
    QStringList ret;
    ret << strl.at (0).split ("(").at (1);
    ret << strl.at (1).split (")").at (0);
    return ret;
}

//void extTools::markerinit() {
//    _hmarker = new QwtPlotMarker();
//    _hmarker->setLineStyle(QwtPlotMarker::HLine);
//    _hmarker->setValue (0.0, 0.0);
//    _hmarker->setLinePen(Qt::blue, Qt::DashDotLine);
//    if(plot != NULL) {
//        _hmarker->attach(plot);
//    }
//}

void extTools::gridinit() {
    grid = new QwtPlotGrid();
    grid->enableXMin (true);
    grid->setMajorPen( Qt::white, 0, Qt::DotLine );
    grid->setMinorPen( Qt::gray, 0 , Qt::DotLine );
    if(plot != NULL) {
        grid->attach (plot);
    }
}

void extTools::initSwitchPara(bool flag) {
   //disable cus
    ui->sbstartTime->setEnabled (flag);
    ui->sbEndTime->setEnabled (flag);
    ui->sbStartY->setEnabled (flag);
    ui->sbEndY->setEnabled (flag);

    ui->btnConfirmSeg->setEnabled (flag);
    ui->btncurDel->setEnabled (flag);

    ui->lswcurv->setEnabled(flag);
}


void extTools::switchWvRbs(int type, bool flag) {
    ui->sbAMP->setEnabled (flag);
    ui->sbTIME->setEnabled (flag);
    if(type == SQU) {
        ui->sbDUTY->setEnabled (flag);
    }
}

int extTools::getvpSet() {
    if(ui->rbphy->isChecked () == true) {
        return PHY;
    } else if(ui->rbvoltage->isChecked () == true) {
        return VOL;
    }
    return -1;
}

void extTools::vpSet(int t) {
    if(t == PHY) {
        ui->rbphy->setChecked (true);
    } else if (t == VOL) {
        ui->rbvoltage->setChecked (true);
    }
}

void extTools::changePRgn(double v) {
    if(v >= 0) {
        plot->setAxisScale (QwtPlot::yLeft, -v, v);
        plot->replot();
    }
}

void extTools::on_sbAMP_valueChanged(double arg1) {
    if(arg1 >= 0.0) {
        _amp = arg1;
    }

    switch (_type) {
        case SINE:
            doPlot(SINE);
            break;
        case SAW :
            doPlot(SAW);
            break;
        case TRI :
            doPlot(TRI);
            break;
        case SQU :
            doPlot(SQU);
            break;
#if 1
        case CUS :
            doPlotCus();
            break;
#endif
        default:
            break;
    }
}

void extTools::on_sbTIME_valueChanged(double arg1) {
    if(arg1 > 0) {
        _time = arg1;
        double feq = 1.0 / _time;
        ui->lbFEQ->setText (QString("FEQ:     ") + QString::number (feq, 'g', 3) + QString(" Hz"));
    }
    switch (_type) {
        case SINE:
            doPlot(SINE);
            break;
        case SAW :
            doPlot(SAW);
            break;
        case TRI :
            doPlot(TRI);
            break;
        case SQU :
            doPlot(SQU);
            break;
        default:
            break;
    }
}

void extTools::on_sbDUTY_valueChanged(double arg1) {
    if(arg1 >= 0.0) {
        _dutyc = arg1;
        doPlot(SQU);
    }
}


//load data files
void extTools::on_btnLoad_clicked() {
    QFileDialog fp;
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
            ".",
            tr("Data (*.wdata)"));
    if(fileName.size () <= 0) {
        qDebug() << fileName ;
        return;
    }
    QSettings set(fileName, QSettings::IniFormat);


    QString _t = set.value (S_ITEM_TYPE, "SINE").toString ();
    if(_t == QString("SINE")) {
        _type = SINE;
        setrbCheck (SINE);
        initSwitchPara (false);
        switchWvRbs (SINE, true);
    } else if(_t == QString("TRI")) {
        _type = TRI;
        setrbCheck (TRI);
        initSwitchPara (false);
        switchWvRbs(TRI, true);
    } else if(_t == QString("SAW")) {
        _type = SAW;
        setrbCheck (SAW);
        initSwitchPara(false);
        switchWvRbs(SAW, true);
    } else if(_t == QString("SQU")) {
        _type = SQU;
        setrbCheck (SQU);
        initSwitchPara(false);
        switchWvRbs(SQU, true);
    } else if(_t == QString("CUS")) {
        _type = CUS;
        setrbCheck (CUS);
        initSwitchPara(true);
        switchWvRbs(SQU, false);
    }

    _amp = set.value (S_ITEM_AMP, 0.0).toDouble ();
    ui->sbAMP->setValue (_amp);
    _time = set.value (S_ITEM_TIME, 0.0).toDouble ();
    ui->sbTIME->setValue (_time);

    if(_type == SQU) {
        _dutyc = set.value (S_ITEM_DUYC, 0.5).toDouble ();
        ui->sbDUTY->setValue (_dutyc);
    }

    _loop = set.value (S_ITEM_LOOP, false).toBool ();
    ui->ckbloop->setChecked (_loop);

    _vpstr = set.value (S_ITEM_VP, QString("PHY")).toString ();
    if(_vpstr.compare (QString("PHY")) == 0) {
        ui->rbphy->setChecked (true);


    } else if(_vpstr.compare (QString("VOL")) == 0) {
        ui->rbphy->setChecked (true);

    }

    double phyfac = set.value (S_ITEM_VPPHY, 1.0).toDouble ();
    double volfac = set.value (S_ITEM_VPVOL, 1.0).toDouble ();

    ui->spphysic->setValue (phyfac);
    ui->spVoltage->setValue (volfac);

    //set data
    doPlot (set.value (S_ITEM_DATA, "").toStringList ());

    return;
}

//value change 提供预览(部分预览)
void extTools::on_sbstartTime_valueChanged(double arg1) {
    if(_type == CUS) {
        if(arg1 != 0.0) {

        }
    }
}

void extTools::on_sbEndTime_valueChanged(double arg1) {

}

void extTools::on_sbStartY_valueChanged(double arg1) {

}

void extTools::on_sbEndY_valueChanged(double arg1) {

}


//确定按钮
void extTools::on_btnConfirmSeg_clicked() {

    double xs = ui->sbstartTime->value ();
    double ys = ui->sbStartY->value ();

    double xe = ui->sbEndTime->value ();
    double ye = ui->sbEndY->value ();



    if(_pcurve != NULL) {

        if(firstFlag == false) {
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
        firstFlag = true;
    }

    _lasttime = ui->sbstartTime->value ();
   // ui->sbstartTime->setMinimum (_lasttime);

}



void extTools::on_lswcurv_itemClicked(QListWidgetItem *item) {
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

#if 1

#endif

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

void extTools::on_btncurDel_clicked() {
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

void extTools::on_ckbloop_clicked() {
   _loop = ui->ckbloop->isChecked ();
}

void extTools::on_rbvoltage_clicked() {
    if(ui->rbvoltage->isChecked () == true) {
        vpflag = true;
    }
    //根据电压到物理换算.
    ui->lbamp_end->setText ("VOL");
    double ret = ui->spVoltage->value ();
    ui->sbAMP->setMaximum (ret);
    changePRgn (ret);
    //刷新UI
}


void extTools::on_rbphy_clicked() {
    if(ui->rbvoltage->isChecked () == true) {
        vpflag = false;
    }
    ui->lbamp_end->setText ("MM/C");
    //刷新UI
    double ret = ui->spphysic->value ();
    ui->sbAMP->setMaximum (ret);
    changePRgn (ret);
}


//电压量程
void extTools::on_spVoltage_valueChanged(double arg1) {

    phyfac = ui->spphysic->value ();
    volfac = ui->spVoltage->value ();
    if(phyfac != 0.0 && volfac != 0.0) {
       pvfactor = phyfac / volfac;
       vpfactor = volfac / phyfac;
//       qDebug () << "pvfactor" << pvfactor;
//       qDebug () << "vpfactor" << vpfactor;
    }
    if(ui->rbvoltage->isChecked () == true) {
        ui->sbAMP->setMaximum (arg1);
        changePRgn (arg1);
    }
}

//物理量量程
void extTools::on_spphysic_valueChanged(double arg1) {

    phyfac = ui->spphysic->value ();
    volfac = ui->spVoltage->value ();
    if(phyfac != 0.0 && volfac != 0.0) {
       pvfactor = phyfac / volfac;
       vpfactor = volfac / phyfac;
//       qDebug () << "pvfactor" << pvfactor;
//       qDebug () << "vpfactor" << vpfactor;
    }
    if(ui->rbphy->isChecked () == true) {
        ui->sbAMP->setMaximum (arg1);
        changePRgn (arg1);
    }
}

