#ifndef VEHICULOHIDROGENO_H
#define VEHICULOHIDROGENO_H

#include "VehiculoMotorizado.h"


class VehiculoHidrogeno : public VehiculoMotorizado {
    int catalizador;
public:
    VehiculoHidrogeno();
    VehiculoHidrogeno(int, double, int, int, int, int, int);
    
    int getCatalizador() const;
    void setCatalizador(int catalizador);
    
    VehiculoHidrogeno(const VehiculoHidrogeno& orig);
    ~VehiculoHidrogeno();
};

#endif /* VEHICULOHIDROGENO_H */

