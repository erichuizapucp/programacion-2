/* 
 * File:   ClaseD.h
 * Author: erichuiza
 *
 * Created on October 21, 2024, 12:41 PM
 */

#ifndef CLASED_H
#define CLASED_H

#include <iostream>
#include "ClaseB.h"
#include "ClaseC.h"

using namespace std;

class ClaseD : public ClaseB, public ClaseC {
public:
    ClaseD();
    ClaseD(const ClaseD& orig);
    
    void imprimirD();
    
    virtual ~ClaseD();
private:

};

#endif /* CLASED_H */

