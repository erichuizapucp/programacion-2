/* 
 * File:   VehiculoHidrogeno.h
 * Author: erichuiza
 *
 * Created on May 14, 2025, 7:49 PM
 */

#ifndef VEHICULOHIDROGENO_H
#define VEHICULOHIDROGENO_H

#include "VehiculoMotorizado.h"


class VehiculoHidrogeno : public VehiculoMotorizado {
private:
    int catalizador;
public:
    VehiculoHidrogeno();
    VehiculoHidrogeno(const VehiculoHidrogeno& orig);
    virtual ~VehiculoHidrogeno();
};

#endif /* VEHICULOHIDROGENO_H */

