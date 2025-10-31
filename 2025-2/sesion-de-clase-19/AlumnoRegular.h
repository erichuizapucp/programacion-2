//
// Created by Eric Huiza on 10/24/25.
//

#ifndef SESION_DE_CLASE_18_ALUMNOREGULAR_H
#define SESION_DE_CLASE_18_ALUMNOREGULAR_H

#include "Alumno.h"

using namespace std;

class AlumnoRegular : public Alumno {
    int ciclo;
public:
    AlumnoRegular();
    AlumnoRegular(int, char*, double, int);
    AlumnoRegular(const AlumnoRegular&);

    AlumnoRegular& operator=(const AlumnoRegular&);
    istream& leer(istream&);
    ostream& imprimir(ostream&) const;
};


#endif //SESION_DE_CLASE_18_ALUMNOREGULAR_H