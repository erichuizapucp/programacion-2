/* 
 * File:   Persona.cpp
 * Author: erichuiza
 * 
 * Created on May 26, 2025, 4:29 PM
 */

#include "Persona.h"

Persona::Persona() {
}

Persona::Persona(int dni, const char* nombre) {
    this->dni = dni;
    this->setNombre(nombre);
}

Persona::Persona(const Persona& orig) {
    *this = orig;
}

int Persona::getDni() const {
    return dni;
}

void Persona::setDni(int dni) {
    this->dni = dni;
}

char* Persona::getNombre() const {
    return this->nombre;
}

void Persona::setNombre(const char* nombre) {
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

Persona& Persona::operator=(const Persona& persona) {
    this->setDni(persona.getDni());
    this->setNombre(persona.getNombre());
    
    return *this;
}

void Persona::imprimir(ostream& os) const {
    os << left << setw(15) << this->dni
        << setw(50) << this->nombre;
}

Persona::~Persona() {
    delete[] nombre;
}

