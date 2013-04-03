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
    ~SetBrdDlg();
    
private:
    Ui::SetBrdDlg *ui;
};

#endif // SETBRDDLG_H
