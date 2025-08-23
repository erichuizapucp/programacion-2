//
// Created by Eric Huiza on 8/21/25.
//

#ifndef SESION_DE_CLASE_02_ESTRUCTURAS_H
#define SESION_DE_CLASE_02_ESTRUCTURAS_H

struct Reaccion {
    char comentario[50];
    int rating; // 1 a 5
};

struct Publicacion {
    char nombre[50];
    char contenido[200];
    Reaccion elementos[5];
    int num;
};

struct Usuario {
    char nombre[50];
    int edad;
    char correo[100];
    Publicacion elementos[5];
    int num;
};

struct RedSocial {
    char nombre[50];
    Usuario elementos[5];
    int num;
};

#endif //SESION_DE_CLASE_02_ESTRUCTURAS_H