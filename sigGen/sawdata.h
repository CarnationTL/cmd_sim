#ifndef SAWDATA_H
#define SAWDATA_H

#include <Qwt/qwt_point_data.h>
//#define PI 3.1415927
class SawData : public QwtSyntheticPointData
{
public:
    SawData(double amp, double time);
    virtual double y( double x ) const;
private:
    double _amp;
    double _feq;
    double _time;


};

#endif // SAWDATA_H
