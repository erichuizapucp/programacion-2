#ifndef RESTAURANTE_H
#define RESTAURANTE_H

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "Mesero.h"
#include "Cliente.h"
#include "ColaPrioritaria.h"

using namespace std;

class Restaurante {
    Mesero** meseros;
    Cliente** clientes;
    
    ColaPrioritaria colaPedidos;
    
    void incrementarMeseros(int&, int&);
    void incrementarClientes(int&, int&);
public:
    Restaurante();

    void cargarMeseros(const char*);
    void reporteMeseros(const char*) const;
    
    void cargarClientes(const char*);
    void reporteClientes(const char*) const;
    
    void cargarPedidos(const char*);
    void reportePedidos(const char*);
    
    virtual ~Restaurante();
};

#endif /* RESTAURANTE_H */

