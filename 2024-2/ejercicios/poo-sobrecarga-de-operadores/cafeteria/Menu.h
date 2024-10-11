/* 
 * File:   Menu.h
 * Author: erichuiza
 *
 * Created on October 7, 2024, 10:53 AM
 */

#ifndef MENU_H
#define MENU_H

#include "Bebida.h"
#include "enums.h"

using namespace std;

class Menu {
private:
    Bebida* bebidas;
    int cantidad;
public:
    Menu();
    Menu(const Menu& orig);
    
    void cargarBebidas(ifstream&);
    void verificar();
    Bebida* buscarBebida(const char*);
    
    Bebida* getBebidas() const;
    int getCantidad() const;
    
    ~Menu();
};

#endif /* MENU_H */

