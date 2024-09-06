/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on September 5, 2024, 8:42 PM
 */

#include <cstdlib>
#include <iostream>

#include "funciones.h"
#include "estructuras.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int* numeros;
    int numDatos;
    cargarDatos("numeros.txt", numeros, numDatos);
    
    for (int i = 0; i < numDatos; i++) {
        cout << numeros[i] << endl;
    }
    
    delete[] numeros;
    cout << endl;
    cargarDatos("numeros.txt", numeros);
    
    for (int i = 0; numeros[i] != -1; i++) {
        cout << numeros[i] << endl;
    }
    
    delete[] numeros;
    
    cout << endl << endl;
    
    Empleado* empleados;
    int numEmpleados;
    cargarDatos("empleados.csv", empleados, numEmpleados);
    
    for (int i = 0; i < numEmpleados; i++) {
        cout << &empleados[i];
    }
    
    delete[] empleados;
    
    cout << endl << endl;
    
    cargarDatos("empleados.csv", empleados);
    
    for (int i = 0; empleados[i].dni != -1; i++) {
        cout << &empleados[i];
    }
    
    delete[] empleados;
    
    return 0;
}

