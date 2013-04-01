#ifndef LVDTCH_H
#define LVDTCH_H
#include "commonch.h"
#include <QString>
class LVDTCh : public CommonCh
{
    Q_OBJECT
public:
    explicit LVDTCh(QObject *parent = 0);
    explicit LVDTCh(int chno, QString chname, QObject *parent = 0);
signals:
    
public slots:
    
};

#endif // LVDTCH_H
