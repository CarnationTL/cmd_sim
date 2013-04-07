#ifndef SETWPDLG_H
#define SETWPDLG_H

#include <QDialog>

namespace Ui {
class SetWPDlg;
}

class SetWPDlg : public QDialog
{
    Q_OBJECT
    
public:
    explicit SetWPDlg(QWidget *parent = 0);
    ~SetWPDlg();
    
private:
    Ui::SetWPDlg *ui;
};

#endif // SETWPDLG_H
