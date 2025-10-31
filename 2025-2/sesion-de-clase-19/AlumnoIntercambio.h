//
// Created by Eric Huiza on 10/24/25.
//

#ifndef SESION_DE_CLASE_18_ALUMNOINTERCAMBIO_H
#define SESION_DE_CLASE_18_ALUMNOINTERCAMBIO_H

#include <iostream>

#include "Alumno.h"

using namespace std;

class AlumnoIntercambio : public Alumno {
    char* paisOrigen;
    int duracion;
public:
    AlumnoIntercambio();
    AlumnoIntercambio(int, char*, double, char*, int);
    AlumnoIntercambio(const AlumnoIntercambio&);

    char* getPaisOrigen() const;
    int getDuracion() const;

    void setPaisOrigen(char*);
    void setDuracion(int);

    AlumnoIntercambio& operator=(const AlumnoIntercambio&);
    istream& leer(istream&) override;
    ostream& imprimir(ostream&) const override;

    ~AlumnoIntercambio();
};


#endif //SESION_DE_CLASE_18_ALUMNOINTERCAMBIO_H