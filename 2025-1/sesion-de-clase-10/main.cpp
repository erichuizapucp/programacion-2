/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on September 13, 2024, 1:33 PM
 */

#include <cstdlib>
#include <stdlib.h>

#include "funciones.h"

using namespace std;

int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

int ejecutarOperacion(int a, int b, int(*p)(int a, int b)) {
   return p(a, b); 
}

int main(int argc, char** argv) {
//    int (*p)(int a, int b) = restar;
//    p = sumar;
//    cout << ejecutarOperacion(5, 3, sumar) << endl;
//    cout << ejecutarOperacion(5, 3, restar) << endl;
//    cout << ejecutarOperacion(5, 3, multiplicar) << endl;
    
    void* meseros;

    cargarDatos("meseros.csv", meseros);
    mostrarDatos(meseros);
    
    void* res;
    int dni = 46587913;
    if (buscarPorDni(dni, meseros, res)) {
        cout << endl;
        cout << "Se encontró el mesero con dni: " << dni << endl;
        cout << (const void**)res << endl;
    }
    else {
        cout << "No se encontró" << endl;
    }
    
            
    //TODO: liberar memoria de los punteros interiores
    delete[] (void**)meseros;
    
    return 0;
}

