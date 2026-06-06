//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO02_PACIENTEPARTICULAR_H
#define EJERCICIO02_PACIENTEPARTICULAR_H

#include "Paciente.h"

class PacienteParticular : public Paciente {
    char categoria;
protected:
    ifstream& leer(ifstream&) override;
    ofstream& imprimir(ofstream&) const override;
public:
    PacienteParticular();
    PacienteParticular(const PacienteParticular&);

    char getCategoria() const;
    void setCategoria(char);

    PacienteParticular& operator=(const PacienteParticular&);

    ~PacienteParticular() override = default;
};

#endif //EJERCICIO02_PACIENTEPARTICULAR_H
