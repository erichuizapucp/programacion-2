/* 
 * File:   Nodo.h
 * Author: erichuiza
 *
 * Created on June 2, 2025, 2:24 PM
 */

#ifndef NODO_H
#define NODO_H

#include "Pedido.h"
#include "Lista.h"

class Lista;

class Nodo {
private:
    Pedido* pedido;
    Nodo* siguiente;
public:
    Nodo();
    Nodo(const Nodo& orig);
    
    Pedido* getPedido() const;
    void setPedido(Pedido*);
    Nodo* getSiguiente() const;
    void setSiguiente(Nodo*);
    
    friend class Lista;
    
    virtual ~Nodo();
};

#endif /* NODO_H */

