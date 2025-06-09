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
#include <iomanip>

#include "Mesero.h"
#include "Cliente.h"
#include "Reclamo.h"
#include "Cola.h"
#include "ColaPrioritaria.h"
#include <vector>


using namespace std;

class Restaurante {
private:
    vector<Mesero> meseros;
    vector<Cliente> clientes;
    
    ColaPrioritaria<Pedido> colaPedidos;
    Cola<Reclamo> reclamos;
    
    void incrementarMeseros(int&, int&);
    void incrementarClientes(int&, int&);
public:
//    Restaurante();
//    Restaurante(const Restaurante&);
    
    void cargarMeseros(const string);
    void reporteMeseros(const string);
    
    void cargarClientes(const string);
    void reporteClientes(const string);
    
    void cargarPedidos(const string);
    void reportePedidos(const string);
    
//    virtual ~Restaurante();
};

#endif /* RESTAURANTE_H */

