#include <iostream>

#include "funciones.h"

using namespace std;

int main() {
    int *p = new int(5);
    incrementarPorValor(p);

    cout << *p << endl;
    cout << "Dirección a la que apunta P: " << p << endl;
    cout << "Dirección de P: " << &p << endl;

    *p = *p + 2;

    incremetarPorRef(p);
    cout << *p << endl;

    *p = *p + 2;
    cout << *p << endl;



    sumar(5, 6);
    sumar(2);
    sumar();

    return 0;
}
