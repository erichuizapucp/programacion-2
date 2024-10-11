/* 
 * File:   Cafeteria.h
 * Author: erichuiza
 *
 * Created on October 6, 2024, 7:08 PM
 */

#ifndef CAFETERIA_H
#define CAFETERIA_H

#include <iostream>
#include <fstream>

#include "Menu.h"
#include "Inventario.h"
#include "enums.h"

using namespace std;

class Cafeteria {
private:
    Inventario inventario;
    Menu menu;
    
    bool cargarIngrediente(ifstream&);
public:
    Cafeteria();
    Cafeteria(const Cafeteria& orig);
    
    void cargarInventario(const char*);
    void cargarMenu(const char*);
    void actualizarMenu(const char*);
    void reporteMenu(const char*);
    
    ~Cafeteria();
};

#endif /* CAFETERIA_H */

