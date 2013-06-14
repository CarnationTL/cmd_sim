#ifndef BRD75C3_H
#define BRD75C3_H
#include "commbrd.h"
#include "c75c3dllencap.h"

class Brd75C3 : public CommBrd
{
    Q_OBJECT
public:
    explicit Brd75C3(QObject *parent = 0);
    int openbrd(int brd);
    int closebrd(int brd);
	int getwireMode(int brd, int model, int ch, unsigned short *mode);
	int setwireMode(int brd, int model, int ch, unsigned short mode);

	int setVllOptMode(int brd, int model, int ch, unsigned short mode);
	int getVllOptMode(int brd, int model, int ch, unsigned short *mode);

	int setSigLossTH(int brd, int model, int ch, double val);
	int getSigLossTH(int brd, int model, int ch, double *val);

	int getRefLossTH(int brd, int model, int ch, double *val);
	int setRefLossTH(int brd, int model, int ch, double val);

	int setChOpStatus(int brd, int model, int ch, unsigned short val);
	int getChOpStatus(int brd, int model, int ch, unsigned short *val);

	int getChPwSupply(int brd, int model, int ch, unsigned short *val);
	int setChPwSupply(int brd, int model, int ch, unsigned short val);

	int setRefRefVol(int brd, int model, double val);
	int getRefRefVol(int brd, int model, double *val);

	int setDLRefVol(int brd, int model, int ch, double val);
	int getDLRefVol(int brd, int mdoel, int ch, double *val);
private:
    C75C3DllEncap *pdll;
signals:

public slots:

};

#endif // BRD75C3_H
