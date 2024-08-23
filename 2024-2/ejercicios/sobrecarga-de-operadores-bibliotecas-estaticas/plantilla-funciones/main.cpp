/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on August 21, 2024, 3:07 PM
 */

#include <cstdlib>
#include "estructuras.h"
#include "funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    const int NUM_CLIENTES = 5;
    
    int dnis[NUM_CLIENTES + 1] {
        37482916,
        58647392,
        19273845,
        48392074,
        65748120,
        -1 // indicador de finalización
    };
    
    double subTotales[NUM_CLIENTES + 1] {
        200.00,
        150.00,
        180.00,
        160.00,
        120.00,
        -1.00 // indicador de finalización
    };
    
    double sueldos[NUM_CLIENTES + 1] {
        2000.00,
        1800.00,
        3000.00,
        5000.00,
        1200.00,
        -1.00 // indicador de finalización
    };
    
    Datos datosClientes { dnis, subTotales };
    Cliente* clientes;
    
    datosClientes >> clientes;
    calcularTotales(clientes);
    cout << clientes << endl;
    
    delete[] clientes;
    
    Datos datosEmpleados { dnis, sueldos };
    Empleado* empleados;
    
    datosEmpleados >> empleados;
    calcularTotales(empleados);
    cout << empleados << endl;
   
    delete[] empleados;
    
    return 0;
}

