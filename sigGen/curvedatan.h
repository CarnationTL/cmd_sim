#ifndef CURVEDATAN_H
#define CURVEDATAN_H
#include <QPointF>
#include <QPolygonF>
class CurveDataN
{
public:
    CurveDataN(int size);
    void appendP(double x, double y);
    QPolygonF getpts();
    QPolygonF genWriteData();
    double getYRgn();
    double getXRgn();
    void clear();
    void delSpcPts(QPointF p);
    QPolygonF findpoint(QPointF point);
private:
    QVector <QPointF> ret;
    QPolygonF _points;
    int _t_size;
};

#endif // CURVEDATAN_H



