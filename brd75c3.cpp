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
    pdll = NULL; 
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
    pdll = NULL;
	pdll = C75C3DllEncap::getInst();
    if(pdll != NULL) {
        FPTR_CLOSE close = NULL; 
		close = pdll->getClose();
        if(close) {
            return close(brd);
        }
    }
    return CPCI75C3_FAIL;
}

int Brd75C3::getwireMode( int brd, int model, int ch, unsigned short *mode ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if (pdll != NULL) {
		FPTR_GET_WIREMODE getwm = NULL; 
		getwm = pdll->getWireMode();
		if(getwm) {
			return getwm(brd, model, ch, mode);
		}
	}
}

int Brd75C3::setwireMode( int brd, int model, int ch, unsigned short mode ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if(pdll != NULL) {
		FPTR_SET_WIREMODE setwm = NULL;
		setwm = pdll->setWireMode();
		if(setwm) {
			return setwm(brd, model, ch, mode);
		}
	}
}

/*set sig vll ratio matric or fix mode*/
int Brd75C3::setVllOptMode( int brd, int model, int ch, unsigned short mode ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if (pdll != NULL) {
		FPTR_SET_VLL_OPTMOD setvll = NULL;
		setvll = pdll->setVllOptMode();
		if(setvll) {
			return setvll(brd, model, ch, mode);
		}
	}
}

int Brd75C3::getVllOptMode( int brd, int model, int ch, unsigned short *mode ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if(pdll != NULL) {
		FPTR_GET_VLL_OPTMOD getvll = NULL;
		getvll = pdll->getVllOptMode();
		if(getvll) {
			return getvll(brd, model, ch, mode);
		}
	}
}


