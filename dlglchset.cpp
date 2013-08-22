#include "dlglchset.h"
#include "ui_dlglchset.h"

DlgLchSet::DlgLchSet(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgLchSet)
{
    ui->setupUi(this);
    initpointers();
    plotInit();
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
}

void DlgLchSet::initpointers() {
    plot = ui->plotWhole;
}
