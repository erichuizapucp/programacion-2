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

void cargarUsuarios(const char*, void*&);
void cargarPublicaciones(const char*, void*&);
void procesarPublicaciones(void*&, const void*);

void cargarMenciones(ifstream&, char**&);
void asignarPublicaciones(void**&, const void*);
void asignarMenciones(void**&, const void*);

void incrementarUsuarios(void**&, int, int&);
void incrementarPublicaciones(void**&, int, int&);

bool leerUsuario(ifstream&, void**&);
bool leerPublicacion(ifstream&, void**&);
bool leerMencion(ifstream&, char*&);

void insertarUsuarioOrdenado(void**&, void**, int);
void insertarPublicacionOrdenado(void**&, void**, int);

int fechaRegistro(void*);
int fechaPublicacion(void*);
char* leerCadena(ifstream&, char=',');

void imprimirReporte(const char*, const void*);
void imprimirUsuario(ofstream&, const void**);
void imprimirPubsUsuario(ofstream&, const void**);
void imprimirPubUsuario(ofstream&, const void**);
void imprimirFecha(ofstream&, int);
void imprimirMencionesUsuario(ofstream&, const void**);
void imprimirMencion(ofstream&, const void**, const char*);
bool mencionadoEnPublicacion(const char*, const char**);

#endif //EJERCICIO03_FUNCIONES_H