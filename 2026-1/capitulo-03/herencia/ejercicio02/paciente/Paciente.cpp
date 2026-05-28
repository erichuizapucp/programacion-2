//
// Created by Eric Huiza on 5/8/26.
//

#include "Paciente.h"

Paciente::Paciente() {
    edad = 0;
    genero = 0;
}

Paciente::Paciente(const Paciente& origin) : Paciente() {
    *this = origin;
}

int Paciente::getEdad() const {
    return edad;
}

char Paciente::getGenero() const {
    return genero;
}

void Paciente::setEdad(int edad) {
    this->edad = edad;
}

void Paciente::setGenero(char genero) {
    this->genero = genero;
}

Paciente& Paciente::operator=(const Paciente& origin) {
    if (this != &origin) {
        Persona::operator=(origin);
        this->setEdad(origin.getEdad());
        this->setGenero(origin.getGenero());
    }
    return *this;
}

ifstream& Paciente::leer(ifstream& archivo) {
    if (!Persona::leer(archivo)) {
        return archivo;
    }

    int edad;
    char genero;
    archivo >> edad;
    archivo.ignore();
    archivo >> genero;
    archivo.ignore();

    this->setEdad(edad);
    this->setGenero(genero);

    return archivo;
}

ofstream& Paciente::imprimir(ofstream& os) const {
    Persona::imprimir(os);
    os << "Edad: " << this->getEdad() << endl;
    os << "Genero: " << this->getGenero() << endl;

    return os;
}

ifstream& operator>>(ifstream& archivo, Paciente& paciente) {
    return paciente.leer(archivo);
}

ofstream& operator<<(ofstream& os, const Paciente& paciente) {
    return paciente.imprimir(os);
}

