#include <iostream>

#include "funciones.h"

using namespace std;

int compararInt(const void* a, const void* b) {
    int ia = *(int*)a;
    int ib = *(int*)b;

    if (ia < ib) return -1;
    if (ia > ib) return 1;
    return 0;
}

int compararDouble(const void* a, const void* b) {
    double ia = *(double*)a;
    double ib = *(double*)b;

    if (ia < ib) return -1;
    if (ia > ib) return 1;
    return 0;
}

int compararCadenas(const void* a, const void* b) {
    const char* sa = (const char*)a;
    const char* sb = (const char*)b;
    return strcmp(sa, sb);
}

int main() {
    const char** cadenas = new const char*[6] { "banana", "apple", "grape", "orange", "kiwi", "melon" };
    const void** datos = new const void*[6];
    for (int i = 0; i < 6; ++i) {
        datos[i] = cadenas[i];
    }

    ordenar(datos, 6, compararCadenas);

    for (int i = 0; i < 6; i++) {
        cout << (const char*)datos[i] << " ";
    }
    cout << endl;

    delete[] cadenas;
    delete[] datos;

    return 0;
}
