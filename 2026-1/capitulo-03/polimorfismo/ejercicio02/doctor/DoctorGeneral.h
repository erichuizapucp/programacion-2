//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO02_DOCTORGENERAL_H
#define EJERCICIO02_DOCTORGENERAL_H

#include "Doctor.h"

class DoctorGeneral : public Doctor {
    int consultorio;
protected:
    ifstream& leer(ifstream&) override;
    ofstream& imprimir(ofstream&) const override;
public:
    DoctorGeneral();
    DoctorGeneral(const DoctorGeneral&);

    int getConsultorio() const;
    void setConsultorio(int);

    Especialidad getEspecialidad() const override;

    DoctorGeneral& operator=(const DoctorGeneral&);

    ~DoctorGeneral() override = default;
};

#endif //EJERCICIO02_DOCTORGENERAL_H
