/* 
 * File:   ClaseC.h
 * Author: erichuiza
 *
 * Created on October 21, 2024, 12:41 PM
 */

#ifndef CLASEC_H
#define CLASEC_H

#include <iostream>
#include "ClaseA.h"

using namespace std;

class ClaseC : virtual public ClaseA {
public:
    ClaseC();
    ClaseC(const ClaseC& orig);
    
    void imprimirC();
    
    ~ClaseC();
private:

};

#endif /* CLASEC_H */

