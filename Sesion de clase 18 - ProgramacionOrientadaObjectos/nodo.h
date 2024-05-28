/* 
 * File:   Nodo.h
 * Author: erichuiza
 *
 * Created on May 27, 2024, 12:06 PM
 */

#ifndef NODO_H
#define NODO_H

class Cola;

class Nodo {
private:
    void* dato;
    Nodo* siguiente;
public:
    Nodo(void* dato);
//    Nodo* getSiguiente();
//    void setSiguiente(Nodo* siguiente);
//    void* getDato();
    
    friend class Cola;
    
    ~Nodo();
};

#endif /* NODO_H */

