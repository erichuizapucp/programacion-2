/* 
 * File:   Pedido.cpp
 * Author: erichuiza
 * 
 * Created on June 2, 2025, 1:19 PM
 */

#include "Pedido.h"

Pedido::Pedido() {
    this->codigo = nullptr;
    this->plato = nullptr;
}

Pedido::Pedido(const char* codigo, int clienteDni, const char* plato) : Registro() {
    this->setCodigo(codigo);
    this->setClienteDni(clienteDni);
    this->setPlato(plato);
} 

Pedido::Pedido(const Pedido& orig) : Registro(orig) {
    *this = orig;
}

int Pedido::getClienteDni() const {
    return clienteDni;
}

void Pedido::setClienteDni(int clienteDni) {
    this->clienteDni = clienteDni;
}

char* Pedido::getCodigo() const {
    return codigo;
}

void Pedido::setCodigo(const char* codigo) {
    if (this->codigo) {
        delete[] this->codigo;
    }
    
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

char* Pedido::getPlato() const {
    return plato;
}

void Pedido::setPlato(const char* plato) {
    if (this->plato) {
        delete[] this->plato;
    }
    
    this->plato = new char[strlen(plato) + 1];
    strcpy(this->plato, plato);
}

bool Pedido::cargarDatos(ifstream& archivo) {
    if (!archivo.eof()) {
        char* codigo = leerCadena(archivo);
        int clienteDni;
        archivo >> clienteDni;
        
        archivo.ignore();
        char* plato = leerCadena(archivo, '\n');
        
        this->setCodigo(codigo);
        this->setClienteDni(clienteDni);
        this->setPlato(plato);
        
        return true;
    }
    
    return false;
}

Pedido& Pedido::operator=(const Pedido& pedido) {
    this->setCodigo(pedido.getCodigo());
    this->setClienteDni(pedido.getClienteDni());
    this->setPlato(pedido.getPlato());
    
    return *this;
}

void Pedido::imprimir(ostream& os) const {
    os 
        << left << setw(10) << (this->getPrioridad() == PedidoPrioridad::ALTA ? "Si" : "No")
        << setw(15) << this->codigo
        << setw(15) << this->clienteDni
        << setw(50) << this->plato
        << endl;
}

Pedido::~Pedido() {
    delete[] codigo;
    delete[] plato;
}
