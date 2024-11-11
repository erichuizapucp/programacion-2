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

/*
 * 
 */
int main(int argc, char** argv) {
    void* meseros = new void*[4];

    cargarDatos("meseros.csv", meseros);
    mostrarDatos(meseros);
    
    void* res;
    if (buscarPorDni(68721345, meseros, res)) {
        cout << (const void**)res;
    }
    else {
        cout << "No se encontró";
    }
    
            
    //TODO: liberar memoria de los punteros interiores
    delete[] (void**)meseros;
    
    return 0;
}

