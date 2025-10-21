#ifndef VEHICULOCOMBUSTION_H
#define VEHICULOCOMBUSTION_H

#include "VehiculoMotorizado.h"


class VehiculoCombustion : virtual public VehiculoMotorizado {
private:
    bool gasolina;
    bool petroleo;
    bool GNV;
    bool GLP;
public:
    VehiculoCombustion();
    VehiculoCombustion(int, double, int, int, int, int, bool, bool, bool, bool);
    
    bool isGLP() const;
    void setGLP(bool GLP);
    bool isGNV() const;
    void setGNV(bool GNV);
    bool isGasolina() const;
    void setGasolina(bool gasolina);
    bool isPetroleo() const;
    void setPetroleo(bool petroleo);
    
    VehiculoCombustion(const VehiculoCombustion& orig);
    virtual ~VehiculoCombustion();
};

#endif /* VEHICULOCOMBUSTION_H */
