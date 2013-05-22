#ifndef SETLBRDPARADLG_H
#define SETLBRDPARADLG_H

#include <QDialog>

namespace Ui {
class setLbrdParaDlg;
}

class setLbrdParaDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit setLbrdParaDlg(QWidget *parent = 0);
    ~setLbrdParaDlg();
    
private:
    Ui::setLbrdParaDlg *ui;
};

#endif // SETLBRDPARADLG_H
