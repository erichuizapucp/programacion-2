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

void cargarUsuarios(const char*, char***&, int**&);
void incrementarUsuarios(char***&, int, int);
void incrementarFechasEdades(int**&, int, int);

void cargarPublicaciones(const char*, int**&, char***&, char***&);
void cargarMenciones(ifstream&, char**&);
void incrementarIdsFechas(int**&, int, int);
void incrementarMenciones(char***&, int, int);
void incrementarPublicaciones(char***&, int, int);

bool leerUsuario(ifstream&, char**&);
bool leerFechaEdad(ifstream&, int*&);
bool leerPublicacion(ifstream&, char**&, char**&);
bool leerIdFecha(ifstream&, int*&);
bool leerMencion(ifstream&, char*&);

void insertarOrdenado(char***&, int**&, char**, int*, int);
void insertarOrdenado(int**&, char***&, char***&, int*, char**, char**, int);

void imprimirReporte(const char*, const char***, const int**, const int**, const char***, const char***);
void imprimirUsuario(ofstream&, const char**, const int*);
void imprimirPubsUsuario(ofstream&, const char*, const int**, const char***);
void imprimirPubUsuario(ofstream&, const char**, const int*);
void imprimirFecha(ofstream&, int);
void imprimirMencionesUsuario(ofstream&, const char*, const int**, const char***, const char***);
void imprimirMencion(ofstream&, const int*, const char**, const char*);
bool mencionadoEnPublicacion(const char*, const char**);

char* leerCadena(ifstream&, char=',');

#endif //EJERCICIO03_FUNCIONES_H