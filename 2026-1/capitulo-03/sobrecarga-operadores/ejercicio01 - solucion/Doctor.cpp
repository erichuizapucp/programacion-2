//
// Created by Eric Huiza on 5/8/26.
//

#include "Doctor.h"
#include "funciones.h"

Doctor::Doctor() {
    dni = 0;
    nombre = nullptr;
    especialidad = GENERAL;
}

Doctor::Doctor(const Doctor& origin) : Doctor() {
    *this = origin;
}

int Doctor::getDni() const {
    return dni;
}

char* Doctor::getNombre() const {
    return nombre;
}

Especialidad Doctor::getEspecialidad() const {
    return especialidad;
}

void Doctor::setDni(int dni) {
    this->dni = dni;
}

void Doctor::setNombre(char* nombre) {
    delete[] this->nombre;
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Doctor::setEspecialidad(Especialidad especialidad) {
    this->especialidad = especialidad;
}

Doctor& Doctor::operator=(const Doctor& origin) {
    if (this != &origin) {
        this->setDni(origin.getDni());
        this->setNombre(origin.getNombre());
        this->setEspecialidad(origin.getEspecialidad());
    }

    return *this;
}

Doctor::~Doctor() {
    delete[] this->nombre;
}

ifstream& operator>>(ifstream& archivo, Doctor& doctor) {
    int dni;
    if (archivo >> dni) {
        archivo.ignore();
        char *nombre = leerCadena(archivo);
        char *especialidad = leerCadena(archivo, '\n');

        doctor.setDni(dni);
        doctor.setNombre(nombre);
        doctor.setEspecialidad(convertirEspecialidad(especialidad));
        delete[] nombre;
        delete[] especialidad;

        return archivo;
    }

    return archivo;
}

ofstream& operator<<(ofstream& os, const Doctor& doctor) {
    os << "DNI: " << doctor.getDni() << endl;
    os << "Nombre: " << doctor.getNombre() << endl;
    imprimirEspecialidad(os, doctor.getEspecialidad());

    return os;
}