#include "Registro.h"

bool operator>>(ifstream& archivo, Registro& registro) {
    return registro.cargarDatos(archivo);
}

ostream& operator<<(ostream& os, const Registro& registro) {
    registro.imprimir(os);
    return os;
}

char* Registro::leerCadena(ifstream& archivo, char delimitador) {
    char buffer[100];
    archivo.getline(buffer, 100, delimitador);

    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);

    return cadena;
}