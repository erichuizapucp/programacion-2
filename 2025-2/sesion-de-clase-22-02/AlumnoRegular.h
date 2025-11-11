//
// Created by Eric Huiza on 11/7/25.
//

#ifndef SESION_DE_CLASE_22_01_ALUMNOREGULAR_H
#define SESION_DE_CLASE_22_01_ALUMNOREGULAR_H
#include "Alumno.h"

using namespace std;
class AlumnoRegular : public Alumno {
    string facultad;
    int ciclo {};
public:
    unique_ptr<Alumno> clonar() const override;

    istream& leer(istream &) override;
    ostream& imprimir(ostream &) const override;
};


#endif //SESION_DE_CLASE_22_01_ALUMNOREGULAR_H