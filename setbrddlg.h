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
    
private:
    Ui::SetBrdDlg *ui;
};

#endif // SETBRDDLG_H
