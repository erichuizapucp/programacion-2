/* 
 * File:   AlumnoExtranjero.cpp
 * Author: erichuiza
 * 
 * Created on October 11, 2024, 4:54 PM
 */

#include "AlumnoExtranjero.h"

AlumnoExtranjero::AlumnoExtranjero() : Alumno() {
    paisOrigen = {};
}

AlumnoExtranjero::AlumnoExtranjero(const AlumnoExtranjero& orig) : Alumno(orig) {
}

AlumnoExtranjero::~AlumnoExtranjero() {
    delete[] paisOrigen;
}

