//
// Created by Eric Huiza on 5/8/26.
//

#include "Doctor.h"

Doctor::Doctor() {
}

Doctor::Doctor(const Doctor& origin) : Persona(origin) {
    *this = origin;
}

Doctor& Doctor::operator=(const Doctor& doctor) {
    if (this != &doctor) {
        Persona::operator=(doctor);
    }
    return *this;
}

ifstream& Doctor::leer(ifstream& archivo) {
    if (!Persona::leer(archivo)) {
        return archivo;
    }
    return archivo;
}

ofstream& Doctor::imprimir(ofstream& os) const {
    Persona::imprimir(os);

    return os;
}

ifstream& operator>> (ifstream& archivo, Doctor& doctor) {
    return doctor.leer(archivo);
}

ofstream& operator<< (ofstream& os, const Doctor& doctor) {
    return doctor.imprimir(os);
}