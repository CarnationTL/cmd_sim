#ifndef CMDSIMMW_H
#define CMDSIMMW_H

#include <QMainWindow>
#include <QStringList>
#include <QListView>
#include <QStandardItemModel>
namespace Ui {
class CMDSimMW;
}

class CMDSimMW : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit CMDSimMW(QWidget *parent = 0);
    ~CMDSimMW();
    int initInstructs();
private:
    Ui::CMDSimMW *ui;
    int initrfm(void);
    int init75c3(void);

    QStringList *ps_ins_v;
    QStandardItemModel *dv_model;
    QString cvcp936(const char str[]);
    void initInsView();
};

#endif // CMDSIMMW_H
