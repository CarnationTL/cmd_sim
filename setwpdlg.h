#ifndef SETWPDLG_H
#define SETWPDLG_H

#include <QDialog>
#include <qwt_dial.h>
#include <qwt_dial_needle.h>
namespace Ui {
class SetWPDlg;
}

class SetWPDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit SetWPDlg(QWidget *parent = 0);
    ~SetWPDlg();
    
private slots:
    void on_pb_test_clicked();

    void on_knob_sliderMoved(double value);

private:
    Ui::SetWPDlg *ui;
    void setdialstyle(QwtDial *p);
};

#endif // SETWPDLG_H
