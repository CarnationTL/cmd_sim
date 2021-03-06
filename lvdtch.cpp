#include "lvdtch.h"
#include "cmddefs.h"
LVDTCh::LVDTCh(QObject *parent) :
    CommonCh(parent) {
}

LVDTCh::LVDTCh(int chno, QString chname, QObject *parent) :
    CommonCh(chno, chname, parent) {
#if defined(Q_OS_WIN)
    ptr = C75C3DllEncap::getInst();
#endif
}


int LVDTCh::sigType() const {
    return _sigType;
}

void LVDTCh::setSigType(int sigType) {
    _sigType = sigType;
}

QPolygonF LVDTCh::getPts() const
{
    return pts;
}

void LVDTCh::setPts(const QPolygonF &value)
{
    pts = value;
}


