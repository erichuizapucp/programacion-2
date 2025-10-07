//
// Created by Eric Huiza on 10/6/25.
//

#ifndef SESION_DE_CLASE_15_HERENCIA_HISTORIA_H
#define SESION_DE_CLASE_15_HERENCIA_HISTORIA_H

#include "Foto.h"
#include "Video.h"

using namespace std;

class Historia : public Foto, public Video {
    int duracionHistoria; // duracion en segundos de la historia
};


#endif //SESION_DE_CLASE_15_HERENCIA_HISTORIA_H