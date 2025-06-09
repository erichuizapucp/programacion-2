/* 
 * File:   Pedido.cpp
 * Author: erichuiza
 * 
 * Created on June 2, 2025, 1:19 PM
 */

#include "Pedido.h"


Pedido::Pedido(const string codigo, int clienteDni, const string plato) : Registro() {
    this->setCodigo(codigo);
    this->setClienteDni(clienteDni);
    this->setPlato(plato);
}

int Pedido::getClienteDni() const {
    return clienteDni;
}

void Pedido::setClienteDni(int clienteDni) {
    this->clienteDni = clienteDni;
}

string Pedido::getCodigo() const {
    return codigo;
}

void Pedido::setCodigo(const string codigo) {
    this->codigo = codigo;
}

string Pedido::getPlato() const {
    return plato;
}

void Pedido::setPlato(const string plato) {
    this->plato = plato;
}

bool Pedido::cargarDatos(ifstream& archivo) {
    if (!archivo.eof()) {
        getline(archivo, this->codigo, ',');
        archivo >> clienteDni;
        archivo.ignore();
        getline(archivo, this->plato, '\n');
        
        this->setCodigo(codigo);
        this->setClienteDni(clienteDni);
        this->setPlato(plato);
        
        return true;
    }
    
    return false;
}

void Pedido::imprimir(ostream& os) const {
    os 
        << left << setw(10) << (this->getPrioridad() == PedidoPrioridad::ALTA ? "Si" : "No")
        << setw(15) << this->codigo
        << setw(15) << this->clienteDni
        << setw(50) << this->plato
        << endl;
}
