//
// Created by Eric Huiza on 11/10/25.
//

#ifndef SESION_DE_CLASE_22_01_COMPARADORALUMNOS_H
#define SESION_DE_CLASE_22_01_COMPARADORALUMNOS_H

#include "AlumnoInfo.h"
#include "SortOrder.h"

using namespace std;
class ComparadorAlumnos {
    SortOrder sortOrder;
public:
    ComparadorAlumnos();
    ComparadorAlumnos(SortOrder);
    bool operator()(const AlumnoInfo&, const AlumnoInfo&) const;
};


#endif //SESION_DE_CLASE_22_01_COMPARADORALUMNOS_H