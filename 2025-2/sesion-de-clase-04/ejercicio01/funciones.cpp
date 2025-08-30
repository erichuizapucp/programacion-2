//
// Created by Eric Huiza on 8/29/25.
//
#include "funciones.h"

void cargarNumeros(const char* nombreArchivo,
    int*& numeros,
    int& cantidad) {
    // Crear un buffer de enteros
    int buffer[200];
    int num = 0;

    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> buffer[num]) {
        num++;
    }

    cantidad = num;
    // asignación exacta
    numeros = new int[cantidad];
    for (int i = 0; i < cantidad; i++) {
        numeros[i] = buffer[i];
    }
}

void cargarNumeros(const char* nombreArchivo,
    int*& numeros) {
    // Crear un buffer de enteros
    int buffer[200];
    int num = 0;

    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> buffer[num]) {
        num++;
    }

    // asignación exacta
    numeros = new int[num + 1];
    for (int i = 0; i < num; i++) {
        numeros[i] = buffer[i];
    }
    numeros[num] = -1;
}

void imprimirNumeros(const char* nombreArchivo,
    const int* numeros,
    int cantidad) {

    ofstream archivo(nombreArchivo, ios::out);
    for (int i = 0; i < cantidad; i++) {
        archivo << numeros[i] << endl;
    }
}

void imprimirNumeros(const char* nombreArchivo,
    const int* numeros) {

    ofstream archivo(nombreArchivo, ios::out);
    for (int i = 0; numeros[i] != -1; i++) {
        archivo << numeros[i] << endl;
    }
}