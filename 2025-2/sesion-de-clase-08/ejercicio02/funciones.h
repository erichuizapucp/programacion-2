//
// Created by Eric Huiza on 9/4/25.
//

#ifndef EJERCICIO03_FUNCIONES_H
#define EJERCICIO03_FUNCIONES_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>


using namespace std;

void cargarDatos(const char*, void*&,
                 bool (*)(ifstream&, void**&),
                 int (*)(const void*, const void*));

int cmpUsuariosPorFechaRegistro(const void*, const void*);
int cmpUsuariosPorNombre(const void*, const void*);
int cmpPubsPorFecha(const void*, const void*);
int cmpMenciones(const void*, const void*);

void procesarPublicaciones(void*&, const void*);
void cargarMenciones(ifstream&, char**&);
void asignarPublicaciones(void**&, const void*);
void asignarMenciones(void**&, const void*);

void incrementarCapacidad(void**&, int, int&);

bool leerUsuario(ifstream&, void**&);
bool leerPublicacion(ifstream&, void**&);
bool leerMencion(ifstream&, char*&);

void insertarUsuarioOrdenado(void**&, void**, int);
void insertarPublicacionOrdenado(void**&, void**, int);

int fechaRegistro(void*);
int fechaPublicacion(void*);
bool mencionadoEnPublicacion(const char*, const char**);
char* leerCadena(ifstream&, char=',');

void imprimirReporte(const char*, const void*);
void imprimirUsuario(ofstream&, const void**);
void imprimirPubsUsuario(ofstream&, const void**);
void imprimirPubUsuario(ofstream&, const void**);
void imprimirFecha(ofstream&, int);
void imprimirMencionesUsuario(ofstream&, const void**);
void imprimirMencion(ofstream&, const void**, const char*);

#endif //EJERCICIO03_FUNCIONES_H