#ifndef SIGGEN_H
#define SIGGEN_H

#include <QObject>
#include <QVector>
#include <QList>
#include <QMap>
#include <cmddefs.h>
class SigGen : public QObject
{
    Q_OBJECT
public:
    explicit SigGen(QObject *parent = 0);
  //  int genData(int type, );
signals:
    
public slots:

private:
    QList <double> _data;
};

#endif // SIGGEN_H
