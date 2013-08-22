#ifndef DLGRFMDEBUG_H
#define DLGRFMDEBUG_H

#include <QDialog>

namespace Ui {
class DlgRFMDebug;
}

class DlgRFMDebug : public QDialog
{
    Q_OBJECT
    
public:
    explicit DlgRFMDebug(QWidget *parent = 0);
    ~DlgRFMDebug();
    
private:
    Ui::DlgRFMDebug *ui;
};

#endif // DLGRFMDEBUG_H
