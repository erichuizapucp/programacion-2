/* 
 * File:   Cola.h
 * Author: erichuiza
 *
 * Created on November 8, 2024, 12:14 PM
 */

#ifndef COLA_H
#define COLA_H

#include "Lista.h"

template<typename T>
class Cola : public Lista<T> {
private:
    
public:
    Cola<T>();
    Cola<T>(const Cola& orig);
    ~Cola<T>();
    
    void encolar(T);
    bool desencolar(T&);
};

template<typename T>
Cola<T>::Cola() : Lista<T>() {
}

template<typename T>
Cola<T>::Cola(const Cola& orig) : Lista<T>(orig) {
}

template<typename T>
void Cola<T>::encolar(T dato) {
    this->insertar(this->getCola(), dato);
}

template<typename T>
bool Cola<T>::desencolar(T& dato) {
    return this->remover(nullptr, dato);
}

template<typename T>
Cola<T>::~Cola() {
}

#endif /* COLA_H */

