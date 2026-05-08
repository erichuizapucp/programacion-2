//
// Created by Eric Huiza on 5/2/26.
//

#ifndef EJERCICIO01_ALUMNO_H
#define EJERCICIO01_ALUMNO_H

#include <iostream>

using namespace std;

class Alumno {
    int dni;
    int codigo;
    char* nombre;
    char* facultad;
    int ciclo;
public:
    Alumno();
    Alumno(int dni, int codigo);
    Alumno(const Alumno&);

    int getDni() const;
    void setDni(int dni);

    int getCodigo() const;
    void setCodigo(int codigo);

    char* getNombre() const;
    void setNombre(char* nombre);

    char* getFacultad() const;
    void setFacultad(char* facultad);

    int getCiclo() const;
    void setCiclo(int ciclo);

    Alumno& operator=(const Alumno&);

    ~Alumno();

    void imprimir();
};


#endif //EJERCICIO01_ALUMNO_H
