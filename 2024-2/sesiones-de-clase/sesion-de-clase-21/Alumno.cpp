/* 
 * File:   Alumno.cpp
 * Author: erichuiza
 * 
 * Created on November 11, 2024, 10:32 AM
 */

#include "Alumno.h"

Alumno::Alumno() {
    codigo = {};
    nombre = {};
    apellido = {};
    edad = {};
    ciclo = {};
    promedio = {};
}

Alumno::Alumno(const Alumno& orig) {
    *this = orig;
}

int Alumno::getCodigo() const {
    return codigo;
}

double Alumno::getPromedio() const {
    return promedio;
}

string Alumno::getNombre() const {
    return nombre;
}

string Alumno::getApellido() const {
    return apellido;
}

Alumno& Alumno::operator=(const Alumno& orig) {
    codigo = orig.codigo;
    nombre = orig.nombre;
    apellido = orig.apellido;
    edad = orig.edad;
    ciclo = orig.ciclo;
    promedio = orig.promedio;
    
    return *this;
}

bool Alumno::operator<(const Alumno& alumno) const {
    return promedio < alumno.promedio;
}

bool Alumno::operator>(const Alumno& alumno) const {
    return promedio > alumno.promedio;
}

void Alumno::cargar(ifstream& archivo) {
    archivo >> codigo;
    archivo.ignore();
    getline(archivo, nombre, ',');
    getline(archivo, apellido, ',');
    archivo >> edad;
    archivo.ignore();
    archivo >> ciclo;
    archivo.ignore();
    archivo >> promedio;
    archivo.ignore();
}

void Alumno::imprimir(ofstream& archivo) const {
    archivo << setw(10) << codigo << setw(20) << nombre << setw(20) << apellido << setw(5) << edad << setw(5) << ciclo << setw(5) << promedio;
}

ifstream& operator>>(ifstream& archivo, Alumno& alumno) {
    alumno.cargar(archivo);
    return archivo;
}

ofstream& operator<<(ofstream& archivo, const Alumno& alumno) {
    alumno.imprimir(archivo);
    return archivo;
}

Alumno::~Alumno() {
}
