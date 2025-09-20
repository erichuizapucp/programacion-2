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

// Funciones públicas
void cargarDatos(const char*,
                 void*&,
                 bool (*)(ifstream&, void**&),
                 int (*)(const void*, const void*));
void procesarDatos(void*, void*, void*, void*);
void imprimirReporte(const char*, const void*);

void incrementarCapacidad(void**&, int, int&);

int ordenarUsuarioPorFecha(const void*, const void*);
int ordenarUsuarioPorNombre(const void*, const void*);
int ordenarUsuarioPorEdad(const void*, const void*);
int ordenarPublicacionPorFecha(const void*, const void*);
int ordenarPublicacionPorContenido(const void*, const void*);
int ordenarMenciones(const void*, const void*);
int ordenarLikePorFechaHora(const void*, const void*);
int ordenarSolicitudPorFecha(const void*, const void*);

// Funciones específicas
bool leerUsuario(ifstream&, void**&);
bool leerPublicacion(ifstream&, void**&);
bool leerMencion(ifstream&, char*&);
bool leerLike(ifstream&, void**&);
bool leerSolicitud(ifstream&, void**&);

void cargarMenciones(ifstream&, char**&);
void asignarPublicaciones(void**&, const void*);
void asignarMenciones(void**&, const void*);
void asignarLikes(void**, const void*);
void asignarSolicitud(void**, const void*);

// Funciones utilitarias
int fechaRegistro(void*);
int fechaPublicacion(void*);
bool mencionadoEnPublicacion(const char*, const char**);
char* leerCadena(ifstream&, char=',');

// Funciones de impresión
void imprimirUsuario(ostream&, const void**);
void imprimirPubsUsuario(ostream&, const void**);
void imprimirPubUsuario(ostream&, const void**);
void imprimirFecha(ostream&, int);
void imprimirFechaHora(ostream&, long long);
void imprimirMencionesUsuario(ostream&, const void**);
void imprimirMencion(ostream&, const void**, const char*);
void imprimirLikesPubUsuario(ostream&, const void**);
void imprimirLike(ostream&, void*);
void imprimirSolicitudedUsuario(ostream&, void**);
void imprimirSolicitud(ostream&, void*);


#endif //EJERCICIO03_FUNCIONES_H