/* 
 * File:   Mesero.cpp
 * Author: erichuiza
 * 
 * Created on May 2, 2025, 5:22 PM
 */

#include "Mesero.h"


Mesero::Mesero(
    int dni, 
    const char* nombre, 
    double sueldo, 
    int experiencia
) : Persona(dni, nombre) {
    this->sueldo = sueldo;
    this->experiencia = experiencia;
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

bool Mesero::cargarDatos(ifstream& archivo) {
    if (Persona::cargarDatos(archivo)) {
        double sueldo;
        int experiencia;
        
        archivo >> sueldo;
        archivo.ignore();
        archivo >> experiencia;
        archivo.ignore();
        
        this->setSueldo(sueldo);
        this->setExperiencia(experiencia);
        
        return true;
    }
    return false;
}

bool Mesero::operator <(const Mesero& other) const {
    return this->getNombre() < other.getNombre();
}


//Mesero& Mesero::operator=(const Mesero& mesero) {
//    Persona::operator=(mesero);
//    this->setSueldo(mesero.getSueldo());
//    this->setExperiencia(mesero.getExperiencia());
//    
//    return *this;
//}

void Mesero::imprimir(ostream& os) const {
    Persona::imprimir(os);
    os 
        << right << setw(15) << fixed << setprecision(2) << this->sueldo
        << setw(15) << this->experiencia
        << endl;
}

//Mesero::~Mesero() {
//}
