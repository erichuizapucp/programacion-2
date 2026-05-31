//
// Created by Eric Huiza on 5/30/26.
//

#include "Persona.h"

Persona::Persona() {
    dni = 0;
    edad = 0;
}

Persona::Persona(int dni, int edad) {
    this->dni = dni;
    this->edad = edad;
}

int Persona::getDni() const {
    return dni;
}

int Persona::getEdad() const {
    return edad;
}

Persona::~Persona() {
    cout << "Destructor de la persona" << endl;
}
