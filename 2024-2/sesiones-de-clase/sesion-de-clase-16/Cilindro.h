/* 
 * File:   Cilindro.h
 * Author: erichuiza
 *
 * Created on October 21, 2024, 10:22 AM
 */

#ifndef CILINDRO_H
#define CILINDRO_H

#include <iostream>
#include "Circulo.h"

using namespace std;

class Cilindro : public Circulo {
private:
    double altura;
public:
    Cilindro();
    Cilindro(double radio, double altura);
    Cilindro(const Cilindro& orig);
    
    double calcularArea() const;
    void operator=(const Cilindro&);
    void imprimir(ostream&) const;
    
    ~Cilindro();
};

ostream& operator<<(ostream&, const Cilindro&);

#endif /* CILINDRO_H */

