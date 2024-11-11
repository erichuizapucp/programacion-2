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
    
    if (empleados[1] <= empleados[2]) {
    }
    
    return 0;
}

