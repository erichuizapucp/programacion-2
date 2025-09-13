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

// Funciones genéricas
void cargarDatos(const char*,
                 void*&,
                 bool (*)(ifstream&, void**&),
                 int (*)(const void*, const void*));
void incrementarCapacidad(void**&, int, int&);

int ordenarUsuarioPorFecha(const void*, const void*);
int ordenarUsuarioPorNombre(const void*, const void*);
int ordenarUsuarioPorEdad(const void*, const void*);
int ordenarPublicacionPorFecha(const void*, const void*);
int ordenarPublicacionPorContenido(const void*, const void*);
int ordenarMenciones(const void*, const void*);

// Funciones específicas
bool leerUsuario(ifstream&, void**&);
bool leerPublicacion(ifstream&, void**&);
bool leerMencion(ifstream&, char*&);

void procesarPublicaciones(void*&, const void*);
void cargarMenciones(ifstream&, char**&);
void asignarPublicaciones(void**&, const void*);
void asignarMenciones(void**&, const void*);

// Funciones utilitarias
int fechaRegistro(void*);
int fechaPublicacion(void*);
bool mencionadoEnPublicacion(const char*, const char**);
char* leerCadena(ifstream&, char=',');

// Funciones de impresión
void imprimirReporte(const char*, const void*);
void imprimirUsuario(ofstream&, const void**);
void imprimirPubsUsuario(ofstream&, const void**);
void imprimirPubUsuario(ofstream&, const void**);
void imprimirFecha(ofstream&, int);
void imprimirMencionesUsuario(ofstream&, const void**);
void imprimirMencion(ofstream&, const void**, const char*);

#endif //EJERCICIO03_FUNCIONES_H