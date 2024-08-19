/* 
 * File:   cliente.h
 * Author: erichuiza
 *
 * Created on August 18, 2024, 9:08 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <iomanip>

using namespace std;

struct Cliente {
    int dni;
    double subTotal; // total comprado antes de impuestos
    double subTotalDescuento;
    double igv;
    double total; // total comprado después de impuestos
    double descuento;
};

// Operaciones a nivel de arreglo
void cargarClientes(int*, double*, Cliente*&);
void calcularTotales(Cliente*&, double=180.00);
void imprimirClientes(Cliente*);

// Operaciones a nivel de registro
void calcular(Cliente*&);
void calcular(double, double, double&, double&, double&, double=0.18);
void descuento(Cliente*&);
void descuento(double, double&, double=0.05);
void imprimir(Cliente*);

#endif /* CLIENTE_H */
