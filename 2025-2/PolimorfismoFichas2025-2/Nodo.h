/* 
 * File:   Nodo.h
 * Author: erichuiza
 *
 * Created on May 30, 2024, 11:31 PM
 */

#ifndef NODO_H
#define NODO_H

#include "Ficha.h"

using namespace std;

class Tablero;

class Nodo {
private:
    Ficha* dato;
    Nodo* siguiente;
public:
    Nodo(Ficha*);
    friend class Tablero;
};

#endif /* NODO_H */

