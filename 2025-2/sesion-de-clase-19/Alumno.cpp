//
// Created by Eric Huiza on 10/24/25.
//

#include "Alumno.h"

Alumno::Alumno() {
    codigo = 0;
    nombre = nullptr;
    creditos = 0.0;
}

Alumno::Alumno(int codigo, char* nombre, double creditos) : Alumno() {
    this->codigo = codigo;
    setCadena(this->nombre, nombre);
    this->creditos = creditos;
}

Alumno::Alumno(const Alumno& origen) : Alumno() {
    *this = origen;
}

int Alumno::getCodigo() const {
    return codigo;
}

char* Alumno::getNombre() const {
    return nombre;
}

double Alumno::getCreditos() const {
    return creditos;
}

void Alumno::setCodigo(int codigo) {
    this->codigo = codigo;
}

void Alumno::setNombre(char* facultad) {
    setCadena(this->nombre, facultad);
}

void Alumno::setCreditos(double creditos) {
    this->creditos = creditos;
}

Alumno& Alumno::operator=(const Alumno& origen) {
    if (this == &origen) {
        return *this;
    }

    this->setCodigo(origen.getCodigo());
    this->setNombre(origen.getNombre());
    this->setCreditos(origen.getCreditos());

    return *this;
}

istream& Alumno::leer(istream& archivo) {
    return archivo;
}

ostream& Alumno::imprimir(ostream& archivo) const {
    archivo << "Codigo: " << codigo << endl;
    archivo << "Nombre: " << nombre << endl;
    archivo << "Creditos: " << fixed << setprecision(2) << creditos << endl;

    return archivo;
}

Alumno::~Alumno() {
    cout << "Destructor Base" << endl;
    delete[] nombre;
}