/* 
 * File:   Alumno.cpp
 * Author: erichuiza
 * 
 * Created on October 11, 2024, 4:45 PM
 */

#include "Alumno.h"

Alumno::Alumno() : Persona() {
    codigo = {};
    ciclo = {};
}

Alumno::Alumno(const Alumno& orig) : Persona(orig) {
}

Alumno::~Alumno() {
}
