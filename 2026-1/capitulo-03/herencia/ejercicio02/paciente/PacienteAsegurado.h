//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO02_PACIENTEASEGURADO_H
#define EJERCICIO02_PACIENTEASEGURADO_H

#include "Paciente.h"

class PacienteAsegurado : public Paciente {
    char* aseguradora;
    char* plan;
public:
    PacienteAsegurado();
    PacienteAsegurado(const PacienteAsegurado&);

    char* getAseguradora() const;
    char* getPlan() const;

    void setAseguradora(char*);
    void setPlan(char*);

    ifstream& leer(ifstream&);
    ofstream& imprimir(ofstream&) const;

    PacienteAsegurado& operator=(const PacienteAsegurado&);

    ~PacienteAsegurado();
};

ifstream& operator>>(ifstream&, PacienteAsegurado&);
ofstream& operator<<(ofstream&, const PacienteAsegurado&);


#endif //EJERCICIO02_PACIENTEASEGURADO_H
