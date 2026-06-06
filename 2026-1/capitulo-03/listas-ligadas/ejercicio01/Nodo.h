#ifndef NODO_H
#define NODO_H

#include "Pedido.h"
#include "Lista.h"

class Lista;

class Nodo {
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
    
    virtual ~Nodo() = default;
};

#endif /* NODO_H */

