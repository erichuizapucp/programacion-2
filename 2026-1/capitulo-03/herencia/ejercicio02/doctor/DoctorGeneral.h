//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO02_DOCTORGENERAL_H
#define EJERCICIO02_DOCTORGENERAL_H

#include "Doctor.h"

class DoctorGeneral : public Doctor {
    int consultorio;
public:
    DoctorGeneral();
    DoctorGeneral(const DoctorGeneral&);

    int getConsultorio() const;
    void setConsultorio(int);

    DoctorGeneral& operator=(const DoctorGeneral&);

    ifstream& leer(ifstream&);
    ofstream& imprimir(ofstream&) const;

    ~DoctorGeneral() = default;
};

ifstream& operator>>(ifstream&, DoctorGeneral&);
ofstream& operator<<(ofstream&, const DoctorGeneral&);


#endif //EJERCICIO02_DOCTORGENERAL_H

