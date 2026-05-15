//
// Created by Eric Huiza on 5/8/26.
//

#ifndef EJERCICIO01_DOCTOR_H
#define EJERCICIO01_DOCTOR_H
#include "../Persona.h"

using namespace std;

class Doctor : public Persona {
public:
    Doctor();
    Doctor(const Doctor&);

    Doctor& operator=(const Doctor&);

    ifstream& leer(ifstream&);
    ofstream& imprimir(ofstream&) const;

    ~Doctor();
};

ifstream& operator>> (ifstream&, Doctor&);
ofstream& operator<< (ofstream&, const Doctor&);


#endif //EJERCICIO01_DOCTOR_H
