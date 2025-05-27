/* 
 * File:   Mesero.cpp
 * Author: erichuiza
 * 
 * Created on May 2, 2025, 5:22 PM
 */

#include "Mesero.h"

Mesero::Mesero() {
//    cout << "El mesero se instancia." << endl;
}

Mesero::Mesero(int dni, const char* nombre, double sueldo, int experiencia) {
    this->dni = dni;
    this->setNombre(nombre);
    this->sueldo = sueldo;
    this->experiencia = experiencia;
}

Mesero::Mesero(const Mesero& orig) {
    *this=orig;
}

int Mesero::getDni() const {
    return dni;
}

void Mesero::setDni(int dni) {
    this->dni = dni;
}

char* Mesero::getNombre() const {
    return this->nombre;
}

void Mesero::setNombre(const char* nombre) {
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
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
    this->setDni(mesero.getDni());
    this->setNombre(mesero.getNombre());
    this->setSueldo(mesero.getSueldo());
    this->setExperiencia(mesero.getExperiencia());
    
    return *this;
}

bool Mesero::operator>(const Mesero& mesero) {
    return this->sueldo > mesero.getSueldo();
}

bool Mesero::operator<(const Mesero& mesero) {
    return this->sueldo < mesero.getSueldo();
}

Mesero::~Mesero() {
//    cout << "Se libera memoria de un mesero" << endl;
    delete[] nombre;
}

