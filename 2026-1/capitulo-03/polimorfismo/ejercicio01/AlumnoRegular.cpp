//
// Created by Eric Huiza on 5/30/26.
//

#include "AlumnoRegular.h"

AlumnoRegular::AlumnoRegular() {
    numCreditos  = 0;
}

AlumnoRegular::AlumnoRegular(int dni, int edad, int codigo,
    int ciclo, int numCreditos) : Alumno(dni, edad, codigo, ciclo) {

    this->numCreditos = numCreditos;
}

void AlumnoRegular::imprimir() const {
    cout << "DNI: " << getDni() << endl;
    cout << "Edad: " << getEdad() << endl;
    cout << "Codigo: " << getCodigo() << endl;
    cout << "Ciclo: " << getCiclo() << endl;
    cout << "Num. Creditos: " << numCreditos << endl;
}

AlumnoRegular::~AlumnoRegular() {
    cout << "Destructor del alumno regular" << endl;
}
