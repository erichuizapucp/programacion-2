#ifndef LISTA_H
#define LISTA_H

class Nodo;
class Cola;
class ColaPrioritaria;

#include <iostream>
#include "Pedido.h"
#include "Nodo.h"

using namespace std;

class Lista {
    Nodo* cabeza;
    Nodo* cola;
    int longitud;
public:
    Lista();

    void insertarPrimero(Pedido*);
    void insertarUltimo(Pedido*);
    void insertar(Nodo*, Pedido*);
    bool removerPrimero(Pedido*&);
    bool removerUltimo(Pedido*&);
    bool remover(Nodo*, Pedido*&);
    bool estaVacia() const;

    void imprimir(ostream&) const;

    friend class Cola;
    friend class ColaPrioritaria;

    virtual ~Lista();
};

#endif /* LISTA_H */
