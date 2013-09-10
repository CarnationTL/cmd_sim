#ifndef SPDATA_H
#define SPDATA_H

#include <Qwt/qwt_point_data.h>
#define PI 3.1415927
#define D_PTS 256

class SpData : public QwtSyntheticPointData
{
public:
    SpData(double value, double time);
    virtual double y(double x) const;
private:
    double _amp;
    double _time;
};

#endif // SPDATA_H
