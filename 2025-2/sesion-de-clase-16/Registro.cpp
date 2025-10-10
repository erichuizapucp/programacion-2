//
// Created by Eric Huiza on 10/10/25.
//

#include "Registro.h"

char* Registro::leerCadena(istream& archivo, char delim) {
    char buffer[100];
    archivo.getline(buffer, 100, delim);
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

void Registro::leerCuentas(istream& archivo, char**& cuentas) {
    char* buffer[10]; // máximo 10 cuentas por lista
    int num = 0;
    char* mencion;

    while (leerCuenta(archivo, mencion)) {
        buffer[num++] = mencion;
    }

    cuentas = new char*[num + 1] {}; // agregamos un NULL al final
    for (int i = 0; i < num; i++) {
        cuentas[i] = buffer[i];
    }
}

bool Registro::leerCuenta(istream& archivo, char*& cuenta) {
    char buffer[20];
    int num = 0;

    // si siguiente es ']', no hay más cuentas
    if (archivo.peek() == ']') {
        archivo.get(); // consumir ']'
        return false;
    }

    while (archivo.peek() != ' ' && archivo.peek() != ']') {
        buffer[num++] = archivo.get();
    }

    buffer[num] = '\0';

    cuenta = new char[num + 1];
    strcpy(cuenta, buffer);

    // consumir espacio
    if (archivo.peek() == ' ')
        archivo.get();

    return true;
}