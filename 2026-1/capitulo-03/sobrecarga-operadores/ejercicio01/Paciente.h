//
// Created by Eric Huiza on 5/8/26.
//

#ifndef EJERCICIO01_PACIENTE_H
#define EJERCICIO01_PACIENTE_H

#include <fstream>

using namespace std;

class Paciente {
    int dni;
    char* nombre;
    int edad;
    char genero;
public:
    Paciente();
    Paciente(const Paciente&);

    int getDni() const;
    char* getNombre() const;
    int getEdad() const;
    char getGenero() const;

    void setDni(int);
    void setNombre(char*);
    void setEdad(int);
    void setGenero(char);

    Paciente& operator=(const Paciente&);

    ~Paciente();
};

ifstream& operator>>(ifstream&, Paciente&);
ofstream& operator<<(ofstream&, const Paciente&);

#endif //EJERCICIO01_PACIENTE_H
