//
// Created by Eric Huiza on 4/1/26.
//
#include "funciones.h"

void cargarNumeros(const char* nombreArchivo, int*& numeros, int& num) {
    num = 0;
    int numero;
    int buffer[200];

    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> numero) {
        buffer[num++] = numero;
    }

    numeros = new int[num];
    for (int i = 0; i <= num; i++) {
        numeros[i] = buffer[i];
    }
}

void cargarNumeros(const char* nombreArchivo, int*& numeros) {
    int num = 0;
    int numero;
    int buffer[200];

    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> numero) {
        buffer[num++] = numero;
    }

    numeros = new int[num + 1];
    for (int i = 0; i <= num; i++) {
        numeros[i] = buffer[i];
    }
    numeros[num] = -1;
}

// ifstream& operator>> (ifstream& archivo, int& num) {
//
// }