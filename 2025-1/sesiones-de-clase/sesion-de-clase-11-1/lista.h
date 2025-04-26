/* 
 * File:   lista.h
 * Author: erichuiza
 *
 * Created on September 15, 2024, 10:28 PM
 */

#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include "nodo.h"

using namespace std;

struct Lista {
    Nodo* cabeza;
    Nodo* cola;
    int longitud;
    void (*destruir)(void* datos);
};

void inicializar(Lista&, void(*)(void*));
void destruir(Lista&);
void insertar(Lista&, Nodo*, const void*);
bool remover(Lista&, Nodo*, void*&);
void recorrer(const Lista&, void(*)(const void*));
void recorrer(const Lista&, ofstream& os, void(*)(ofstream&, const void*));

#endif /* LISTA_H */

