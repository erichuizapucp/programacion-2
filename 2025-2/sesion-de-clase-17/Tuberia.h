//
// Created by Eric Huiza on 10/20/25.
//

#ifndef SESION_DE_CLASE_17_TUBERIA_H
#define SESION_DE_CLASE_17_TUBERIA_H
#include "Cilindro.h"

using namespace std;

class Tuberia : public Cilindro {
    double radioInterno;

public:
    double calcularArea() const;
};


#endif //SESION_DE_CLASE_17_TUBERIA_H