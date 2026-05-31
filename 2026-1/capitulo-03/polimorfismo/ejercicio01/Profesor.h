//
// Created by Eric Huiza on 5/30/26.
//

#ifndef EJERCICIO01_PROFESOR_H
#define EJERCICIO01_PROFESOR_H

#include <iostream>

#include "Persona.h"

using namespace std;

class Profesor : public Persona {
    int cantCursos;
public:
    Profesor();
    Profesor(int dni, int edad, int cantCursos);

    void imprimir() const override;

    ~Profesor() override;
};


#endif //EJERCICIO01_PROFESOR_H
