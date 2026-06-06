//
// Created by Eric Huiza on 5/15/26.
//

#include "DoctorGeneral.h"

DoctorGeneral::DoctorGeneral() {
    consultorio = 0;
}

DoctorGeneral::DoctorGeneral(const DoctorGeneral& origin) : DoctorGeneral() {
    *this = origin;
}

int DoctorGeneral::getConsultorio() const {
    return consultorio;
}

void DoctorGeneral::setConsultorio(int consultorio) {
    this->consultorio = consultorio;
}

DoctorGeneral& DoctorGeneral::operator=(const DoctorGeneral& origin) {
    if (this != &origin) {
        Doctor::operator=(origin);
        this->setConsultorio(origin.getConsultorio());
    }
    return *this;
}

ifstream& DoctorGeneral::leer(ifstream& archivo) {
    if (!Doctor::leer(archivo)) {
        return archivo;
    }

    int consultorio;
    archivo >> consultorio;
    this->setConsultorio(consultorio);

    return archivo;
}

ofstream& DoctorGeneral::imprimir(ofstream& archivo) const {
    archivo << "Tipo Doctor: GENERAL" << endl;
    Doctor::imprimir(archivo);
    archivo << "Consultorio: " << this->getConsultorio() << endl;

    return archivo;
}

Especialidad DoctorGeneral::getEspecialidad() const {
    return GENERAL;
}
