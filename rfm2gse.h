#ifndef RFM2GSE_H
#define RFM2GSE_H

#ifdef Q_OS_WIN
#include <Windows.h>
#include <wincodecsdk.h>
#include <wincodec.h>
#include <WinDef.h>
#include <WinBase.h>
#endif

#include "rfminc/rfm2g_windows.h"
#include "rfminc/rfm2g_types.h"
#include "rfminc/rfm2gdll_stdc.h"
#include "rfminc/rfm2g_api.h"
#include "cmddefs.h"

#include <QObject>
class RFM2gSE : public QObject
{
    Q_OBJECT
public:
    explicit RFM2gSE(QObject *parent = 0);
    int open();
	const char* DevName() const { return _devName; }
	void DevName(char val[]) { strcpy_s(_devName, val); }
	RFM2G_STATUS Result() const { return _result; }
	void Result(RFM2G_STATUS val) { _result = val; }

	const RFM2G_UINT32* Outbuffer() const { return _outbuffer; }
	void Outbuffer(RFM2G_UINT32 val[]) { 
		memcpy(_outbuffer, val, sizeof(val) / sizeof(RFM2G_UINT32)); }

	const RFM2G_UINT32* Inbuffer() const { return _inbuffer; }
	void Inbuffer(RFM2G_UINT32 val[]) {
		memcpy(_inbuffer, val, sizeof(val) / sizeof(RFM2G_UINT32)); }

	RFM2GHANDLE Handle() const { return _Handle; }
	void Handle(RFM2GHANDLE val) { _Handle = val; }

	RFM2G_INT32 NumDevice() const { return _numDevice; }
	void NumDevice(RFM2G_INT32 val) { _numDevice = val; }

	RFM2GEVENTINFO EventInfo() const { return _EventInfo; }
	void EventInfo(RFM2GEVENTINFO val) { _EventInfo = val; }

	RFM2G_NODE OtherNodeId() const { return _otherNodeId; }
	void OtherNodeId(RFM2G_NODE val) { _otherNodeId = val; }
private:
    char           _devName[DEV_LEN];
	RFM2G_STATUS   _result;                 /* Return codes from RFM2g API calls */
	RFM2G_UINT32   _outbuffer[BUFFER_SIZE]; /* Data written to another node      */
	RFM2G_UINT32   _inbuffer[BUFFER_SIZE];  /* Data read from another node       */
	RFM2G_NODE     _otherNodeId;            /* Node ID of the other RFM board    */
	RFM2GEVENTINFO _EventInfo;              /* Info about received interrupts    */
	RFM2G_INT32    _numDevice;
	RFM2GHANDLE    _Handle;
	char           *pchar;
	RFM2G_UINT32   *prfmInt;
signals:

public slots:
    
};
    #endif // RFM2GSE_H
