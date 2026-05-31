//
// Created by Eric Huiza on 5/30/26.
//

#include "Alumno.h"

Alumno::Alumno() {
    codigo =  0;
    ciclo = 0;
}

Alumno::Alumno(int dni, int edad, int codigo, int ciclo) : Persona(dni, edad) {
    this->codigo = codigo;
    this->ciclo = ciclo;
}

int Alumno::getCodigo() const {
    return codigo;
}

int Alumno::getCiclo() const {
    return ciclo;
}

Alumno::~Alumno() {
    cout << "destructor del alumno." << endl;
}
