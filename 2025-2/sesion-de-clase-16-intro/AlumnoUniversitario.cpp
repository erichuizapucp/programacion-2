//
// Created by Eric Huiza on 10/10/25.
//

#include "AlumnoUniversitario.h"

AlumnoUniversitario::AlumnoUniversitario() : Alumno() {
    this->facultad = nullptr;
    this->ciclo = 0;
}

AlumnoUniversitario::AlumnoUniversitario(
    char* nombre,
    char* dni,
    int codigo,
    char* facultad,
    int ciclo)
    : Alumno(nombre, dni, codigo),
      facultad(nullptr),
      ciclo(0) {

    cout << "AlumnoUniversitario: Constructor(char*, char*, int, char*, int)" << endl;

    this->setFacultad(facultad);
    this->ciclo = ciclo;
}

AlumnoUniversitario::AlumnoUniversitario(
    const AlumnoUniversitario& origen)
    : Alumno(origen), facultad(nullptr), ciclo(0) {
    *this = origen;
}

char* AlumnoUniversitario::getFacultad() const {
    return facultad;
}

void AlumnoUniversitario::setFacultad(char* facultad) {
    setCadena(facultad, this->facultad);
    // delete[] this->facultad;
    // if (facultad) {
    //     this->facultad = new char[strlen(facultad) + 1];
    //     strcpy(this->facultad, facultad);
    // }
    // else {
    //     this->facultad = nullptr;
    // }
}

int AlumnoUniversitario::getCiclo() const {
    return ciclo;
}

void AlumnoUniversitario::setCiclo(int ciclo) {
    this->ciclo = ciclo;
}

AlumnoUniversitario& AlumnoUniversitario::operator=(
    const AlumnoUniversitario& origen) {

    if (this == &origen) {
        return *this;
    }

    Alumno::operator=(origen);
    this->setFacultad(origen.getFacultad());
    this->ciclo = origen.ciclo;

    return *this;
}

void AlumnoUniversitario::imprimir() {
    Alumno::imprimir();
    cout << "Facultad: " << getFacultad() << endl;
    cout << "Ciclo: " << getCiclo() << endl;
}

AlumnoUniversitario::~AlumnoUniversitario() {
    cout << "AlumnoUniversitario: Destructor()" << endl;

    delete[] this->facultad;
}
