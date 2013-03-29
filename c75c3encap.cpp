#include "c75c3encap.h"


C75C3Encap::C75C3Encap(QObject *parent) :
    QObject(parent) {

}

/**
  open brd test for load win dir
  **/
int C75C3Encap::OpenTest() {
 //   return CPCI75C3_Open(0);
    return 0;
}
