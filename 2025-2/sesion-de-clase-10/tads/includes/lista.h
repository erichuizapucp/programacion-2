//
// Created by Eric Huiza on 9/11/25.
//

#ifndef EJERCICIO01_LISTA_H
#define EJERCICIO01_LISTA_H

#include "enums.h"
#include <iostream>
#include <fstream>

using namespace std;

void* crearLista();
bool listaVacia(void*);
void insertarSiguiente(void*, void*, void*);
bool removerSiguiente(void*, void*, void*&);
void* buscar(void*, void*);
void imprimirLista(ostream&, void*, void (*)(ostream&, void*));
void destruir(void*);
void* primero(void*);
void* ultimo(void*);

void imprimirEntero(ostream &, void*);
void imprimirDouble(ostream &, void*);
void imprimirCadena(ostream &, void*);

#endif //EJERCICIO01_LISTA_H