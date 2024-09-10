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

//void cargarNumeros(const char*, int*&, int&);
//void cargarNumeros(const char*, int*&);
//void cargarEmpleados(const char*, Empleado*&, int&);
//void cargarEmpleados(const char*, Empleado*&);

//void incrementarEspacios(int*&, int&, int&);
//void incrementarEspacios(Empleado*&, int&, int&);

bool operator>>(ifstream&, Empleado&);
ostream& operator<<(ostream&,const Empleado*);

bool operator<=(const Empleado&, const Empleado&);
bool operator>=(const Empleado&, const Empleado&);

void asignarValorDeCorte(int&);
void asignarValorDeCorte(Empleado&);

char* leerCadena(ifstream&, char=',');

template<typename T>
void cargarDatos(const char*, T*&, int&, bool=false);

template<typename T>
void cargarDatos(const char*, T*&);

template<typename T>
void incrementarEspacios(T*&, int&, int&, bool);

template<typename T>
void cargarDatos(const char* nombreArchivo, T*& datos, int& numDatos, bool corte) {
    int cap = 0;
    numDatos = 0;
    datos = nullptr;
    
    ifstream archivo(nombreArchivo, ios::in);
    
    T dato;
    while (archivo >> dato) {
        if (numDatos == cap) {
            incrementarEspacios(datos, numDatos, cap, corte);
        }
        
        if (corte) {
            asignarValorDeCorte(datos[numDatos]);
            datos[numDatos - 1] = dato;
        }
        else {
            datos[numDatos] = dato;
        }
        
        numDatos++;
    }
}

template<typename T>
void cargarDatos(const char* nombreArchivo, T*& datos) {
    int numDatos = 0;
    
    cargarDatos(nombreArchivo, datos, numDatos, true);
}

template<typename T>
void incrementarEspacios(T*& datos, int& numDatos, int& cap, bool corte) {
    cap += INCREMENTO;
    
    if (datos == nullptr) {
        datos = new T[cap];
        if (corte) {
            asignarValorDeCorte(datos[numDatos]);
            numDatos++;
        }
    }
    else {
        T* aux = new T[cap];
        for (int i = 0; i < numDatos; i++) {
            aux[i] = datos[i];
        }
        delete[] datos;
        datos = aux;
    }
}

#endif /* FUNCIONES_H */
