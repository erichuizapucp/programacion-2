//
// Created by Eric Huiza on 10/6/25.
//

#ifndef SESION_DE_CLASE_15_HERENCIA_ALBUM_H
#define SESION_DE_CLASE_15_HERENCIA_ALBUM_H
#include "Foto.h"
#include "Publicacion.h"
#include "Video.h"


class Album : public Publicacion {
    Foto* fotos;
    Video* videos;
};


#endif //SESION_DE_CLASE_15_HERENCIA_ALBUM_H