/* 
 * File:   Alumno.cpp
 * Author: erichuiza
 * 
 * Created on November 11, 2024, 3:17 PM
 */

#include "Alumno.h"

Alumno::Alumno() {
    nombre = {};
    apellido = {};
    edad = {};
    ciclo = {};
    cursos = {};
}

Alumno::Alumno(const Alumno& orig) {
    *this = orig;
}

Alumno::Alumno(Alumno&& orig) {
    *this = std::move(orig);
}

Alumno& Alumno::operator=(const Alumno& orig) {
    nombre = orig.nombre;
    apellido = orig.apellido;
    edad = orig.edad;
    ciclo = orig.ciclo;
    cursos = orig.cursos;
    
    return *this;
}

Alumno& Alumno::operator=(Alumno&& orig) {
    nombre = std::move(orig.nombre.);
    apellido = std::move(orig.apellido);
    edad = orig.edad;
    ciclo = std::move(orig.ciclo);
    cursos = std::move(orig.cursos);
    
    orig.edad = {};
    
    return *this;
}

void Alumno::cargar(ifstream& archivo) {
    getline(archivo, nombre, ',');
    getline(archivo, apellido, ',');
    archivo >> edad;
    archivo.ignore();
    archivo >> ciclo;
    archivo.ignore();
    
    // TODO: revisar al final de la clase o inicio de la siguiente.
    string curs;
    getline(archivo, curs, ',');
    stringstream ss(curs);
    string curso;
    while (getline(ss, curso, ' ')) {
        cursos.push_back(curso);
    }
}

void Alumno::imprimir(ofstream& archivo) const {
    archivo << setw(20) << nombre << setw(20) << apellido << setw(5) << edad << setw(5) << ciclo;
}

void operator>>(ifstream& archivo, Alumno& alumno) {
    alumno.cargar(archivo);
}

void operator<<(ofstream& archivo, const Alumno& alumno) {
    alumno.imprimir(archivo);
}

Alumno::~Alumno() {
}

