/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on March 27, 2025, 9:50 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>

#include "estructuras.h"
#include "funciones.h"

using namespace std;

int main(int argc, char** argv) {
    Cliente* clientes = new Cliente[3] { 
        { 45673848 }, 
        { 45673674 }, 
        { 45687573 } 
    };
    clientes[0].nombre = new char[50];
    strcpy(clientes[0].nombre, "Juan");
    clientes[0].apellido = new char[50];
    strcpy(clientes[0].apellido, "Pérez");
    
    clientes[1].nombre = new char[50];
    strcpy(clientes[1].nombre, "Maria");
    clientes[1].apellido = new char[50];
    strcpy(clientes[1].apellido, "García");
    
    clientes[2].nombre = new char[50];
    strcpy(clientes[2].nombre, "John");
    clientes[2].apellido = new char[50];
    strcpy(clientes[2].apellido, "Torres");
    
    clientes[0].pedidos = new Pedido[10];
    clientes[1].pedidos = new Pedido[10];
    clientes[2].pedidos = new Pedido[10];
    
    Pedido* pedidos = new Pedido[5] { { 1 }, { 2 }, { 3 }, { 4 }, { 5 } };
    pedidos[0].productos = new Producto[10];
    pedidos[1].productos = new Producto[10];
    pedidos[2].productos = new Producto[10];
    pedidos[3].productos = new Producto[10];
    pedidos[4].productos = new Producto[10];
    
    Producto* productos = new Producto[5] {
        { 1111 }, 
        { 2222 }, 
        { 3333 }, 
        { 4444 }, 
        { 5555 }
    };
    
    productos[0].nombre = new char[50];
    productos[1].nombre = new char[50];
    productos[2].nombre = new char[50];
    productos[3].nombre = new char[50];
    productos[4].nombre = new char[50];
    strcpy(productos[0].nombre, "Aceite Vegetal");
    strcpy(productos[1].nombre, "Yogurt Griego");
    strcpy(productos[2].nombre, "Pan Integral");
    strcpy(productos[3].nombre, "Leche Evaporada");
    strcpy(productos[4].nombre, "Huevos");
    productos[0].precio = 5.00;
    productos[1].precio = 8.7;
    productos[2].precio = 4.5;
    productos[3].precio = 3.5;
    productos[4].precio = 5.5;
    
    pedidos[0]+=productos[0];
    pedidos[0]+=productos[3];
    pedidos[0]+=productos[4];
    
    pedidos[1]+=productos[1];
    pedidos[1]+=productos[2];
    
    pedidos[2]+=productos[2];
    pedidos[2]+=productos[4];
    
    pedidos[3]+=productos[0];
    pedidos[3]+=productos[3];
    
    pedidos[4]+=productos[0];
    pedidos[4]+=productos[1];
    pedidos[4]+=productos[2];
    pedidos[4]+=productos[3];
    pedidos[4]+=productos[4];
    
    clientes[0]+=pedidos[0];
    clientes[0]+=pedidos[1];
    
    clientes[1]+=pedidos[2];
    clientes[1]+=pedidos[3];
    
    clientes[2]+=pedidos[4];
    
    cout << clientes[0] << endl;
    cout << clientes[1] << endl;
    cout << clientes[2] << endl;
    
    bool iguales = clientes[0] == clientes[0];
    cout << (iguales ? "Son iguales" : "No son iguales") << endl;
    
    bool diferentes = clientes[0] != clientes[1];
    cout << (diferentes ? "Son diferentes" : "No son diferentes") << endl;
    
    return 0;
}

