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
private:
    C75C3DllEncap *pdll;
signals:

public slots:

};

#endif // BRD75C3_H
