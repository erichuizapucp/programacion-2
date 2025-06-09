/* 
 * File:   Persona.cpp
 * Author: erichuiza
 * 
 * Created on May 26, 2025, 4:29 PM
 */

#include "Persona.h"

Persona::Persona(int dni, const string nombre) : Registro() {
    this->dni = dni;
    this->setNombre(nombre);
}

//Persona::Persona(const Persona& orig) : Registro(orig) {
//    *this = orig;
//}

int Persona::getDni() const {
    return dni;
}

void Persona::setDni(int dni) {
    this->dni = dni;
}

string Persona::getNombre() const {
    return this->nombre;
}

void Persona::setNombre(string nombre) {
    this->nombre = nombre;
}

bool Persona::cargarDatos(ifstream& archivo) {
    int dni;
    if (!archivo.eof() && archivo >> dni) {
        archivo.ignore();
        getline(archivo, this->nombre, ',');
        
        this->setDni(dni);
        this->setNombre(nombre);
        
        return true;
    }

    return false;
}

void Persona::imprimir(ostream& os) const {
    os << left << setw(15) << this->dni
        << setw(50) << this->nombre;
}
