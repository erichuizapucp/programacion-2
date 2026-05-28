//
// Created by Eric Huiza on 5/15/26.
//

#ifndef EJERCICIO02_PACIENTEPARTICULAR_H
#define EJERCICIO02_PACIENTEPARTICULAR_H

#include "Paciente.h"

class PacienteParticular : public Paciente {
    char categoria;
public:
    PacienteParticular();
    PacienteParticular(const PacienteParticular&);

    char getCategoria() const;
    void setCategoria(char);

    PacienteParticular& operator=(const PacienteParticular&);

    ifstream& leer(ifstream&);
    ofstream& imprimir(ofstream&) const;

    ~PacienteParticular() = default;
};

ifstream& operator>>(ifstream&, PacienteParticular&);
ofstream& operator<<(ofstream&, const PacienteParticular&);


#endif //EJERCICIO02_PACIENTEPARTICULAR_H

