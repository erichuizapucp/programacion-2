/* 
 * File:   Restaurante.h
 * Author: erichuiza
 *
 * Created on May 2, 2025, 5:21 PM
 */

#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "Mesero.h"
#include "Cliente.h"

using namespace std;

class Restaurante {
private:
    Mesero** meseros;
    Cliente** clientes;
    void incrementarMeseros(int&, int&);
    void incrementarClientes(int&, int&);
public:
    Restaurante();
    Restaurante(const Restaurante&);
    
    void cargarMeseros(const char*);
    void mostrarMeseros();
    
    void cargarClientes(const char*);
    void mostrarClientes();
    
    virtual ~Restaurante();
};

#endif /* RESTAURANTE_H */

