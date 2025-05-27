/* 
 * File:   VehiculoHibrido.h
 * Author: erichuiza
 *
 * Created on May 14, 2025, 7:56 PM
 */

#ifndef VEHICULOHIBRIDO_H
#define VEHICULOHIBRIDO_H

#include "VehiculoCombustion.h"
#include "VehiculoElectrico.h"


class VehiculoHibrido : public VehiculoCombustion, public VehiculoElectrico {
private:
    
public:
    VehiculoHibrido();
    VehiculoHibrido(const VehiculoHibrido& orig);
    virtual ~VehiculoHibrido();
};

#endif /* VEHICULOHIBRIDO_H */
