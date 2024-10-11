/* 
 * File:   Bebida.h
 * Author: erichuiza
 *
 * Created on October 6, 2024, 7:09 PM
 */

#ifndef BEBIDA_H
#define BEBIDA_H

#include "Insumo.h"
#include "Ingrediente.h"

using namespace std;

class Bebida {
private:
    char* codigo;
    char* nombre;
    char* descripcion;
    char tipo;
    double precio;
    int cantVent;
    bool disponible;
    Ingrediente* ingredientes;
    int cantIngredientes;
    
    void incrementarIngredientes();
public:
    Bebida();
    Bebida(const Bebida& orig);
    
    char* getCodigo() const;
    char* getNombre() const;
    char* getDescripcion() const;
    char getTipo() const;
    double getPrecio() const;
    int getCantVent() const;
    bool getDisponible() const;
    const char* getNombreTipoBebida() const;
    Ingrediente* getIngredientes() const;
    int getCantIngredientes() const;
    
    void setCodigo(const char*);
    void setNombre(const char*);
    void setDescripcion(const char*);
    void setTipo(const char);
    void setPrecio(const double);
    void setCantVent(const int);
    void setDisponible(const bool);
    void verificarDisponibilidad();
    
    void operator<<(const Ingrediente);
    void operator=(const Bebida&);
    
    ~Bebida();
};

#endif /* BEBIDA_H */

