/* 
 * File:   ClaseC.h
 * Author: erichuiza
 *
 * Created on May 30, 2025, 10:55 AM
 */

#ifndef CLASEC_H
#define CLASEC_H

#include <iostream>
#include "ClaseA.h"

using namespace std;

class ClaseC : public ClaseA {
private:
    
public:
    ClaseC();
    ClaseC(const ClaseC& orig);
    
    void imprimir();
    
    virtual ~ClaseC();
};

#endif /* CLASEC_H */

