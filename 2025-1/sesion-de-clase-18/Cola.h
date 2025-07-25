/* 
 * File:   Cola.h
 * Author: erichuiza
 *
 * Created on June 2, 2025, 2:50 PM
 */

#ifndef COLA_H
#define COLA_H

#include <iostream>
#include "Lista.h"

using namespace std;

class Cola {
protected:
    Lista lista;
public:
    Cola() = default;
    
    virtual void encolar(Pedido*);
    virtual Pedido* desencolar();
    bool estaVacia() const;
    virtual void imprimir(ostream&);
    
    virtual ~Cola() = default;
};

#endif /* COLA_H */

