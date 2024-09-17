/* 
 * File:   cola.h
 * Author: erichuiza
 *
 * Created on September 15, 2024, 10:28 PM
 */

#ifndef COLA_H
#define COLA_H

#include "lista.h"

using Cola = Lista;

void encolar(Cola&, const void* data);
bool desencolar(Cola&, void*&);

#endif /* COLA_H */

