#include <iostream>

#include "lista.h"
#include "cola.h"
#include "pila.h"

using namespace std;

int main() {
    void* pila = crearPila();

    // double a = 10.5, b = 20.4, c = 30.9;
    const char* a = "Juan Perez";
    const char* b = "Ana Gomez";
    const char* c = "Luis Martinez";

    apilar(pila, &a); // &a es un char**
    apilar(pila, &b); // &b es un char**
    apilar(pila, &c); // &c es un char**

    imprimirPila(cout, pila, imprimirCadena);

    void* datoDesapilado;
    if (desapilar(pila, datoDesapilado)) {
        void** datoPtr = (void**)datoDesapilado; // datoPtr es un char**
        char* dato = (char*)*datoPtr; // dato es un char*
        cout << "Valor desapilado: " << dato << endl;
    }

    cout << "Cola luego de desapilar el dato: " << endl;
    imprimirPila(cout, pila, imprimirCadena);

    destruir(pila);

    return 0;
}