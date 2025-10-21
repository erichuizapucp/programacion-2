//
// Created by Eric Huiza on 10/20/25.
//

#ifndef SESION_DE_CLASE_17_CILINDRO_H
#define SESION_DE_CLASE_17_CILINDRO_H
#include "Circulo.h"

using namespace std;
class Cilindro : public Circulo {
    double altura;
public:
    Cilindro();
    Cilindro(double, double);
    Cilindro(const Cilindro &);

    double calcularArea() const;

    ~Cilindro();
};


#endif //SESION_DE_CLASE_17_CILINDRO_H