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
    
    Datos datos { dnis, subTotales };
    Cliente* clientes;
    
    datos >> clientes;
    calcularTotales(clientes);
    cout << clientes;
    
    delete[] clientes;
    
    return 0;
}

