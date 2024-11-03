/* 
 * File:   Cilindro.h
 * Author: erichuiza
 *
 * Created on October 21, 2024, 4:01 PM
 */

#ifndef CILINDRO_H
#define CILINDRO_H

#include <iostream>
#include "Circulo.h"

using namespace std;

class Cilindro : public Circulo {
private:
    double altura;
protected:
    virtual void imprimir(ostream&) const;
public:
    Cilindro();
    Cilindro(double radio, double altura);
    Cilindro(const Cilindro& orig);
    
    double getAltura() const;
    virtual double calcularArea() const;
    
    void operator=(const Cilindro&);
    
    virtual ~Cilindro();
};

#endif /* CILINDRO_H */
