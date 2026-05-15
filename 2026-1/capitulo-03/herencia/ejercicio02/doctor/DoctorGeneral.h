//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO02_DOCTORGENERAL_H
#define EJERCICIO02_DOCTORGENERAL_H

#include "Doctor.h"

class DoctorGeneral : public Doctor {
public:
    DoctorGeneral();
    DoctorGeneral(const DoctorGeneral&);

    DoctorGeneral& operator=(const DoctorGeneral&);

    ifstream& leer(ifstream&);
    ofstream& imprimir(ofstream&) const;
};

ifstream& operator>>(ifstream&, DoctorGeneral&);
ofstream& operator<<(ofstream&, const DoctorGeneral&);


#endif //EJERCICIO02_DOCTORGENERAL_H

