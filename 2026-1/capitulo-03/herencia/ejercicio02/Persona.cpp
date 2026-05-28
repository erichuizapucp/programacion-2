//
// Created by Eric Huiza on 5/15/26.
//

#include "Persona.h"

Persona::Persona() {
    dni = 0;
    nombre = nullptr;
}

Persona::Persona(const Persona& origin) : Persona() {
    *this = origin;
}

int Persona::getDni() const {
    return dni;
}

char* Persona::getNombre() const {
    return nombre;
}

void Persona::setDni(int dni) {
    this->dni = dni;
}

void Persona::setNombre(char* nombre) {
    setCadena(this->nombre, nombre);
}

Persona& Persona::operator=(const Persona& origin) {
    if (this != &origin) {
        this->setDni(origin.getDni());
        this->setNombre(origin.getNombre());
    }
    return *this;
}

ifstream& Persona::leer(ifstream& archivo) {
    int dni;
    if (archivo >> dni) {
        archivo.ignore();
        char* nombre = leerCadena(archivo);

        this->setDni(dni);
        this->setNombre(nombre);

        delete[] nombre;
    }

    return archivo;
}

ofstream& Persona::imprimir(ofstream& archivo) const {
    archivo << "DNI: " << this->getDni() << endl;
    archivo << "Nombre: " << this->getNombre() << endl;

    return archivo;
}

Persona::~Persona() {
    delete[] this->nombre;
}

ifstream& operator>>(ifstream& archivo, Persona& persona) {
    return persona.leer(archivo);
}

ofstream& operator<<(ofstream& archivo, const Persona& persona) {
    return persona.imprimir(archivo);
}

