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
#include "PedidoInfo.h"
#include <vector>
#include <queue> // para manejar colas y colas prioritarias


using namespace std;

class Restaurante {
private:
    vector<Mesero> meseros;
    vector<Cliente> clientes;
    
    priority_queue<PedidoInfo> colaPedidos;
    queue<Reclamo> reclamos;
    
//    void incrementarMeseros(int&, int&);
//    void incrementarClientes(int&, int&);
public:    
    void cargarMeseros(const string);
    void reporteMeseros(const string);
    
    void cargarClientes(const string);
    void reporteClientes(const string);
    
    void cargarPedidos(const string);
    void reportePedidos(const string);
};

#endif /* RESTAURANTE_H */

