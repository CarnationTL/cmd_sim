#include "commbrd.h"

CommBrd::CommBrd(QObject *parent) :
    QObject(parent) {

}

CommBrd::CommBrd(int bdno, QObject *parent):
                _bdno(bdno), QObject(parent) {
}
