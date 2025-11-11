//
// Created by Eric Huiza on 11/7/25.
//

#ifndef SESION_DE_CLASE_22_01_ALUMNOINTERCAMBIO_H
#define SESION_DE_CLASE_22_01_ALUMNOINTERCAMBIO_H
#include "Alumno.h"
#include <string>

using namespace std;
class AlumnoIntercambio : public Alumno {
    string pais;
    int duracion {};
public:
    unique_ptr<Alumno> clonar() const override;

    istream& leer(istream &) override;
    ostream& imprimir(ostream &) const override;
};


#endif //SESION_DE_CLASE_22_01_ALUMNOINTERCAMBIO_H