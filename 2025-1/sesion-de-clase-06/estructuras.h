/* 
 * File:   estructuras.h
 * Author: erichuiza
 *
 * Created on March 27, 2025, 9:51 PM
 */

#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

struct Producto {
    int codigo;
    char* nombre;
    double precio;
};

struct Pedido {
    int codigo;
    int codigoCliente;
    int cantProductos;
    Producto* productos;
};

struct Cliente {
    int codigo;
    char* nombre;
    char* apellido;
    int cantPedidos;
    Pedido* pedidos;
};

struct DetallePedido {
    int codigoPedido;
    int codigoProducto;
    double cantidad;
};

#endif /* ESTRUCTURAS_H */
