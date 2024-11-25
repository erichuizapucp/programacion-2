/* 
 * File:   Pila.h
 * Author: erichuiza
 *
 * Created on November 8, 2024, 12:14 PM
 */

#ifndef PILA_H
#define PILA_H

#include <Lista.h>

template<typename T>
class Pila : public Lista<T>{
private:
public:
    Pila<T>();
    Pila<T>(const Pila<T>& orig);
    virtual ~Pila<T>();
    
    void apilar(T);
    bool desapilar(T&);
};

template<typename T>
Pila<T>::Pila() : Lista<T>() {
    
}

template<typename T>
Pila<T>::Pila(const Pila<T>& orig) : Lista<T>(orig) {
}

template<typename T>
void Pila<T>::apilar(T dato) {
    this->insertar(this->getCabeza(), dato);
}

template<typename T>
bool Pila<T>::desapilar(T& dato) {
    return this->remover(this->getCabeza(), dato);
}

template<typename T>
Pila<T>::~Pila() {
}

#endif /* PILA_H */

