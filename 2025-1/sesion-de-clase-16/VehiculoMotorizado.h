#ifndef VEHICULOMOTORIZADO_H
#define VEHICULOMOTORIZADO_H

#include "Carreta.h"


class VehiculoMotorizado : public Carreta {
private:
    int cantMotores;
    int tipoCombustible;
public:
    VehiculoMotorizado();
    VehiculoMotorizado(int, double, int, int, int, int);
    
    int getCantMotores() const;
    void setCantMotores(int);
    int getTipoCombustible() const;
    void setTipoCombustible(int);
    
    VehiculoMotorizado(const VehiculoMotorizado& orig);
    virtual ~VehiculoMotorizado();
};

#endif /* VEHICULOMOTORIZADO_H */

