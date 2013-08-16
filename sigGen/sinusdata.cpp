#include "sinusdata.h"

SinusData::SinusData(double amp, double time) :
    QwtSyntheticPointData(100)

{
    _amp = amp;
    _time = time;
}
