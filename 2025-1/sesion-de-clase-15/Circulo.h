/* 
 * File:   Circulo.h
 * Author: erichuiza
 *
 * Created on May 16, 2025, 5:37 PM
 */

#ifndef CIRCULO_H
#define CIRCULO_H

#include <iostream>

using namespace std;

class Circulo {
private:
    double radio;
public:
    Circulo();
    Circulo(double);
    Circulo(const Circulo& orig);
    
    double getRadio() const;
    void setRadio(double radio);
    
    double calcularArea();
    void imprimirArea();
    
    virtual ~Circulo();
};

#endif /* CIRCULO_H */

