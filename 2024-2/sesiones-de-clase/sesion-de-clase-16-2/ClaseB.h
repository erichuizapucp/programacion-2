/* 
 * File:   ClaseB.h
 * Author: erichuiza
 *
 * Created on October 21, 2024, 12:41 PM
 */

#ifndef CLASEB_H
#define CLASEB_H

#include <iostream>
#include "ClaseA.h"

using namespace std;

class ClaseB : virtual public ClaseA {
public:
    ClaseB();
    ClaseB(const ClaseB& orig);
    
    void imprimirB();
    
    ~ClaseB();
private:

};

#endif /* CLASEB_H */

