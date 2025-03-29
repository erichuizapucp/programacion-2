/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on March 28, 2025, 4:55 PM
 */

#include <cstdlib>

#include <iostream>
#include "estructuras.h"
#include "funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Cliente clientes[3] {
        { 45639767, "Juan", "Torres" }, 
        { 45639756, "María", "Gonzales" },
        { 45639134, "David", "Padilla" }
    };
    
    Pedido pedidos[5] { { 1 }, { 2 }, { 3 }, { 4 }, { 5 } };
    
    Producto productos[5] {
        { 1000, "Arroz", 4.00 }, 
        { 2000, "Huevos", 6.00 },
        { 3000, "Aceite", 10.00 }, 
        { 4000, "Leche", 9.00 }, 
        { 5000, "Pan", 5.00 }
    };
    
    pedidos[0] += productos[0];
    pedidos[0] += productos[4];
    pedidos[0] += productos[2];
    
    pedidos[1] += productos[1];
    pedidos[1] += productos[3];
    pedidos[1] += productos[4];
    
    pedidos[2] += productos[4];
    
    pedidos[3] += productos[2];
    
    pedidos[4] += productos[0];
    pedidos[4] += productos[1];
    pedidos[4] += productos[2];
    pedidos[4] += productos[3];
    pedidos[4] += productos[4];
    
    clientes[0] += pedidos[0];
    clientes[0] += pedidos[1];
    
    clientes[1] += pedidos[2];
    
    clientes[2] += pedidos[3];
    clientes[2] += pedidos[4];
    
    for (int i = 0; i < 3; i++) {
        cout << clientes[i] << endl;
    }
    
    if (clientes[0] == clientes[1]) {
        cout << "Son Iguales" << endl;
    }
    else {
        cout << "No son iguales" << endl;
    }
    
    
    if (pedidos[0] == pedidos[1]) {
        cout << "Son Iguales" << endl;
    }
    else {
        cout << "No son iguales" << endl;
    }
    
    
    return 0;
}

