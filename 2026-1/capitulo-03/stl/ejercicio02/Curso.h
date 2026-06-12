//
// Created by Eric Huiza on 6/12/26.
//

#ifndef EJERCICIO02_CURSO_H
#define EJERCICIO02_CURSO_H

#include <string>

using namespace std;

class Curso {
    int codigo;
    string nombre;
    int ciclo;
public:
    Curso() : codigo(0), ciclo(0) {};

    int getCodigo() const;
    string getNombre() const;
    int getCiclo() const;

    void setCodigo(int codigo);
    void setNombre(string nombre);
    void setCiclo(int ciclo);

};


#endif //EJERCICIO02_CURSO_H
