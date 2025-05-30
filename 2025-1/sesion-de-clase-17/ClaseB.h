/* 
 * File:   ClaseB.h
 * Author: erichuiza
 *
 * Created on May 30, 2025, 10:55 AM
 */

#ifndef CLASEB_H
#define CLASEB_H

#include <iostream>
#include "ClaseA.h"

using namespace std;

class ClaseB : public ClaseA {
private:
public:
    ClaseB();
    ClaseB(const ClaseB& orig);
    
    void imprimir();
    
    virtual ~ClaseB();
};

#endif /* CLASEB_H */

