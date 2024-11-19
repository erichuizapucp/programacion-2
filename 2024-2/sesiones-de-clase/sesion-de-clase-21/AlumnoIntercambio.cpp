/* 
 * File:   AlumnoIntercambio.cpp
 * Author: erichuiza
 * 
 * Created on November 11, 2024, 10:18 AM
 */

#include "AlumnoIntercambio.h"

AlumnoIntercambio::AlumnoIntercambio() : Alumno() {
    paisOrigen = {};
    universidadOrigen = {};
    duracion = {};
}

AlumnoIntercambio::AlumnoIntercambio(const AlumnoIntercambio& orig) : Alumno(orig) {
    *this = orig;
}

char AlumnoIntercambio::getTipo() const {
    return 'I';
}

Alumno* AlumnoIntercambio::clonar() {
    return new AlumnoIntercambio(*this);
}

void AlumnoIntercambio::cargar(ifstream& archivo) {
    Alumno::cargar(archivo);
    getline(archivo, paisOrigen, ',');
    getline(archivo, universidadOrigen, ',');
    archivo >> duracion;
    archivo.ignore();
}

void AlumnoIntercambio::imprimir(ofstream& archivo) const {
    Alumno::imprimir(archivo);
    archivo << setw(10) << paisOrigen << setw(20) << universidadOrigen << setw(5) << duracion << endl;
}

AlumnoIntercambio& AlumnoIntercambio::operator=(const AlumnoIntercambio& orig) {
    Alumno::operator =(orig);
    paisOrigen = orig.paisOrigen;
    universidadOrigen = orig.universidadOrigen;
    duracion = orig.duracion;
    
    return *this;
}

AlumnoIntercambio::~AlumnoIntercambio() {
}

