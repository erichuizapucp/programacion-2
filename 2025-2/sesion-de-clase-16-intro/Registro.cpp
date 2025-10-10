//
// Created by Eric Huiza on 10/10/25.
//

#include "Registro.h"

void Registro::setCadena(const char* origen, char*& destino) {
    delete[] destino;
    if (origen) {
        destino = new char[strlen(origen) + 1];
        strcpy(destino, origen);
    }
    else {
        destino = nullptr;
    }
}
