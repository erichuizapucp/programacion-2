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
//Pedido& operator+=(Pedido&, Producto&);

void cargarProductos(const char*, Producto*&, int&);
bool operator>>(ifstream&, Producto&);

void cargarClientes(const char*, Cliente*&, int&);
void cargarClientes(const char*, Cliente*&);
bool operator>>(ifstream&, Cliente&);

void cargarPedidos(const char*, Pedido*&, int&);
bool operator>>(ifstream&, Pedido&);

void asignarPedidosClientes(Pedido*&, int numPedidos, Cliente*&);
Cliente* buscarClientePorCodigo(Cliente*, int);
void incrementarPedidos(Pedido*&, const int, int&);

char* leerCadena(ifstream&, char=',');

ostream& operator<<(ostream&, Cliente&);

#endif /* FUNCIONES_H */
