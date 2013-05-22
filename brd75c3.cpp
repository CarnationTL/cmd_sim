#define WIN32_LEAN_AND_MEAN
#include "brd75c3.h"
#include "c75c3funcp.h"
#include "CPCI75C3.h"
Brd75C3::Brd75C3(QObject *parent) :
    CommBrd(parent) {
}

/**
  encap open
*/
int Brd75C3::openbrd(int brd) {
    pdll = C75C3DllEncap::getInst();
    if(pdll != NULL) {
        FPTR_OPEN open = NULL;
        open = pdll->getOpen();
        if(open) {
            return open(brd); //need caller to watch return values
        }
    }
    return CPCI75C3_FAIL;
}


/**
  encap close
*/
int Brd75C3::closebrd(int brd) {
    pdll = C75C3DllEncap::getInst();
    if(pdll != NULL) {
        FPTR_CLOSE close = pdll->getClose();
        if(close) {
            return close(brd);
        }
    }
    return CPCI75C3_FAIL;
}

