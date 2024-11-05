/* 
 * File:   Producto.h
 * Author: erichuiza
 *
 * Created on October 17, 2024, 11:47 AM
 */

#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <fstream>
#include <iomanip>

#include "Registro.h"
#include "Ingrediente.h"
#include "Lista.h"

using namespace std;

class Producto : public Registro {
private:
    char* codigo;
    char* nombre;
    char* descripcion;
    double precio;
    int cantVentDiaria;
    bool disponible;
    Lista<Ingrediente> ingredientes;
protected:
    virtual bool crear(ifstream&);
    virtual void imprimir(ofstream&) const;
public:
    Producto();
    Producto(const Producto&);
    
    char* getCodigo() const;
    char* getNombre() const;
    char* getDescripcion() const;
    double getPrecio() const;
    int getCantVentDiaria() const;
    bool getDisponible() const;
    const Lista<Ingrediente>& getIngredientes() const;

    void setCodigo(const char*);
    void setNombre(const char*);
    void setDescripcion(const char*);
    void setPrecio(const double);
    void setCantVentDiaria(const int);
    void setDisponible(const bool);
    void setIngredientes(const Lista<Ingrediente>&);
    
    virtual void operator=(const Producto&);
    
    friend ofstream& operator<<(ofstream&, const Producto&);
//    friend bool operator>>(ifstream&, Producto&);
    
    virtual ~Producto();
};

#endif /* PRODUCTO_H */
