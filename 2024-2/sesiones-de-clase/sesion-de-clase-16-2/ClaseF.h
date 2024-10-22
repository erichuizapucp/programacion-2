/* 
 * File:   ClaseF.h
 * Author: erichuiza
 *
 * Created on October 21, 2024, 12:56 PM
 */

#ifndef CLASEF_H
#define CLASEF_H

#include "ClaseE.h"

using namespace std;

class ClaseF : public ClaseE {
public:
    ClaseF();
    ClaseF(const ClaseF& orig);
    
    void imprimirF();
    
    ~ClaseF();
private:

};

#endif /* CLASEF_H */

