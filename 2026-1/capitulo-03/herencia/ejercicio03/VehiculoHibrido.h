#ifndef VEHICULOHIBRIDO_H
#define VEHICULOHIBRIDO_H

#include "VehiculoCombustion.h"
#include "VehiculoElectrico.h"


class VehiculoHibrido : public VehiculoCombustion, public VehiculoElectrico {
public:
    VehiculoHibrido();
    VehiculoHibrido(const VehiculoHibrido& orig);
    ~VehiculoHibrido();
};

#endif /* VEHICULOHIBRIDO_H */
