/* 
 * File:   Alumno.cpp
 * Author: erichuiza
 * 
 * Created on November 11, 2024, 10:32 AM
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

void Alumno::operator=(const Alumno& orig) {
    nombre = orig.nombre;
    apellido = orig.apellido;
    edad = orig.edad;
    ciclo = orig.ciclo;
    cursos = orig.cursos;
}

void Alumno::cargar(ifstream& archivo) {
    getline(archivo, nombre, ',');
    getline(archivo, apellido, ',');
    archivo >> edad;
    archivo.ignore();
    archivo >> ciclo;
    archivo.ignore();
    
    string curs;
    getline(archivo, curs, ',');
    stringstream ss(curs);
    string curso;
    while (getline(ss, curso, ' ')) {
        cursos.push_back(curso);
        cout << curso << endl;
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
