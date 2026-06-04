#include "funciones.h"
#include <cstring>

void saltarEspacios(ifstream& archivo) {
    while (archivo.peek() == ' ') {
        archivo.get();
    }
}

void consumirComa(ifstream& archivo) {
    saltarEspacios(archivo);
    if (archivo.peek() == ',') {
        archivo.get();
    }
}

void consumirFinLinea(ifstream& archivo) {
    saltarEspacios(archivo);
    if (archivo.peek() == '\r') {
        archivo.get();
    }
    if (archivo.peek() == '\n') {
        archivo.get();
    }
}

static void limpiarExtremos(char* texto) {
    int inicio = 0;
    int fin = (int)strlen(texto) - 1;
    while (texto[inicio] == ' ') {
        inicio++;
    }
    while (fin >= inicio and texto[fin] == ' ') {
        fin--;
    }

    int j = 0;
    for (int i = inicio; i <= fin; i++) {
        texto[j++] = texto[i];
    }
    texto[j] = 0;
}

char* leerCadena(ifstream& archivo, char delim) {
    char buffer[300];
    archivo.getline(buffer, 300, delim);
    limpiarExtremos(buffer);

    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}
