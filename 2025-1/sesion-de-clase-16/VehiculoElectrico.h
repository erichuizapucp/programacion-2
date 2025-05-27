#ifndef VEHICULOELECTRICO_H
#define VEHICULOELECTRICO_H

#include "VehiculoMotorizado.h"


class VehiculoElectrico : virtual public VehiculoMotorizado {
private:
    int tipoBateria;
    int cantCeldas;
public:
    VehiculoElectrico();
    VehiculoElectrico(int, double, int, int, int, int, int, int);
    
    int getCantCeldas() const;
    void setCantCeldas(int cantCeldas);
    int getTipoBateria() const;
    void setTipoBateria(int tipoBateria);
    
    VehiculoElectrico(const VehiculoElectrico& orig);
    virtual ~VehiculoElectrico();
};

#endif /* VEHICULOELECTRICO_H */

