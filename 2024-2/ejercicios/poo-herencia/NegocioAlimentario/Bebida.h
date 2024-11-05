/* 
 * File:   Bebida.h
 * Author: erichuiza
 *
 * Created on October 17, 2024, 11:47 AM
 */

#ifndef BEBIDA_H
#define BEBIDA_H

#include "Producto.h"

class Bebida : public Producto {
public:
    Bebida();
    Bebida(const Bebida&);
    virtual ~Bebida();
};

#endif /* BEBIDA_H */

