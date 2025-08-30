#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    int* numeros;
    cargarNumeros("numeros.csv", numeros);
    imprimirNumeros("numeros.txt", numeros);

    return 0;
}