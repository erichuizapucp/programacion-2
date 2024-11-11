/* 
 * File:   AlumnoIntercambio.cpp
 * Author: erichuiza
 * 
 * Created on November 11, 2024, 3:19 PM
 */

#include "AlumnoIntercambio.h"

AlumnoIntercambio::AlumnoIntercambio() {
    paisOrigen = {};
    universidadOrigen = {};
    duracion = {};
}

AlumnoIntercambio::AlumnoIntercambio(const AlumnoIntercambio& orig) {
    *this = orig;
}

Alumno* AlumnoIntercambio::clonar() {
    return new AlumnoIntercambio(*this);
}

void AlumnoIntercambio::operator=(const AlumnoIntercambio& orig) {
    Alumno::operator =(orig);
    
    paisOrigen = orig.paisOrigen;
    universidadOrigen = orig.universidadOrigen;
    duracion = orig.duracion;
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

AlumnoIntercambio::~AlumnoIntercambio() {
}

