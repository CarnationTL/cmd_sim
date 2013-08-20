#ifndef SETBRDDLG_H
#define SETBRDDLG_H

#include <QDialog>

namespace Ui {
class SetBrdDlg;
}

class SetBrdDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit SetBrdDlg(QWidget *parent = 0);
    void initBrdDlgCtls();
    ~SetBrdDlg();
    
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_kb1v_valueChanged(double value);

    void on_kb1f_valueChanged(double value);

    void on_kb2v_valueChanged(double value);

    void on_kb2f_valueChanged(double value);

    void on_kb3v_valueChanged(double value);

    void on_kb3f_valueChanged(double value);

    void on_kb4v_valueChanged(double value);

    void on_kb4f_valueChanged(double value);

    void on_sp1v_valueChanged(double arg1);

    void on_sp1f_valueChanged(double arg1);

    void on_sp2v_valueChanged(double arg1);

    void on_sp2f_valueChanged(double arg1);

    void on_sp3v_valueChanged(double arg1);

    void on_sp3f_valueChanged(double arg1);

    void on_sp4v_valueChanged(double arg1);

    void on_sp4f_valueChanged(double arg1);

private:
    Ui::SetBrdDlg *ui;
};

#endif // SETBRDDLG_H
