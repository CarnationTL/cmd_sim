#include "lvdtch.h"
#include "cmddefs.h"
LVDTCh::LVDTCh(QObject *parent) :
    CommonCh(parent) {
}

LVDTCh::LVDTCh(int chno, QString chname, QObject *parent) :
    CommonCh(chno, chname, parent) {

}
