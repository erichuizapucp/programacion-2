/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on August 18, 2024, 9:07 PM
 */

#include <cstdlib>
#include "cliente.h"

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
    
    Cliente* clientes;
    cargarClientes(dnis, subTotales, clientes);
    calcularTotales(clientes);
    imprimirClientes(clientes);
    
    delete[] clientes;
    
    return 0;
}

