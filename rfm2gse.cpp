#include "rfm2gse.h"
#include <string.h>
#include <QString>
#include "cmddefs.h"

RFM2gSE::RFM2gSE(QObject *parent) :
    QObject(parent)
{
	QString tmp(RFM_DEV);
    int len = tmp.size();
    if(len > 0) {
        memset(_devName, 0, DEV_LEN);
		for (int i = 0; i < len; i++) {
			_devName[i] = tmp.at(i).toLatin1();
		}
    }
}

int RFM2gSE::open() {
	int ret = RFM2gOpen(_devName, &_Handle);
	if(ret != RFM2G_SUCCESS) {
		return EXE_FAIL;
	}
	return EXE_SUCCESS;
}

