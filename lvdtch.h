#ifndef LVDTCH_H
#define LVDTCH_H
#include "c75c3dllencap.h"
#include "commonch.h"
#include <QString>
class LVDTCh : public CommonCh
{
    Q_OBJECT
public:
    explicit LVDTCh(QObject *parent = 0);
    explicit LVDTCh(int chno, QString chname, QObject *parent = 0);
private:
    C75C3DllEncap *ptr;
signals:
    
public slots:
    
};

#endif // LVDTCH_H
