//
// Created by Eric Huiza on 5/13/26.
//

#include "Persona.h"

Persona::Persona() : Registro() {
    dni = 0;
    nombre = nullptr;
    edad = 0;

    cout << "Se ejecutó el constructor de Persona" << endl;
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

void Persona::setDni(int dni) {
    this->dni = dni;
}

void Persona::setNombre(char* nombre) {
    delete[] this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Persona::setEdad(int edad) {
    this->edad = edad;
}

void Persona::imprimir(ostream& os) const {
    os << "DNI: " << this->getDni() << endl;
    os << "Nombre: " << this->getNombre() << endl;
    os << "Edad: " << this->getEdad() << endl;
}

ostream& operator<<(ostream& os, const Persona& persona) {
    persona.imprimir(os);
    return os;
}

Persona::~Persona() {
    delete[] nombre;

    cout << "Se ejecutó el destructor de Persona" << endl;
}