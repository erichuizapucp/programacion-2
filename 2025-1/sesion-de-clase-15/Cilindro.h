/* 
 * File:   Cilindro.h
 * Author: erichuiza
 *
 * Created on May 16, 2025, 5:44 PM
 */

#ifndef CILINDRO_H
#define CILINDRO_H

#include "Circulo.h"


class Cilindro : public Circulo {
private:
    double altura;
public:
    Cilindro();
    Cilindro(double, double);
    Cilindro(const Cilindro& orig);
    
    double getAltura() const;
    void setAltura(double altura);
    
    double calcularArea();
    void imprimirArea();
    
    virtual ~Cilindro();
};

#endif /* CILINDRO_H */

