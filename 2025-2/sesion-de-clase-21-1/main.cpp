#include <iostream>

#include "Arreglo.h"

using namespace std;

int main() {
    Arreglo<int> enteros;
    Arreglo<double> decimales;

    enteros.agregar(5);
    enteros.agregar(10);
    enteros.agregar(15);

    decimales.agregar(4.3);
    decimales.agregar(2.5);
    decimales.agregar(8.4);

    int a = enteros.obtener(0);
    double b = decimales.obtener(1);

    cout << a << endl;
    cout << b << endl;

    return 0;
}