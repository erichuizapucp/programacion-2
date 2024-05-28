/* 
 * File:   cola.h
 * Author: erichuiza
 *
 * Created on May 27, 2024, 12:07 PM
 */

#ifndef COLA_H
#define COLA_H

#include "nodo.h"

class Cola {
private:
    Nodo* frente;
    Nodo* fondo;
public:
    Cola();
    void encola(void* dato);
    void* desencola();
    bool colaVacia();
    
    Nodo* getFrente();
    Nodo* getFondo();
    
    ~Cola();
};

#endif /* COLA_H */

