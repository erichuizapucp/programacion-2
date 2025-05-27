/* 
 * File:   VehiculoMotorizado.h
 * Author: erichuiza
 *
 * Created on May 14, 2025, 7:43 PM
 */

#ifndef VEHICULOMOTORIZADO_H
#define VEHICULOMOTORIZADO_H

#include "Carreta.h"


class VehiculoMotorizado : public Carreta {
private:
    int cantMotores;
    int tipoCombustible;
public:
    VehiculoMotorizado();
    VehiculoMotorizado(const VehiculoMotorizado& orig);
    virtual ~VehiculoMotorizado();
};

#endif /* VEHICULOMOTORIZADO_H */

