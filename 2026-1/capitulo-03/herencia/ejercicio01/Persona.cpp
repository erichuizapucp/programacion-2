//
// Created by Eric Huiza on 5/13/26.
//

#include "Persona.h"

Persona::Persona() {
    dni = 0;
    nombre = nullptr;
    edad = 0;
}

Persona::Persona(const Persona& origin) {
    *this = origin;
}

int Persona::getDni() const {
    return dni;
}

char* Persona::getNombre() const {
    return nombre;
}

int Persona::getEdad() const {
    return edad;
}

void Persona::leer(ifstream& archivo) {

}

void Persona::imprimir(ofstream& os) {

}

Persona::~Persona() {
    delete[] nombre;
}