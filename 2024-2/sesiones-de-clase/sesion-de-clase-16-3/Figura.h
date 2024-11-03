/* 
 * File:   Figura.h
 * Author: erichuiza
 *
 * Created on October 25, 2024, 5:05 PM
 */

#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>
#include <fstream>

using namespace std;

class Figura {
protected:
    virtual void imprimir(ostream&) const = 0;
    virtual void cargar(ifstream&) const = 0;
public:
    Figura();
    Figura(const Figura& orig);
    
    friend ostream& operator<<(ostream&, const Figura&);
    friend ifstream& operator>>(ifstream&, const Figura&);
    
    virtual ~Figura();
};

#endif /* FIGURA_H */
