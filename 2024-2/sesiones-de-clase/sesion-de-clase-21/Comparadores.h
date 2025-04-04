/* 
 * File:   Comparadores.h
 * Author: erichuiza
 *
 * Created on November 17, 2024, 11:10 PM
 */

#ifndef COMPARADORES_H
#define COMPARADORES_H

#include "AlumnoUniversitario.h"

class OrdenaAlumnoPorNombre {
public:
    bool operator()(const AlumnoUniversitario&, const AlumnoUniversitario&) const;
};

class OrdenaAlumnoPorCodigo {
public:
    bool operator()(const AlumnoUniversitario&, const AlumnoUniversitario&) const;
};

#endif /* COMPARADORES_H */

