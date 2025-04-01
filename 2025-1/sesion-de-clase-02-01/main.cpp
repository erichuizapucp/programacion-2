/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on March 28, 2025, 4:55 PM
 */

#include <cstdlib>
#include <cstring>

#include <iostream>
#include "estructuras.h"
#include "funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Cliente* clientes = new Cliente[3] {
        { 45639767 }, 
        { 45639756 },
        { 45639134 }
    };
    
    clientes[0].pedidos = new Pedido[5];
    clientes[1].pedidos = new Pedido[5];
    clientes[2].pedidos = new Pedido[5];
    
    clientes[0].nombre = new char[20];
    strcpy(clientes[0].nombre, "Juan");
    clientes[0].apellido = new char[20];
    strcpy(clientes[0].apellido, "Torres");
    
    clientes[1].nombre = new char[20];
    strcpy(clientes[1].nombre, "María");
    clientes[1].apellido = new char[20];
    strcpy(clientes[1].apellido, "Gonzales");
    
    clientes[2].nombre = new char[20];
    strcpy(clientes[2].nombre, "David");
    clientes[2].apellido = new char[20];
    strcpy(clientes[2].apellido, "Padilla");
    
    Pedido pedidos[5] { { 1 }, { 2 }, { 3 }, { 4 }, { 5 } };
    pedidos[0].productos = new Producto[10];
    pedidos[1].productos = new Producto[10];
    pedidos[2].productos = new Producto[10];
    pedidos[3].productos = new Producto[10];
    pedidos[4].productos = new Producto[10];
    
    Producto productos[5] {
        { 1000, 4.00 }, 
        { 2000, 6.00 },
        { 3000, 10.00 }, 
        { 4000, 9.00 }, 
        { 5000, 5.00 }
    };
    
    productos[0].nombre = new char[10];
    strcpy(productos[0].nombre, "Arroz");
    productos[1].nombre = new char[10];
    strcpy(productos[1].nombre, "Huevos");
    productos[2].nombre = new char[10];
    strcpy(productos[2].nombre, "Aceite");
    productos[3].nombre = new char[10];
    strcpy(productos[3].nombre, "Leche");
    productos[4].nombre = new char[10];
    strcpy(productos[4].nombre, "Pan");
    
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

