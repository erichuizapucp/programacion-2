/* 
 * File:   Circulo.h
 * Author: erichuiza
 *
 * Created on October 21, 2024, 3:38 PM
 */

#ifndef CIRCULO_H
#define CIRCULO_H

#include <iostream>
#include "Figura.h"

using namespace std;

class Circulo : public Figura {
private:
    double radio;
protected:
    virtual void imprimir(ostream&) const;
public:
    Circulo();
    Circulo(double);
    Circulo(const Circulo& orig);
    
    double getRadio() const;
    virtual double calcularArea() const;
    double calcularCircunferencia() const;
    
    void operator=(const Circulo&);
    
    virtual ~Circulo();
};

#endif /* CIRCULO_H */
