//
// Created by Eric Huiza on 3/27/26.
//

#include "funciones.h"

void incrementarPorValor(int* x) {
    *x = *x + 1;
    cout << "Dirección a la que apunta X: " << x << endl;
    cout << "Dirección de X: " << &x << endl;
}

void incremetarPorRef(int*& x) {
    x = new int(9);
    *x = *x + 2;

    cout << "Dirección a la que apunta X: " << x << endl;
    cout << "Dirección de X: " << &x << endl;
}

void sumar(int a, int b) {
    cout << a + b << endl;
}