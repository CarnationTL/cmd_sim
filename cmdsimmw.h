#ifndef CMDSIMMW_H
#define CMDSIMMW_H

#include <QMainWindow>

namespace Ui {
class CMDSimMW;
}

class CMDSimMW : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CMDSimMW(QWidget *parent = 0);
    ~CMDSimMW();
    
private:
    Ui::CMDSimMW *ui;
    int initrfm(void);
};

#endif // CMDSIMMW_H
