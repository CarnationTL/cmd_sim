#ifndef DLGLCHSET_H
#define DLGLCHSET_H

#include <QDialog>

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
};

#endif // DLGLCHSET_H
