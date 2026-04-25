#include <iostream>

#include "lista.h"
#include "cola.h"
#include "pila.h"

using namespace std;

int main() {
    void* cola = crearCola();

    // double a = 10.5, b = 20.4, c = 30.9;
    const char* a = "Juan Perez";
    const char* b = "Ana Gomez";
    const char* c = "Luis Martinez";

    encolar(cola, &a); // &a es un char**
    encolar(cola, &b); // &b es un char**
    encolar(cola, &c); // &c es un char**

    imprimirCola(cout, cola, imprimirCadena);

    void* datoDesencolado;
    if (desencolar(cola, datoDesencolado)) {
        void** datoPtr = (void**)datoDesencolado; // datoPtr es un char**
        char* dato = (char*)*datoPtr; // dato es un char*
        cout << "Valor desencolado: " << dato << endl;
    }

    cout << "Cola luego de desapilar el dato: " << endl;
    imprimirCola(cout, cola, imprimirCadena);

    destruir(cola);

    return 0;
}