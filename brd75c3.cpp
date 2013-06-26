#define WIN32_LEAN_AND_MEAN
#include "brd75c3.h"
#include "c75c3funcp.h"

#if defined(Q_OS_WIN)
#include "CPCI75C3.h"
#endif

#if defined(Q_OS_LINUX)
#define CPCI75C3_FAIL -1
#endif

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
	return CPCI75C3_FAIL;
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
	return CPCI75C3_FAIL;
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
	return CPCI75C3_FAIL;
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
	return CPCI75C3_FAIL;
}

int Brd75C3::setSigLossTH( int brd, int model, int ch, double val ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if (pdll != NULL) {
		FPTR_SET_SIGLOSS_THOLD func = NULL;
		func = pdll->setSigLossTH();
		if (func) {
			return func(brd, model, ch, val);
		}
	}
	return CPCI75C3_FAIL;
}

int Brd75C3::getSigLossTH( int brd, int model, int ch, double *val ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if (pdll != NULL) {
		FPTR_GET_SIGLOSS_THOLD func = NULL;
		func = pdll->getSigLossTH();
		if (func) {
			return func(brd, model, ch, val);
		}
	}
	return CPCI75C3_FAIL;
}

/*ref loss thread funcs*/
int Brd75C3::getRefLossTH( int brd, int model, int ch, double *val ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if (pdll != NULL) {
		FPTR_GET_REFLOSS_THOLD func = NULL;
		func = pdll->getRefLossTH();
		if (func) {
			return func(brd, model, ch, val);
		}
	}
	return CPCI75C3_FAIL;
}

int Brd75C3::setRefLossTH( int brd, int model, int ch, double val ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if (pdll != NULL) {
		FPTR_SET_REFLOSS_THOLD func = NULL;
		func = pdll->setRefLossTH();
		if (func) {
			return func(brd, model, ch, val);
		}
	}
	return CPCI75C3_FAIL;
}

int Brd75C3::setChOpStatus( int brd, int model, int ch, unsigned short val ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if (pdll != NULL) {
		FPTR_SET_CHOP_STA func = NULL;
		func = pdll->setChOPStat();
		if (func) {
			return func(brd, model, ch, val);
		}
	}
	return CPCI75C3_FAIL;
}

int Brd75C3::getChOpStatus( int brd, int model, int ch, unsigned short *val ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if (pdll != NULL) {
		FPTR_GET_CHOP_STA func;
		func = pdll->getChOPStat();
		if (func) {
			return func(brd, model, ch, val);
		}
	}
	return CPCI75C3_FAIL;
}

int Brd75C3::getChPwSupply( int brd, int model, int ch, unsigned short *val ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if (pdll != NULL) {
		FPTR_GET_DLCHPW_STA func;
		func = pdll->getDLPwStat();
		if (func) {
			return func(brd, model, ch, val);
		}
	}
	return CPCI75C3_FAIL;
}

int Brd75C3::setChPwSupply( int brd, int model, int ch, unsigned short val ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if (pdll != NULL) {
		FPTR_SET_DLCHPW_STA func = NULL;
		func = pdll->setDLPwStat();
		if (func) {
			return func(brd, model, ch, val);
		}
	}
	return CPCI75C3_FAIL;
}

/*set ref vol val for DL and REF model*/
int Brd75C3::setRefRefVol( int brd, int model, double val ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if (pdll != NULL) {
		FPTR_SET_REF_VOL func = NULL;
		func = pdll->setRefVol();
		if (func) {
			return func(brd, model, val);
		}
	}
	return CPCI75C3_FAIL;
}

int Brd75C3::getRefRefVol( int brd, int model, double *val ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if (pdll != NULL) {
		FPTR_GET_REF_VOL func = NULL;
		func = pdll->getRefVol();
		if (func) {
			return func(brd, model, val);
		}
	}
	return CPCI75C3_FAIL;
}

int Brd75C3::setDLRefVol( int brd, int model, int ch, double val ) {
	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if (pdll != NULL) {
		FPTR_SET_EXPREF_VOL func = NULL;
		func = pdll->setexpRefVol();
		if (func) {
			return func(brd, model, ch, val);
		}
	}
	return CPCI75C3_FAIL;
}

int Brd75C3::getDLRefVol( int brd, int mdoel, int ch, double *val ) {

	pdll = NULL;
	pdll = C75C3DllEncap::getInst();
	if (pdll != NULL) {
		FPTR_GET_EXPREF_VOL func = NULL;
		func = pdll->getexpEefVol();
		if (func) {
			return func(brd, mdoel, ch, val);
		}
	}
	return CPCI75C3_FAIL;
}

