#ifndef TRIDATA_H
#define TRIDATA_H

#include <Qwt/qwt_point_data.h>
class TriData : public QwtSyntheticPointData
{
public:
    TriData(double amp, double time);
};

#endif // TRIDATA_H
