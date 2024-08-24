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

// Funciones plantilla
template<typename T>
void operator>>(Datos&, T*&); // carga los datos genérico

ostream& operator<<(ostream&, Cliente*); // imprime todos los clientes
ostream& operator<<(ostream&, Empleado*); // imprime todos los empleados

bool operator>>(Datos&, Cliente&); // inserta un cliente
ostream& operator<<(ostream&, Cliente&); // imprime un cliente
bool operator>>(Datos&, Empleado&); // inserta un empleado
ostream& operator<<(ostream&, Empleado&); // imprime un empleado

void calcularTotales(Cliente*&, double=180.00);
void calcular(Cliente*&); // calcula los totales de un cliente
void calcular(double, double, double&, double&, double&, double=0.18);
void descuento(Cliente*&, double=0.05);

void descuento(double, double&, double); // aplica un descuento

void calcularTotales(Empleado*&, double=2000.00);
void calcular(Empleado*&);
void calcular(double, double, double&);
void descuento(Empleado*&, double=0.08);

template<typename T>
void operator>>(Datos& datos, T*& registros) {
    int num;
    // itera hasta llegar al final de los DNIs para saber la cantidad de elementos
    for (num = 0; datos.dnis[num] != -1; num++);
    
    // siempre agregamos un elemento más para saber cuando parar al recorrer el arreglo
    registros = new T[num + 1];
    // declaramos un puntero temporal para moverse a través del arreglo usando aritmética de punteros.
    // no se recomienda usar el arreglo para realizar el movimiento porque eso causará que se pierda
    // la referencia a la ubicación original.
    T* ptr = registros;
    while (datos >> *ptr) {
        ptr++;
    }
}

#endif /* SOBRECARGAS_H */

