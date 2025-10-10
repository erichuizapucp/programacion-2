//
// Created by Eric Huiza on 10/3/25.
//

#include "FiltroEdad.h"

bool FiltroEdad::operator()(int edad) {
    return edad >= edadMinima;
}