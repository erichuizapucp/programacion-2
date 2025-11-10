//
// Created by Eric Huiza on 11/7/25.
//

#include "Registro.h"

istream& operator>>(istream& archivo, Registro& registro) {
    registro.leer(archivo);
    return archivo;
}

ostream& operator<<(ostream& archivo, const Registro& registro) {
    registro.imprimir(archivo);
    return archivo;
}