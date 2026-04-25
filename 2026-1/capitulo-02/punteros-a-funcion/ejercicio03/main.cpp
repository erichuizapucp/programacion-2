#include <iostream>

#include "funciones.h"

using namespace std;

int main() {
    const char** cadenas = new const char*[6] {
        "banana", "apple", "grape", "orange", "kiwi", "melon"
    };
    // const int* numeros = new const int[6] {5, 2, 9, 1, 5, 6};

    const void **datos = new const void *[6];
    for (int i = 0; i < 6; ++i) {
        // datos[i] = &numeros[i];
        datos[i] = cadenas[i];
    }

    // ordenar(datos, 6, compararInt);
    ordenar(datos, 6, compararCadenas);

    for (int i = 0; i < 6; i++) {
        cout << (char*)datos[i] << " ";
    }
    cout << endl;

    // delete[] numeros;
    delete[] cadenas;
    delete[] datos;

    return 0;
}
