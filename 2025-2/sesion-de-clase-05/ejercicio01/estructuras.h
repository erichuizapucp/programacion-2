//
// Created by Eric Huiza on 9/1/25.
//

#ifndef EJERCICIO01_ESTRUCTURAS_H
#define EJERCICIO01_ESTRUCTURAS_H

struct Usuario {
    int dni;
    char* nombre;
    char* correo;
    char membresia; // 'S' - Standard, 'P' - Premium
};

struct Publicacion {
    int id;
    int dniUsuario;
    int anho;
    int mes;
    int dia;
    char* contenido;
};

#endif //EJERCICIO01_ESTRUCTURAS_H