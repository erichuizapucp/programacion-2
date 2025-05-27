/* 
 * File:   Mesero.cpp
 * Author: erichuiza
 * 
 * Created on May 2, 2025, 5:22 PM
 */

#include "Mesero.h"

Mesero::Mesero() {
}

Mesero::Mesero(
    int dni, 
    const char* nombre, 
    double sueldo, 
    int experiencia
) : Persona(dni, nombre) {
    this->sueldo = sueldo;
    this->experiencia = experiencia;
}

Mesero::Mesero(const Mesero& orig) : Persona(orig) {
    *this=orig;
}

double Mesero::getSueldo() const {
    return sueldo;
}

void Mesero::setSueldo(double sueldo) {
    this->sueldo = sueldo;
}

int Mesero::getExperiencia() const {
    return experiencia;
}

void Mesero::setExperiencia(int experiencia) {
    this->experiencia = experiencia;
}

Mesero& Mesero::operator=(const Mesero& mesero) {
//    Persona::operator=(mesero);
    this->setDni(mesero.getDni());
    this->setNombre(mesero.getNombre());
    this->setSueldo(mesero.getSueldo());
    this->setExperiencia(mesero.getExperiencia());
    
    return *this;
}

void Mesero::imprimir(ostream& os) const {
    Persona::imprimir(os);
    os << right << setw(15) << fixed 
            << setprecision(2) << this->sueldo
        << setw(15) << this->experiencia
        << endl;
}

Mesero::~Mesero() {
}

