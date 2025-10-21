#ifndef VEHICULOHIBRIDO_H
#define VEHICULOHIBRIDO_H

#include "VehiculoCombustion.h"
#include "VehiculoElectrico.h"


class VehiculoHibrido : 
    public VehiculoCombustion, 
    public VehiculoElectrico {
private:
public:
    VehiculoHibrido();
    VehiculoHibrido(const VehiculoHibrido& orig);
    virtual ~VehiculoHibrido();
};

#endif /* VEHICULOHIBRIDO_H */
