/* 
 * File:   sobrecargas.h
 * Author: erichuiza
 *
 * Created on August 21, 2024, 3:43 PM
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

#include <iostream>
#include <iomanip>
#include "estructuras.h"

using namespace std;

// Operaciones a nivel de arreglo
void operator>>(Datos&, Cliente*&); // carga los datos de los clientes
ostream& operator<<(ostream&, Cliente*); // imprime todos los clientes
void calcularTotales(Cliente*&, double=180.00);

// Operaciones a nivel de registro
void calcular(Cliente*&);
void calcular(double, double, double&, double&, double&, double=0.18);
void descuento(Cliente*&);
void descuento(double, double&, double=0.05);
bool operator>>(Datos&, Cliente&);
ostream& operator<<(ostream&, Cliente&); // imprime un cliente

#endif /* SOBRECARGAS_H */

