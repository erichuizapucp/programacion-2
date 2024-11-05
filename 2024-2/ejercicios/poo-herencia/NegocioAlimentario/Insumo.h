/* 
 * File:   InsumoInventario.h
 * Author: erichuiza
 *
 * Created on October 6, 2024, 7:09 PM
 */

#ifndef INSUMOINVENTARIO_H
#define INSUMOINVENTARIO_H

#include <iostream>
#include <cstring>

#include "Registro.h"

using namespace std;

class Insumo : public Registro {
private:
    char* codigo;
    char* nombre;
    double cantDisponible;
    double cantRequerida;
    char* unidadMedida;
protected:
    virtual bool crear(ifstream&);
    virtual void imprimir(ofstream&) const;
public:
    Insumo();
    Insumo(const Insumo& orig);
    
    char* getCodigo() const;
    char* getNombre() const;
    double getCantDisponible() const;
    double getCantRequerida() const;
    char* getUnidadMedida() const;
    
    void setCodigo(const char*);
    void setNombre(const char*);
    void setCantDisponible(const double);
    void setCantRequerida(const double);
    void setUnidadMedida(const char*);
    
    void operator=(const Insumo&);
    
    virtual ~Insumo();
};

#endif /* INSUMOINVENTARIO_H */

