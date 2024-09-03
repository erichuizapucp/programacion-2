/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on August 28, 2024, 1:59 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

#include "funciones.h"

using namespace std;

int main(int argc, char** argv) {
    int* numeros;
    int numDatos;
    cargarNumeros("numeros.txt", numeros, numDatos);
    
    for (int i = 0; i < numDatos; i++) {
        cout << numeros[i] << endl;
    }
    
    delete[] numeros;
    cout << endl;
    cargarNumeros("numeros.txt", numeros);
    
    for (int i = 0; numeros[i] != -1; i++) {
        cout << numeros[i] << endl;
    }
    
    delete[] numeros;
    
    cout << endl;
    
    ifstream archParrafo("parrafo.txt");
    char* parrafo = leerCadena(archParrafo, '\n');
    
//    cout << strlen(parrafo);
    cout << parrafo;
    
    delete[] parrafo;
    
    cout << endl << endl;
    
    Empleado* empleados;
    int numEmpleados;
    cargarEmpleados("empleados.csv", empleados, numEmpleados);
    
    for (int i = 0; i < numEmpleados; i++) {
        cout << &empleados[i];
    }
    
    delete[] empleados;
    
    cout << endl << endl;
    
    cargarEmpleados("empleados.csv", empleados);
    
    for (int i = 0; empleados[i].dni != -1; i++) {
        cout << &empleados[i];
    }
    
    delete[] empleados;
    
    return 0;
}

