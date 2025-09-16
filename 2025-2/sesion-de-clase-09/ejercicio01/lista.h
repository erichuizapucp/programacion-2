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
bool listaVacia(void* lista);
void insertarSiguiente(void* lista, void* nodo, void* dato);
bool removerSiguiente(void* lista, void* nodo, void*& datp);
void* buscar(void* lista, void* valor);
void imprimirLista(ostream&, void* lista, void (*)(ostream&, void*));
void destruir(void* lista);
void* primero(void* lista);
void* ultimo(void* lista);

void imprimirEntero(ostream &, void*);
void imprimirDoubles(ostream &, void*);
void imprimirCadena(ostream &, void*);

#endif //EJERCICIO01_LISTA_H