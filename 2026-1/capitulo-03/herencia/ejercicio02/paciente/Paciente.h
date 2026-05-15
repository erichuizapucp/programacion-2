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
public:
    Paciente();
    Paciente(const Paciente&);

    int getEdad() const;
    char getGenero() const;

    void setEdad(int);
    void setGenero(char);

    Paciente& operator=(const Paciente&);

    ifstream& leer(ifstream&);
    ofstream& imprimir(ofstream&) const;

    ~Paciente();
};

ifstream& operator>>(ifstream&, Paciente&);
ofstream& operator<<(ofstream&, const Paciente&);

#endif //EJERCICIO01_PACIENTE_H
