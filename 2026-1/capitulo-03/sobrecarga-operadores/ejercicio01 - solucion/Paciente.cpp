//
// Created by Eric Huiza on 5/8/26.
//

#include "Paciente.h"
#include "funciones.h"

Paciente::Paciente() {
    dni = 0;
    nombre = nullptr;
    edad = 0;
    genero = 0;
}

Paciente::Paciente(const Paciente& origin) : Paciente() {
    *this = origin;
}

int Paciente::getDni() const {
    return dni;
}

char* Paciente::getNombre() const {
    return nombre;
}

int Paciente::getEdad() const {
    return edad;
}

char Paciente::getGenero() const {
    return genero;
}

void Paciente::setDni(int dni) {
    this->dni = dni;
}

void Paciente::setNombre(char* nombre) {
    delete[] this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Paciente::setEdad(int edad) {
    this->edad = edad;
}

void Paciente::setGenero(char genero) {
    this->genero = genero;
}

Paciente& Paciente::operator=(const Paciente& origin) {
    if (this != &origin) {
        this->setDni(origin.getDni());
        this->setNombre(origin.getNombre());
        this->setEdad(origin.getEdad());
        this->setGenero(origin.getGenero());
    }
    return *this;
}

Paciente::~Paciente() {
    delete[] this->nombre;
}

ofstream& operator<<(ofstream& os, const Paciente& paciente) {
    os << "DNI: " << paciente.getDni() << endl;
    os << "Nombre: " << paciente.getNombre() << endl;
    os << "Edad: " << paciente.getEdad() << endl;
    os << "Genero: " << paciente.getGenero() << endl;

    return os;
}

ifstream& operator>>(ifstream& archivo, Paciente& paciente) {
    int dni;
    char* nombre;
    int edad;
    char genero;
    if (archivo >> dni) {
        archivo.ignore();
        nombre = leerCadena(archivo);
        archivo >> edad;
        archivo.ignore();
        archivo >> genero;
        archivo.ignore();

        paciente.setDni(dni);
        paciente.setNombre(nombre);
        paciente.setEdad(edad);
        paciente.setGenero(genero);
    }

    return archivo;
}