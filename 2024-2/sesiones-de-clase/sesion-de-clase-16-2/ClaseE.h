/* 
 * File:   ClaseE.h
 * Author: erichuiza
 *
 * Created on October 21, 2024, 12:53 PM
 */

#ifndef CLASEE_H
#define CLASEE_H

#include "ClaseD.h"

class ClaseE : private ClaseD {
public:
    ClaseE();
    ClaseE(const ClaseE& orig);
    
    void imprimirE();
    
    ~ClaseE();
private:

};

#endif /* CLASEE_H */

