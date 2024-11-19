/* 
 * File:   Curso.cpp
 * Author: erichuiza
 * 
 * Created on November 17, 2024, 6:10 PM
 */

#include "Curso.h"

Curso::Curso() {
    codigo = {};
    nombre = {};
    creditos = {};
    capacidad = {};
}

Curso::Curso(const Curso& orig) {
    *this = orig;
}

int Curso::getCodigo() const {
    return codigo;
}

int Curso::getCapacidad() const {
    return capacidad;
}

string Curso::getNombre() const {
    return nombre;
}

Curso& Curso::operator=(const Curso& orig) {
    codigo = orig.codigo;
    nombre = orig.nombre;
    creditos = orig.creditos;
    capacidad = orig.capacidad;
    
    return *this;
}

bool Curso::operator<(const Curso& curso) const {
    return codigo < curso.codigo;
}

bool Curso::operator>(const Curso& curso) const {
    return codigo > curso.codigo;
}

ifstream& operator>>(ifstream& archivo, Curso& curso) {
    archivo >> curso.codigo;
    archivo.ignore();
    getline(archivo, curso.nombre, ',');
    archivo >> curso.creditos;
    archivo.ignore();
    archivo >> curso.capacidad;
    archivo.ignore();
    
    return archivo;
}

ofstream& operator<<(ofstream& archivo, const Curso& curso) {
    archivo << setw(5) << curso.codigo << setw(20) << curso.nombre << setw(5) << curso.creditos << setw(5) << curso.capacidad << endl;
    
    return archivo;
}

Curso::~Curso() {
}

