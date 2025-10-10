//
// Created by Eric Huiza on 10/10/25.
//

#include "Alumno.h"

Alumno::Alumno() {
    cout << "Alumno: Constructor()" << endl;

    nombre = nullptr;
    dni = nullptr;
    codigo = 0;
}

Alumno::Alumno(
    char* nombre,
    char* dni,
    int codigo)
    : Alumno() {

    cout << "Alumno: Constructor(char*, char*, int)" << endl;

    this->setNombre(nombre);
    this->setDni(dni);
    this->codigo = codigo;
}

Alumno::Alumno(const Alumno& origen) : Alumno() {
    *this = origen;
}

char* Alumno::getNombre() const {
    return nombre;
}

void Alumno::setNombre(char* nombre) {
    setCadena(nombre, this->nombre);
    // delete[] this->nombre;
    // if (nombre) {
    //     this->nombre = new char[strlen(nombre) + 1];
    //     strcpy(this->nombre, nombre);
    // }
    // else {
    //     this->nombre = nullptr;
    // }
}

char* Alumno::getDni() const {
    return dni;
}

void Alumno::setDni(char* dni) {
    setCadena(dni, this->dni);
    // delete[] this->dni;
    // if (dni) {
    //     this->dni = new char[strlen(dni) + 1];
    //     strcpy(this->dni, dni);
    // }
    // else {
    //     this->dni = nullptr;
    // }
}

int Alumno::getCodigo() const {
    return codigo;
}

void Alumno::setCodigo(int codigo) {
    this->codigo = codigo;
}

Alumno& Alumno::operator=(const Alumno& origen) {
    if (this == &origen) {
        return *this;
    }
    this->setNombre(origen.getNombre());
    this->setDni(origen.getDni());
    this->codigo = origen.getCodigo();

    return *this;
}

void Alumno::imprimir() {
    cout << "DNI: " << this-> dni << endl;
    cout << "Nombre: " << this->nombre << endl;
    cout << "Código: " << this->codigo << endl;
}

Alumno::~Alumno() {
    cout << "Alumno: Destructor()" << endl;

    delete[] this->nombre;
    delete[] this->dni;
}

