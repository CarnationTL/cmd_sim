#ifndef C75C3ENCAP_H
#define C75C3ENCAP_H

#include <QObject>
#include <WinSock2.h>
#include <QLibrary>
extern "C" {
#include "75C3inc/CPCI75C3.h"
}

#include <QLibrary>


class C75C3Encap : public QObject
{
    Q_OBJECT
public:
    explicit C75C3Encap(QObject *parent = 0);
    QLibrary *pclib;
public:
    int OpenTest();
signals:

public slots:
    
};

#endif // C75C3ENCAP_H
