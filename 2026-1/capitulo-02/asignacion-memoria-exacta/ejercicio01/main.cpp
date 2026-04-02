#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    int* numeros;
    cargarNumeros("numeros.csv", numeros);

    for (int i = 0; numeros[i] != -1; i++) {
        cout << numeros[i] << endl;
    }

    delete[] numeros;

    return 0;
}
