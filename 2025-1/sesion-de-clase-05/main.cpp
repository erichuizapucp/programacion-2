/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on April 7, 2025, 3:29 PM
 */

#include <cstdlib>
#include "estructuras.h"
#include "funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Producto* productos;
    int numProductos;
    cargarProductos("productos.csv", productos, numProductos);
    
//    for (int i = 0; i < numProductos; i++) {
//        cout << "Código de Producto: " << productos[i].codigo << endl;
//        cout << "Nombre de Producto: " << productos[i].nombre << endl;
//        cout << "Precio de Producto: " << productos[i].precio << endl;
//        cout << endl;
//    }
//    cout << endl;
    
    Cliente* clientes;
    cargarClientes("clientes.csv", clientes);
    
//    for (int i = 0; clientes[i].codigo != -1; i++) {
//        cout << "Código de Cliente: " << clientes[i].codigo << endl;
//        cout << "Nombre de Cliente: " << clientes[i].nombre << endl;
//        cout << "Apellido de Cliente: " << clientes[i].apellido << endl;
//        cout << endl;
//    }
//    cout << endl;
    
    Pedido* pedidos;
    int numPedidos;
    cargarPedidos("pedidos.csv", pedidos, numPedidos);
    
//    for (int i = 0; i < numPedidos; i++) {
//        cout << "Código de Pedido: " << pedidos[i].codigo << endl;
//        cout << "Código de Cliente: " << pedidos[i].codigoCliente << endl;
//        cout << endl;
//    }
//    cout << endl;
    
    asignarPedidosClientes(pedidos, numPedidos, clientes);
    
    for (int i = 0; clientes[i].codigo != -1; i++) {
        cout << clientes[i];
    }
    
    return 0;
}

