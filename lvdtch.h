#ifndef LVDTCH_H
#define LVDTCH_H
#include <qglobal.h>
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
    int sigType() const;
    void setSigType(int sigType);

private:
#if defined(Q_OS_WIN)
    C75C3DllEncap *ptr;
#endif

signals:
    
public slots:

private:
    int _sigType;
};

#endif // LVDTCH_H
