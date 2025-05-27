/* 
 * File:   VehiculoElectrico.h
 * Author: erichuiza
 *
 * Created on May 14, 2025, 7:48 PM
 */

#ifndef VEHICULOELECTRICO_H
#define VEHICULOELECTRICO_H

#include "VehiculoMotorizado.h"


class VehiculoElectrico : public VehiculoMotorizado {
private:
    int tipoBateria;
    int cantCeldas;
public:
    VehiculoElectrico();
    VehiculoElectrico(const VehiculoElectrico& orig);
    virtual ~VehiculoElectrico();
};

#endif /* VEHICULOELECTRICO_H */

