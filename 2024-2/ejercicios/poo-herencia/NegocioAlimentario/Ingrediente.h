/* 
 * File:   Ingrediente.h
 * Author: erichuiza
 *
 * Created on October 7, 2024, 12:42 PM
 */

#ifndef INGREDIENTE_H
#define INGREDIENTE_H

#include "Insumo.h"


class Ingrediente : public Registro {
private:
    double cantidad;
    char* unidadMedida;
    Insumo* insumo;
protected:
    virtual bool crear(ifstream&);
    virtual void imprimir(ofstream&) const;
public:
    Ingrediente();
    Ingrediente(const Ingrediente& orig);
    
    Insumo* getInsumo() const;
    char* getUnidadMedida() const;
    double getCantidad() const;
    
    void setInsumo(Insumo*);
    void setUnidadMedida(const char*);
    void setCantidad(const double);
    
    void operator=(const Ingrediente&);
    
    virtual ~Ingrediente();
};

#endif /* INGREDIENTE_H */

