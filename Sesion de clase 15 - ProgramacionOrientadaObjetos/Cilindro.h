/* 
 * File:   Cilindro.h
 * Author: erichuiza
 *
 * Created on May 6, 2024, 4:16 PM
 */

#ifndef CILINDRO_H
#define CILINDRO_H

class Cilindro : public Circulo {
private:
    double h;
public:
    Cilindro(double, double);
    double calcularArea();
};

#endif /* CILINDRO_H */

