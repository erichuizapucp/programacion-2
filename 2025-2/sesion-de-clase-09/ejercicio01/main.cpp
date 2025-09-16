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

    apilar(pila, &a);
    apilar(pila, &b);
    apilar(pila, &c);

    imprimirPila(cout, pila, imprimirCadena);

    void* datoDesapilado;
    if (desapilar(pila, datoDesapilado)) {
        cout << "Valor desencolado: " << *(const char**)datoDesapilado << endl;
    }

    cout << "Cola luego de remover el dato: " << endl;
    imprimirPila(cout, pila, imprimirCadena);

    destruir(pila);

    return 0;
}