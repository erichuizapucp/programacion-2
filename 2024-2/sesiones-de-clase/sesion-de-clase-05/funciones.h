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

const int INCREMENTO = 5;

void cargarNumeros(const char*, int*&, int&);
void cargarNumeros(const char*, int*&);
void cargarEmpleados(const char*, Empleado*&, int&);
void cargarEmpleados(const char*, Empleado*&);

bool operator>>(ifstream&, Empleado&);
ostream& operator<<(ostream&,const Empleado*);

bool operator<=(const Empleado&, const Empleado&);
bool operator>=(const Empleado&, const Empleado&);

char* leerCadena(ifstream&, char=',');

template<typename T>
void cargar(const char* nombreArchivo, T*& datos, int& numDatos) {
    T buffer[1000];
    
    ifstream archivo(nombreArchivo, ios::in);
    numDatos = 0;
    while (archivo >> buffer[numDatos]) {
        numDatos++;
    }
    
    datos = new T[numDatos];
    
    for (int i = 0; i < numDatos; i++) {
        datos[i] = buffer[i];
    }
}

#endif /* FUNCIONES_H */

