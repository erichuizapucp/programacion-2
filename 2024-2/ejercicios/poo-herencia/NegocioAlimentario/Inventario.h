/* 
 * File:   Inventario.h
 * Author: erichuiza
 *
 * Created on November 3, 2024, 3:30 PM
 */

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Servicio.h"

using namespace std;

template<typename T>
class Inventario : public Servicio<T> {
private:
public:
    Inventario();
    Inventario(const Inventario& orig);
    virtual ~Inventario();
};

template<typename T>
Inventario<T>::Inventario() : Servicio<T>() {
}

template<typename T>
Inventario<T>::Inventario(const Inventario& orig) : Servicio<T>(orig) {
    *this = orig;
}

template<typename T>
Inventario<T>::~Inventario() {
}

#endif /* INVENTARIO_H */

