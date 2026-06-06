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
protected:
    ifstream& leer(ifstream&) override;
    ofstream& imprimir(ofstream&) const override;
public:
    DoctorEspecialista();
    DoctorEspecialista(const DoctorEspecialista&);

    Especialidad getEspecialidad() const override;
    void setEspecialidad(Especialidad);

    DoctorEspecialista& operator=(const DoctorEspecialista&);
};

#endif //EJERCICIO02_DOCTORESPECIALISTA_H

