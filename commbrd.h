#ifndef COMMBRD_H
#define COMMBRD_H

#include <QObject>

class CommBrd : public QObject
{
    Q_OBJECT
public:
    explicit CommBrd(QObject *parent = 0);
    explicit CommBrd(int bdno, QObject *parent);
private:
    int _bdno;
signals:

public slots:
    
};

#endif // COMMBRD_H
