#ifndef LVDTCH_H
#define LVDTCH_H
#include <qglobal.h>
#include <QPointF>
#include <QPolygonF>
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
    LVDTCh(int chno, QString chname, QObject *parent = 0);
    int sigType() const;
    void setSigType(int sigType);

public:
#if defined(Q_OS_WIN)
    C75C3DllEncap *ptr;
#endif

    QPolygonF getPts() const;
    void setPts(const QPolygonF &value);

signals:
    
public slots:

private:
    int _sigType;
    QPolygonF pts;
};


#endif // LVDTCH_H

