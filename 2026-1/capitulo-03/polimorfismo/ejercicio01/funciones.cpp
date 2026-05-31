//
// Created by Eric Huiza on 5/30/26.
//
#include "funciones.h"

ostream& operator<<(ostream& os, const Persona& persona) {
    persona.imprimir();
    return os;
}