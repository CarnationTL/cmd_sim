#include "commonch.h"

CommonCh::CommonCh(QObject *parent) :
    QObject(parent)
{

}

QString CommonCh::chname() const {
    return _chname;
}

void CommonCh::setChname(const QString &chname) {
    _chname = chname;
}
int CommonCh::chno() const {
    return _chno;
}

void CommonCh::setChno(int chno) {
    _chno = chno;
}
