//
// Created by Eric Huiza on 5/30/26.
//

#ifndef EJERCICIO01_ALUMNOINTERCAMBIO_H
#define EJERCICIO01_ALUMNOINTERCAMBIO_H
#include "Alumno.h"

#include <iostream>

using namespace std;

class AlumnoIntercambio : public Alumno {
    int estancia;
public:
    AlumnoIntercambio();
    AlumnoIntercambio(int dni, int edad, int ciclo, int creditos, int estancia);

    void imprimir() const override;

    ~AlumnoIntercambio() override;
};

inline AlumnoIntercambio::~AlumnoIntercambio() {
    cout << "destructor del alumno de intercambio" << endl;
}


#endif //EJERCICIO01_ALUMNOINTERCAMBIO_H
