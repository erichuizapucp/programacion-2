//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO02_PACIENTEASEGURADO_H
#define EJERCICIO02_PACIENTEASEGURADO_H

#include "Paciente.h"

class PacienteAsegurado : public Paciente {
    char* aseguradora;
    char* plan;
protected:
    ifstream& leer(ifstream&) override;
    ofstream& imprimir(ofstream&) const override;
public:
    PacienteAsegurado();
    PacienteAsegurado(const PacienteAsegurado&);

    char* getAseguradora() const;
    char* getPlan() const;

    void setAseguradora(char*);
    void setPlan(char*);

    PacienteAsegurado& operator=(const PacienteAsegurado&);

    ~PacienteAsegurado() override;
};

#endif //EJERCICIO02_PACIENTEASEGURADO_H
