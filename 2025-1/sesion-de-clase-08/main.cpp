/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on September 13, 2024, 1:33 PM
 */

#include <cstdlib>

#include "funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    void* meseros;
    cargarDatos("meseros.csv", meseros);
    mostrarDatos(meseros);

    //TODO: liberar memoria de los punteros interiores
    delete[] (void**)meseros;
    
    return 0;
}

