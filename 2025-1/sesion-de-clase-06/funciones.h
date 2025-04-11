/* 
 * File:   funciones.h
 * Author: erichuiza
 *
 * Created on March 27, 2025, 9:52 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "estructuras.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

Cliente& operator+=(Cliente&, Pedido&);
Pedido& operator+=(Pedido&, Producto&);

void cargarProductos(const char*, Producto*&);
bool operator>>(ifstream&, Producto&);

void cargarClientes(const char*, Cliente*&);
bool operator>>(ifstream&, Cliente&);

void cargarPedidos(const char*, Pedido*&);
bool operator>>(ifstream&, Pedido&);

void cargarDetallePedido(const char*, DetallePedido*&);
bool operator>>(ifstream&, DetallePedido&);

Cliente* buscarClientePorCodigo(Cliente*, int);
Pedido* buscarPedidoPorCodigo(Pedido*, int);
Producto* buscarProductoPorCodigo(Producto*, int);

void asignarPedidosClientes(Pedido*&, Cliente*&);
void asignarProductosPedidos(Pedido*&, Producto*&, DetallePedido*&);

void incrementarPedidos(Pedido*&, int, int&);
void incrementarProductos(Producto*&, int, int&);

char* leerCadena(ifstream&, char=',');

ostream& operator<<(ostream&, Cliente&);
ostream& operator<<(ostream&, Pedido&);
ostream& operator<<(ostream&, Producto&);

void imprimirPedidosPorCliente(Cliente*&);

#endif /* FUNCIONES_H */
