//
// Created by Eric Huiza on 10/24/25.
//

#include "Registro.h"

char* Registro::leerCadena(istream& archivo, char delimitador) {
    char buffer[200];
    archivo.getline(buffer, 200, delimitador);
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void Registro::setCadena(char*& destino, const char* origen) {
    delete[] destino;
    if (origen) {
        destino = new char[strlen(origen) + 1];
        strcpy(destino, origen);
    }
    else {
        destino = nullptr;
    }
}