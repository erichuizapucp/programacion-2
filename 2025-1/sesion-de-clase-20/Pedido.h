/* 
 * File:   Pedido.h
 * Author: erichuiza
 *
 * Created on June 2, 2025, 1:19 PM
 */

#ifndef PEDIDO_H
#define PEDIDO_H

#include "Registro.h"
#include "PedidoPrioridad.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>


class Pedido : public Registro {
private:
    string codigo;
    int clienteDni;
    string plato;
protected:
    virtual bool cargarDatos(ifstream&);
    virtual void imprimir(ostream&) const;
public:
    Pedido() = default;
    Pedido(const string, int, const string);
    
    int getClienteDni() const;
    void setClienteDni(int);
    string getCodigo() const;
    void setCodigo(const string);
    string getPlato() const;
    void setPlato(const string);
    
    virtual PedidoPrioridad getPrioridad() const = 0;
    virtual Pedido* clonar() const = 0;
    
    virtual ~Pedido() = default;
};

#endif /* PEDIDO_H */

