//
// Created by Eric Huiza on 5/15/26.
//

#include "DoctorGeneral.h"

DoctorGeneral::DoctorGeneral() : Doctor() {
}

DoctorGeneral::DoctorGeneral(const DoctorGeneral& origin) : Doctor(origin) {
}

DoctorGeneral& DoctorGeneral::operator=(const DoctorGeneral& origin) {
    if (this != &origin) {
        Doctor::operator=(origin);
    }
    return *this;
}

ifstream& DoctorGeneral::leer(ifstream& archivo) {
    if (!Doctor::leer(archivo)) {
        return archivo;
    }

    char* descartado = leerCadena(archivo, '\n');
    delete[] descartado;

    return archivo;
}

ofstream& DoctorGeneral::imprimir(ofstream& archivo) const {
    archivo << "Tipo Doctor: GENERAL" << endl;
    Doctor::imprimir(archivo);

    return archivo;
}

ifstream& operator>>(ifstream& archivo, DoctorGeneral& doctor) {
    return doctor.leer(archivo);
}

ofstream& operator<<(ofstream& archivo, const DoctorGeneral& doctor) {
    return doctor.imprimir(archivo);
}

