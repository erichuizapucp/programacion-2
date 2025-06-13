/* 
 * File:   Restaurante.cpp
 * Author: erichuiza
 * 
 * Created on May 2, 2025, 5:21 PM
 */

#include "Restaurante.h"
#include "Cliente.h"
#include "PedidoRegular.h"
#include "PedidoPrioritario.h"
#include "PedidoInfo.h"
#include "Comparadores.h"


void Restaurante::cargarMeseros(const string nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    
    Mesero mesero;
    while (archivo >> mesero) {
        this->meseros.push_back(mesero);
    }
    
    sort(this->meseros.begin(), 
            this->meseros.end(), 
            OrdenarMeseroPorExperiencia());
}

void Restaurante::cargarClientes(const string nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    
    Cliente cliente;
    while (archivo >> cliente) {
        this->clientes.push_back(cliente);
    }
}

void Restaurante::cargarPedidos(const string nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    
    int prioridad;
    while (!archivo.eof() && archivo >> prioridad) {
        archivo.ignore();
        
        Pedido *pedido;
        switch (prioridad) {
            case 0:
                pedido = new PedidoRegular();
                break;
            case 1:
                pedido = new PedidoPrioritario();
                break;
        }
        
        if (archivo >> *pedido) {
            PedidoInfo pedidoInfo(pedido);
            this->colaPedidos.push(pedidoInfo);
        }
    }
}

void Restaurante::reportePedidos(const string nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out);
    
    archivo 
        << left << setw(10) << "PRIORITARIO"
        << left << setw(15) << "CODIGO"
        << setw(15) << "DNI"
        << setw(50) << "PLATO"
        << endl;
    
    // Copio la cola porque la cola prioritaria de la STL no tiene
    // iteradores directamente, así que copiamos para mantener la cola de pedidos 
    // intacta.
    auto copia = this->colaPedidos;
    while (!copia.empty()) {
        const PedidoInfo& pedido = copia.top();
        archivo << *pedido.getPedido();
        
        copia.pop();
    }
}

void Restaurante::reporteMeseros(const string nombreArchivo) {
    ofstream os(nombreArchivo, ios::out);
    
    os 
        << left << setw(15) << "DNI"
        << setw(50) << "NOMBRE"
        << setw(15) << "SUELDO"
        << setw(15) << "EXPERIENCIA"
        << endl;

    for (auto it = 
            this->meseros.begin();it != 
            this->meseros.end(); it++) {
        os << *it;
    }
}

void Restaurante::reporteClientes(const string nombreArchivo) {
    ofstream os(nombreArchivo, ios::out);
    
    os 
        << left << setw(15) << "DNI"
        << setw(50) << "NOMBRE"
        << setw(20) << "TELEFONO"
        << setw(20) << "CORREO"
        << endl;

    for (vector<Cliente>::iterator it = this->clientes.begin();it != this->clientes.end(); it++) {
        os << *it;
    }
}
