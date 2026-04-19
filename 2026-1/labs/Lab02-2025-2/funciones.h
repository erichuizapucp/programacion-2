//
// Created by Eric Huiza on 9/10/25.
//

#ifndef LAB02_FUNCIONES_H
#define LAB02_FUNCIONES_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

void cargarCategorias(const char*, char***&);
void cargarStreamers(const char*, char***&, int**&, long long**&);
void cargarComentarios(const char*, char***&, char***&);
void cargarEtiquetas(ifstream&, char**&);

void incrementarCategorias(char***&, int, int&);
void incrementarStreamers(char***&, int, int);
void incrementarFechasPromedios(int**&, int, int);
void incrementarTiemposRepSegidores(long long**&, int, int);
void incrementarComentarios(char***&, int, int);
void incrementarEtiquetas(char***&, int, int);

void insertarOrdenado(char***&, int**&, long long**&, char**&, int*&, long long*&, int);

bool leerCategoria(ifstream&, char**&);
bool leerStreamer(ifstream&, char**&, int*&, long long*&);
bool leerComentario(ifstream&, char**&, char**&);
bool leerEtiqueta(ifstream&, char*&);

char* leerCadena(ifstream&, char=',');
int leerFecha(ifstream&);

void imprimirReporte(const char*, const char***, const char***, const int**,
                     const long long**, const char***,  const char***);
void imprimirCategoria(ofstream&, const char**);
void imprimirStreamersEnCategoria(ofstream&, const char***, const int**, const long long**, const char***,
                                  const char***, const char*);
void imprimirStreamer(ofstream&, const char**, const int*, const long long*, const char***, const char***);
void imprimirEtiquetas(ofstream&, const char**, const char***, const char***);
void imprimirFecha(ofstream&, int);
bool esEtiquedoEnComentario(const char**, const char*);

#endif //LAB02_FUNCIONES_H