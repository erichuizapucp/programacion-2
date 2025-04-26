/* 
 * File:   pila.h
 * Author: erichuiza
 *
 * Created on April 26, 2025, 12:40 PM
 */

#ifndef PILA_H
#define PILA_H

#include "lista.h"

using Pila = Lista;

void apilar(Pila&, const void* data);
bool desapilar(Pila&, void*&);

#endif /* PILA_H */

