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
    double precio;
    char* nombre;
};

struct Pedido {
    int codigo;
    Producto* productos;
    int cantProductos;
};

struct Cliente {
    int codigo;
    char* nombre;
    char* apellido;
    Pedido* pedidos;
    int cantPedidos;
};

#endif /* ESTRUCTURAS_H */

