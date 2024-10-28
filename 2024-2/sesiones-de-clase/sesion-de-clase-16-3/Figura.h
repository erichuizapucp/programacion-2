/* 
 * File:   Figura.h
 * Author: erichuiza
 *
 * Created on October 25, 2024, 5:05 PM
 */

#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>

using namespace std;

class Figura {
public:
    Figura();
    Figura(const Figura& orig);
    
    virtual void imprimir(ostream&) const = 0;
    
    virtual ~Figura();
};

ostream& operator<<(ostream&, const Figura&);

#endif /* FIGURA_H */

