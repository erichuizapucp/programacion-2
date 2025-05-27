/* 
 * File:   VehiculoCombustion.h
 * Author: erichuiza
 *
 * Created on May 14, 2025, 7:46 PM
 */

#ifndef VEHICULOCOMBUSTION_H
#define VEHICULOCOMBUSTION_H

#include "VehiculoMotorizado.h"


class VehiculoCombustion : public VehiculoMotorizado {
private:
    bool gasolina;
    bool petroleo;
    bool GNV;
    bool GLP;
public:
    VehiculoCombustion();
    VehiculoCombustion(const VehiculoCombustion& orig);
    virtual ~VehiculoCombustion();
};

#endif /* VEHICULOCOMBUSTION_H */

