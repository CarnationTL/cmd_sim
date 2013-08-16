#ifndef SINUSDATA_H
#define SINUSDATA_H

#include <Qwt/qwt_point_data.h>

class SinusData : public QwtSyntheticPointData
{
public:
    SinusData(double amp, double time);
private:
    double _amp;
    double _time;

};

#endif // SINUSDATA_H
