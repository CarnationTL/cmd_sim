#include "sigdata.h"

SigData::SigData(QObject *parent) :
    QObject(parent) {

}

SigData::~SigData() {

}


void SigData::genDataFrame(int type) {
    switch (type) {
    case SINE:
        break;
    case TRI:
        break;
    case SAW:
        break;
    case SQU:
        break;
    case CUS:
        break;
    default:
        break;
    }
   // if(type == SINE) {
   //
   // } else
}

int SigData::sigTypes() const
{
    return _sigTypes;
}

void SigData::setSigTypes(int sigTypes)
{
    _sigTypes = sigTypes;
}
