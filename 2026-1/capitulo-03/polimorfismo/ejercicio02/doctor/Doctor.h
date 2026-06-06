//
// Created by Eric Huiza on 5/8/26.
//

#ifndef EJERCICIO01_DOCTOR_H
#define EJERCICIO01_DOCTOR_H

#include "../enums.h"
#include "../Persona.h"

using namespace std;

class Doctor : public Persona {
protected:
    ifstream& leer(ifstream&) override;
    ofstream& imprimir(ofstream&) const override;
public:
    Doctor();
    Doctor(const Doctor&);

    virtual Especialidad getEspecialidad() const = 0;

    Doctor& operator=(const Doctor&);

    ~Doctor() override = default;
};

#endif //EJERCICIO01_DOCTOR_H
