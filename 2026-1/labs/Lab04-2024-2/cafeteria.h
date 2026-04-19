#ifndef CAFETERIA_H
#define CAFETERIA_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "enums.h"

using namespace std;

void cargarInventario(const char*, void*&);
void cargarInventario(ifstream&, void*&);

void cargarMenu(const char*, void*&);
void cargarMenu(ifstream&, void*&);

void actualizarMenu(const char*, void*, void*);
void actualizarMenu(ifstream&, void*, void*);

void reporteMenu(const char*, const void*);
void reporteMenu(ofstream&, const void*);

bool cargarInsumoInventario(ifstream&, void*&);
bool cargarBebida(ifstream&, void*&);
bool cargarInsumoBebida(ifstream&, const void*, void*&, char*&);
void* buscarInsumo(const char*, const void*);
void* buscarBebida(const char*, const void*);
void agregarInsumoBebida(void*&, void*);
void incrementarInsumos(void**&, int, int);
int numInsumosBebida(const void*);
void verificarInventario(void*);
bool existeSuficienteInsumoEnInventario(void*, int);
const char* getNombreTipoBebida(const char);
char* leeCadena(ifstream&, char=',');

#endif /* CAFETERIA_H */
