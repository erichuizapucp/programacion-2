/* 
 * File:   Persona.cpp
 * Author: erichuiza
 * 
 * Created on October 11, 2024, 4:45 PM
 */

#include "Persona.h"

Persona::Persona() {
    dni = {};
    nombre = {};
    edad = {};
}

Persona::Persona(const Persona& orig) {
}

Persona::~Persona() {
    delete[] nombre;
}

