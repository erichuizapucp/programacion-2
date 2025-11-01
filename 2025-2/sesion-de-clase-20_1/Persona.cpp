//
// Created by Eric Huiza on 10/31/25.
//

#include "Persona.h"

Persona::Persona(char* nombre, int dni) : Persona() {
    this->setNombre(nombre);
    this->dni = dni;
}

Persona::Persona(const Persona& origen) : Persona() {
    *this = origen;
}

void Persona::setDni(int dni) {
    this->dni = dni;
}

void Persona::setNombre(char* nombre) {
    delete[] this->nombre;
    if (nombre) {
        this->nombre = new char[strlen(nombre) + 1];
        strcpy(this->nombre, nombre);
    }
    else {
        this->nombre = nullptr;
    }
}

Persona& Persona::operator=(const Persona& origen) {
    if (this == &origen) {
        return *this;
    }
    this->setDni(origen.dni);
    this->setNombre(origen.nombre);
    return *this;
}

ostream& operator<<(ostream& os, const Persona& persona) {
    os << "Nombre: " << persona.nombre << endl;
    os << "DNI: " << persona.dni << endl;
    return os;
}