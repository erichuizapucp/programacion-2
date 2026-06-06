//
// Created by Eric Huiza on 5/8/26.
//

#ifndef EJERCICIO01_PACIENTE_H
#define EJERCICIO01_PACIENTE_H

#include "../Persona.h"

using namespace std;

class Paciente : public Persona {
    int edad;
    char genero;
protected:
    ifstream& leer(ifstream&) override;
    ofstream& imprimir(ofstream&) const override;
public:
    Paciente();
    Paciente(const Paciente&);

    int getEdad() const;
    char getGenero() const;

    void setEdad(int);
    void setGenero(char);

    Paciente& operator=(const Paciente&);

    ~Paciente() override = default;
};

#endif //EJERCICIO01_PACIENTE_H
