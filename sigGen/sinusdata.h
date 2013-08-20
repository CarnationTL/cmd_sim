#ifndef SINUSDATA_H
#define SINUSDATA_H

#include <Qwt/qwt_point_data.h>
#define PI 3.1415927
#define D_PTS 256
class SinusData : public QwtSyntheticPointData
{
public:
    SinusData(double amp, double time);
    virtual double y( double x ) const;
private:
    double _amp;
    double _feq;
    double _time;
};

#endif // SINUSDATA_H
