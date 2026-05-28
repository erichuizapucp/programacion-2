//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO02_DOCTORESPECIALISTA_H
#define EJERCICIO02_DOCTORESPECIALISTA_H

#include "Doctor.h"
#include "../enums.h"
#include "../funciones.h"

class DoctorEspecialista : public Doctor {
    Especialidad especialidad;
public:
    DoctorEspecialista();
    DoctorEspecialista(const DoctorEspecialista&);

    Especialidad getEspecialidad() const;
    void setEspecialidad(Especialidad);

    DoctorEspecialista& operator=(const DoctorEspecialista&);

    ifstream& leer(ifstream&);
    ofstream& imprimir(ofstream&) const;
};

ifstream& operator>>(ifstream&, DoctorEspecialista&);
ofstream& operator<<(ofstream&, const DoctorEspecialista&);


#endif //EJERCICIO02_DOCTORESPECIALISTA_H

