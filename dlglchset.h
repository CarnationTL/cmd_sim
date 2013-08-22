#ifndef DLGLCHSET_H
#define DLGLCHSET_H

#include <QDialog>
#include <Qwt/qwt_plot.h>
#include <Qwt/qwt_plot_grid.h>

namespace Ui {
class DlgLchSet;
}

class DlgLchSet : public QDialog
{
    Q_OBJECT
    
public:
    explicit DlgLchSet(QWidget *parent = 0);
    ~DlgLchSet();
    
private:
    Ui::DlgLchSet *ui;
    QString genChInfo(QStringList chlst, QStringList namelist);
    void plotInit();
    void initpointers();
    QwtPlot *plot;
    QwtPlotGrid *grid;
};

#endif // DLGLCHSET_H
