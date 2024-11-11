/* 
 * File:   AlumnoExtranjero.h
 * Author: erichuiza
 *
 * Created on October 11, 2024, 4:54 PM
 */

#ifndef ALUMNOEXTRANJERO_H
#define ALUMNOEXTRANJERO_H

#include "Alumno.h"


class AlumnoExtranjero : public Alumno {
private:
    char* paisOrigen;
public:
    AlumnoExtranjero();
    AlumnoExtranjero(const AlumnoExtranjero& orig);
    ~AlumnoExtranjero();
};

#endif /* ALUMNOEXTRANJERO_H */

