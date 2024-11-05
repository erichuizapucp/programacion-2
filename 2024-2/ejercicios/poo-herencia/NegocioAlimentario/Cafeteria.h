/* 
 * File:   Cafeteria.h
 * Author: erichuiza
 *
 * Created on October 17, 2024, 11:58 AM
 */

#ifndef CAFETERIA_H
#define CAFETERIA_H

#include "Negocio.h"
#include "Inventario.h"
#include "Bebida.h"
#include "Insumo.h"


class Cafeteria : public Negocio<Bebida, Insumo> {
public:
    Cafeteria();
    virtual ~Cafeteria();
};

#endif /* CAFETERIA_H */

