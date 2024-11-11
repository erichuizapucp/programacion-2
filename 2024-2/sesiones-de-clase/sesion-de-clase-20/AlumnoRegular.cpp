/* 
 * File:   AlumnoRegular.cpp
 * Author: erichuiza
 * 
 * Created on November 11, 2024, 10:34 AM
 */

#include "AlumnoRegular.h"

AlumnoRegular::AlumnoRegular() : Alumno() {
    annoIngreso = {};
}

AlumnoRegular::AlumnoRegular(const AlumnoRegular& orig) : Alumno(orig) {
    *this = orig;
}

char AlumnoRegular::getTipo() const {
    return 'R';
}

Alumno* AlumnoRegular::clonar() {
    return new AlumnoRegular(*this);
}

void AlumnoRegular::cargar(ifstream& archivo) {
    Alumno::cargar(archivo);
    archivo >> annoIngreso;
}

void AlumnoRegular::imprimir(ofstream& archivo) const {
    Alumno::imprimir(archivo);
    archivo << setw(5) << annoIngreso << endl;
}

void AlumnoRegular::operator=(const AlumnoRegular& alumno) {
    Alumno::operator =(alumno);
    annoIngreso = alumno.annoIngreso;
}

AlumnoRegular::~AlumnoRegular() {
}

