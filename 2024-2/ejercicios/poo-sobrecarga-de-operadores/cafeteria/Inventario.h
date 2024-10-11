/* 
 * File:   Inventario.h
 * Author: erichuiza
 *
 * Created on October 7, 2024, 10:55 AM
 */

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <iostream>
#include <fstream>

#include "Insumo.h"
#include "enums.h"

using namespace std;

class Inventario {
private:
    Insumo* insumos;
    int cantidad;
public:
    Inventario();
    Inventario(const Inventario& orig);
    
    void cargarInsumos(ifstream&);
    Insumo* buscarInsumo(const char*);
    
    int getCantidad();
    
    ~Inventario();
};

#endif /* INVENTARIO_H */

