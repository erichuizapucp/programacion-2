/* 
 * File:   estructuras.h
 * Author: erichuiza
 *
 * Created on March 28, 2025, 4:57 PM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct Producto {
    int codigo;
    char nombre[50];
    double precio;
};

struct Pedido {
    int codigo;
    Producto productos[10];
    int cantProductos;
};

struct Cliente {
    int codigo;
    char nombre[50];
    char apellido[50];
    Pedido pedidos[10];
    int cantPedidos;
};

#endif /* ESTRUCTURAS_H */

