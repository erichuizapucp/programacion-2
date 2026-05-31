//
// Created by Eric Huiza on 5/30/26.
//

#ifndef EJERCICIO01_PERSONA_H
#define EJERCICIO01_PERSONA_H

#include <iostream>

using namespace std;

class Persona {
    int dni;
    int edad;
public:
    Persona();
    Persona(int dni, int edad);

    int getDni() const;
    int getEdad() const;

    virtual void imprimir() const = 0;

    virtual ~Persona();
};


#endif //EJERCICIO01_PERSONA_H
