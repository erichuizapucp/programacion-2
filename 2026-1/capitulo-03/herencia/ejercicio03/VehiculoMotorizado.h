#ifndef VEHICULOMOTORIZADO_H
#define VEHICULOMOTORIZADO_H

#include "Carreta.h"


class VehiculoMotorizado : public Carreta {
    int cantMotores;
    int tipoCombustible;
public:
    VehiculoMotorizado();
    VehiculoMotorizado(int, double, int, int, int, int);
    VehiculoMotorizado(const VehiculoMotorizado& orig);

    int getCantMotores() const;
    void setCantMotores(int);
    int getTipoCombustible() const;
    void setTipoCombustible(int);

    ~VehiculoMotorizado();
};

#endif /* VEHICULOMOTORIZADO_H */

