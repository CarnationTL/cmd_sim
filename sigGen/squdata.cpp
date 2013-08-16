#include "squdata.h"

SquData::SquData(double amp, double time, double dutyc) :
    QwtSyntheticPointData(100)
{
    _amp = amp;
    _time = time;
    _dutyc = dutyc;
}
