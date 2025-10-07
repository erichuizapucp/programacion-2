//
// Created by Eric Huiza on 10/6/25.
//

#ifndef SESION_DE_CLASE_15_HERENCIA_VIDEO_H
#define SESION_DE_CLASE_15_HERENCIA_VIDEO_H


class Video : public Publicacion {
    char* archivo; // ruta de video
    char* poster;  // ruta de la imagen del video
    int duracion;  // duracion en segundos
};


#endif //SESION_DE_CLASE_15_HERENCIA_VIDEO_H