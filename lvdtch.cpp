#include "lvdtch.h"
#include "cmddefs.h"
LVDTCh::LVDTCh(QObject *parent) :
    CommonCh(parent) {
}

LVDTCh::LVDTCh(int chno, QString chname, QObject *parent) :
    CommonCh(chno, chname, parent) {

}

int LVDTCh::OpenBrd() {
    if(pdll->isloaded()) {

    }else {
        pdll->loadDll();
        if(pdll->isloaded()) {

        }else {
            return EXE_FAIL;
        }
    }
}

int LVDTCh::InitBrd() {

}
