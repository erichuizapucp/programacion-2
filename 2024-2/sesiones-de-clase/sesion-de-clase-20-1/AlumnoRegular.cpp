/* 
 * File:   AlumnoRegular.cpp
 * Author: erichuiza
 * 
 * Created on November 11, 2024, 3:18 PM
 */

#include "AlumnoRegular.h"

AlumnoRegular::AlumnoRegular() : Alumno() {
    annoIngreso = {};
}

AlumnoRegular::AlumnoRegular(const AlumnoRegular& orig) : Alumno(orig) {
    *this = orig;
}

Alumno* AlumnoRegular::clonar() {
    return new AlumnoRegular(*this);
}

void AlumnoRegular::operator=(const AlumnoRegular& orig) {
    Alumno::operator =(orig);
    annoIngreso = orig.annoIngreso;
}

void AlumnoRegular::cargar(ifstream& archivo) {
    Alumno::cargar(archivo);
    archivo >> annoIngreso;
}

void AlumnoRegular::imprimir(ofstream& archivo) const {
    Alumno::imprimir(archivo);
    archivo << setw(5) << annoIngreso << endl;
}

AlumnoRegular::~AlumnoRegular() {
}

