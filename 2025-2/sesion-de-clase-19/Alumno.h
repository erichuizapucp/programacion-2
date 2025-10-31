//
// Created by Eric Huiza on 10/24/25.
//

#ifndef SESION_DE_CLASE_18_ALUMNO_H
#define SESION_DE_CLASE_18_ALUMNO_H

#include "Registro.h"
#include <iomanip>

using namespace std;

class Alumno : public Registro {
    int codigo;
    char* nombre;
    double creditos;
public:
    Alumno();
    Alumno(int, char*, double);
    Alumno(const Alumno&);

    int getCodigo() const;
    char* getNombre() const;
    double getCreditos() const;

    void setCodigo(int);
    void setNombre(char*);
    void setCreditos(double);

    Alumno& operator=(const Alumno&);

    virtual istream& leer(istream&);
    virtual ostream& imprimir(ostream&) const;

    virtual ~Alumno();
};

#endif //SESION_DE_CLASE_18_ALUMNO_H