#ifndef COMMBRD_H
#define COMMBRD_H

#include <QObject>

class CommBrd : public QObject
{
    Q_OBJECT
public:
    explicit CommBrd(QObject *parent = 0);
    explicit CommBrd(int bdno, QObject *parent);
    virtual int openbrd(int) = 0;
    virtual int closebrd(int) = 0;
    virtual int bitTest() = 0;
private:
    int _bdno;
signals:

public slots:
    
};

#endif // COMMBRD_H
