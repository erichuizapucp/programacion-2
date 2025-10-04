//
// Created by Eric Huiza on 10/3/25.
//

#ifndef SESION_DE_CLASE_14_FILTROEDAD_H
#define SESION_DE_CLASE_14_FILTROEDAD_H


class FiltroEdad {
    int edadMinima;
public:
    FiltroEdad() : edadMinima(18) {}
    FiltroEdad(int edad) : edadMinima(edad) {}

    bool operator()(int);
};


#endif //SESION_DE_CLASE_14_FILTROEDAD_H