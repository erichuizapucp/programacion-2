/* 
 * File:   Circulo.h
 * Author: erichuiza
 *
 * Created on October 21, 2024, 8:48 AM
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
    Circulo(double radio);
    Circulo(const Circulo& orig);
    
    double getRadio() const;
    double calcularArea() const;
    double calcularCircunferencia() const;
    void imprimir(ostream&) const;
    void operator=(const Circulo&);
    
    ~Circulo();
};

ostream& operator<<(ostream&, const Circulo&);

#endif /* CIRCULO_H */

