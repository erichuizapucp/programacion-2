/* 
 * File:   funciones.h
 * Author: erichuiza
 *
 * Created on September 2, 2024, 4:17 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <iostream>
#include <fstream>
#include "estructuras.h"

using namespace std;

void cargarNumeros(const char*, int*&, int&);
void cargarNumeros(const char*, int*&);
void cargarEmpleados(const char*, Empleado*&, int&);
void cargarEmpleados(const char*, Empleado*&);

bool operator>>(ifstream&, Empleado&);
ostream& operator<<(ostream&,const Empleado*);

char* leerCadena(ifstream&, char=',');

#endif /* FUNCIONES_H */

