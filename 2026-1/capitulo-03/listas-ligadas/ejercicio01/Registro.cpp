#include "Registro.h"

istream& operator>>(istream& archivo, Registro& registro) {
    return registro.leer(archivo);
}

ostream& operator<<(ostream& os, const Registro& registro) {
    registro.imprimir(os);
    return os;
}

char* Registro::leerCadena(istream& archivo, char delimitador) {
    char buffer[100];
    archivo.getline(buffer, 100, delimitador);

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