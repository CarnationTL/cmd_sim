#ifndef LVDTCH_H
#define LVDTCH_H
#if defined(Q_OS_WIN)
#include "c75c3dllencap.h"
#endif

#include "commonch.h"
#include <QString>
class LVDTCh : public CommonCh
{
    Q_OBJECT
public:
    explicit LVDTCh(QObject *parent = 0);
    explicit LVDTCh(int chno, QString chname, QObject *parent = 0);
private:
#if defined(Q_OS_WIN)
    C75C3DllEncap *ptr;
#endif

signals:
    
public slots:
    
};

#endif // LVDTCH_H
