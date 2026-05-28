//
// Created by Eric Huiza on 5/15/26.
//

#include "DoctorEspecialista.h"

DoctorEspecialista::DoctorEspecialista() {
    especialidad = GENERAL;
}

DoctorEspecialista::DoctorEspecialista(const DoctorEspecialista& origin) : DoctorEspecialista() {
    *this = origin;
}

Especialidad DoctorEspecialista::getEspecialidad() const {
    return especialidad;
}

void DoctorEspecialista::setEspecialidad(Especialidad especialidad) {
    this->especialidad = especialidad;
}

DoctorEspecialista& DoctorEspecialista::operator=(const DoctorEspecialista& origin) {
    if (this != &origin) {
        Doctor::operator=(origin);
        this->setEspecialidad(origin.getEspecialidad());
    }
    return *this;
}

ifstream& DoctorEspecialista::leer(ifstream& archivo) {
    if (!Doctor::leer(archivo)) {
        return archivo;
    }

    char* especialidad = leerCadena(archivo, '\n');
    this->setEspecialidad(convertirEspecialidad(especialidad));
    delete[] especialidad;

    return archivo;
}

ofstream& DoctorEspecialista::imprimir(ofstream& archivo) const {
    archivo << "Tipo Doctor: ESPECIALISTA" << endl;
    Doctor::imprimir(archivo);
    imprimirEspecialidad(archivo, especialidad);

    return archivo;
}

ifstream& operator>>(ifstream& archivo, DoctorEspecialista& doctor) {
    return doctor.leer(archivo);
}

ofstream& operator<<(ofstream& archivo, const DoctorEspecialista& doctor) {
    return doctor.imprimir(archivo);
}

