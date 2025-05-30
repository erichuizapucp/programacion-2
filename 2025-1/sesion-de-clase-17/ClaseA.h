/* 
 * File:   ClaseA.h
 * Author: erichuiza
 *
 * Created on May 30, 2025, 10:55 AM
 */

#ifndef CLASEA_H
#define CLASEA_H

#include <iostream>

using namespace std;

class ClaseA {
private:
public:
    ClaseA();
    ClaseA(const ClaseA& orig);
    
    virtual void imprimir();
    
    
    virtual ~ClaseA();
};

#endif /* CLASEA_H */

