/* 
 * File:   Persona.cpp
 * Author: erichuiza
 * 
 * Created on May 26, 2025, 4:29 PM
 */

#include "Persona.h"

Persona::Persona() {
}

Persona::Persona(int dni, const string nombre) {
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

string Persona::getNombre() const {
    return this->nombre;
}

void Persona::setNombre(const string nombre) {
    this->nombre = nombre;
}

bool Persona::cargarDatos(ifstream& archivo) {
    int dni;
    if (!archivo.eof() && archivo >> dni) {
        archivo.ignore();
        char *nombre = leerCadena(archivo);
        
        this->setDni(dni);
        this->setNombre(nombre);
        
        return true;
    }

    return false;
}

bool operator>>(ifstream& archivo, Persona& persona) {
    return persona.cargarDatos(archivo);
}

ostream& operator<<(ostream& os, const Persona& persona) {
    persona.imprimir(os);
    return os;
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
}

