//
// Created by Eric Huiza on 5/2/26.
//

#include "Alumno.h"

void Alumno::imprimir() {
    cout << "DNI: " << dni << endl;
    cout << "Código: " << codigo << endl;
    // cout << "Nombre: " << nombre << endl;
    // cout << "Facultad: " << facultad << endl;
    // cout << "Ciclo: " << ciclo << endl;
}

Alumno::Alumno() {
    dni = 0;
    codigo = -1;
    nombre = nullptr;
    facultad = nullptr;
    ciclo = 0;
}

Alumno::Alumno(int dni, int codigo) : Alumno() {
    this->dni = dni;
    this->codigo = codigo;
}

Alumno::Alumno(const Alumno& origin) {
    *this = origin;
}

int Alumno::getDni() const {
    return dni;
}

void Alumno::setDni(int dni) {
    this->dni = dni;
}

int Alumno::getCodigo() const {
    return codigo;
}
void Alumno::setCodigo(int codigo) {
    this->codigo = codigo;
}

char* Alumno::getNombre() const {
    return nombre;
}

void Alumno::setNombre(char* nombre) {
    delete[] this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

char* Alumno::getFacultad() const {
    return facultad;
}

void Alumno::setFacultad(char* facultad) {
    delete[] this->facultad;
    this->facultad = new char[strlen(facultad) + 1];
    strcpy(this->facultad, facultad);
}

int Alumno::getCiclo() const {
    return ciclo;
}

void Alumno::setCiclo(int ciclo) {
    this->ciclo = ciclo;
}

Alumno& Alumno::operator=(const Alumno& origin) {
    if (this != &origin) {
        this->setDni(origin.getDni());
        this->setCodigo(origin.getCodigo());
        this->setNombre(origin.getNombre());
        this->setFacultad(origin.getFacultad());
        this->setCiclo(origin.getCiclo());
    }
    return *this;
}

Alumno::~Alumno() {
    delete[] nombre;
    delete[] facultad;
}