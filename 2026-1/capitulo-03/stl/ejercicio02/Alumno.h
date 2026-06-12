//
// Created by Eric Huiza on 6/12/26.
//

#ifndef EJERCICIO02_ALUMNO_H
#define EJERCICIO02_ALUMNO_H

#include <string>
#include <vector>
#include "Curso.h"

using namespace std;

class Alumno {
    int codigo;
    string nombre;
    int edad;
    int ciclo;
    string facultad;

    vector<Curso> cursos;
public:
    Alumno() : codigo(0), edad(0), ciclo(0) {};

    int getCodigo() const;
    string getNombre() const;
    int getEdad() const;
    int getCiclo() const;
    string getFacultad() const;
    vector<Curso> getCursos() const;

    void setCodigo(int codigo);
    void setNombre(string nombre);
    void setEdad(int edad);
    void setCiclo(int ciclo);
    void setFacultad(string facultad);
    void setCursos(vector<Curso> curso);
};


#endif //EJERCICIO02_ALUMNO_H
