//
// Created by Eric Huiza on 5/13/26.
//

#include "ManejadorCadenas.h"

ManejadorCadenas::ManejadorCadenas() {
    cadenas = nullptr;
    numCadenas = 0;
}

void ManejadorCadenas::cargarCadenas(const char* nombreArchivo) {
    Cadena buffer[20];
    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> buffer[numCadenas]) {
        numCadenas++;
    }

    cadenas = new Cadena[numCadenas];
    for (int i = 0; i < numCadenas; i++) {
        cadenas[i] = buffer[i];
    }
    qsort(cadenas, numCadenas, sizeof(Cadena), cmpCadena);
}

int cmpCadena(const void* a, const void* b) {
    const Cadena* cadA = (const Cadena*)a;
    const Cadena* cadB = (const Cadena*)b;

    if (*cadA == *cadB) {
        return 0;
    }

    if (*cadA < *cadB) {
        return -1;
    }

    return 1;
}

void ManejadorCadenas::imprimirCadenas() const {
    for (int i = 0; i < numCadenas; i++) {
        cout << cadenas[i];
    }
}

ManejadorCadenas::~ManejadorCadenas() {
    delete[] cadenas;
}