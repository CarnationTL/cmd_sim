#ifndef SIGPARA_H
#define SIGPARA_H

#include <QObject>
#include <cmddefs.h>
class SigPara : public QObject
{
    Q_OBJECT
public:
    explicit SigPara(QObject *parent = 0);
    int createSigPara(int type);
signals:
    
public slots:

private:
    int _types;
    int _amp;
    int _feq;
    int _duty;
};

#endif // SIGPARA_H
