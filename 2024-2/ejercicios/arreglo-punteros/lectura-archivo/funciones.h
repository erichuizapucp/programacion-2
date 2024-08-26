/* 
 * File:   sobrecargas.h
 * Author: erichuiza
 *
 * Created on August 21, 2024, 3:43 PM
 */

#ifndef SOBRECARGAS_H
#define SOBRECARGAS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "estructuras.h"

using namespace std;

void operator>>(ifstream&, Cliente*&); // carga los datos de clientes
void operator>>(ifstream&, Empleado*&); // carga los datos de clientes
bool operator>>(ifstream&, Cliente&); // inserta un cliente
bool operator>>(ifstream&, Empleado&); // inserta un empleado

ofstream& operator<<(ofstream&, const Cliente*); // imprime todos los clientes
ofstream& operator<<(ofstream&, const Empleado*); // imprime todos los empleados
ofstream& operator<<(ofstream&, const Cliente&); // imprime un cliente
ofstream& operator<<(ofstream&, const Empleado&); // imprime un empleado

void calcularTotales(Cliente*&, double=180.00);
void calcular(Cliente*&); // calcula los totales de un cliente
void calcular(double, double, double&, double&, double&, double=0.18);
void descuento(Cliente*&, double=0.05);

void descuento(double, double&, double); // aplica un descuento

void calcularTotales(Empleado*&, double=2000.00);
void calcular(Empleado*&);
void calcular(double, double, double&);
void descuento(Empleado*&, double=0.08);

#endif /* SOBRECARGAS_H */

