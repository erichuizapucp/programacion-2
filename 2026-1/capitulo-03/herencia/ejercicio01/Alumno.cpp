//
// Created by Eric Huiza on 5/13/26.
//

#include "Alumno.h"

Alumno::Alumno() : Persona() {
    codigo = 0;
    facultad = nullptr;

    cout << "Se ejecutó el constructor de Alumno" << endl;
}

int Alumno::getCodigo() const {
    return codigo;
}
char* Alumno::getFacultad() const {
    return facultad;
}

void Alumno::setCodigo(int codigo) {
    this->codigo = codigo;
}

void Alumno::setFacultad(char* facultad) {
    delete[] this->facultad;
    this->facultad = new char[strlen(facultad) + 1];
    strcpy(this->facultad, facultad);
}

void Alumno::imprimir(ostream& os) const {
    Persona::imprimir(os);
    os << "Código: " << this->getCodigo() << endl;
    os << "Facultad: " << this->getFacultad() << endl;
}

ostream& operator<<(ostream& os, const Alumno& alumno) {
    alumno.imprimir(os);
    return os;
}

// Alumno(const Alumno&);
//
// void leer(ifstream&);
// void imprimir(ofstream&);

Alumno::~Alumno() {
    delete[] facultad;

    cout << "Se ejecutó el destructor de Alumno" << endl;
}