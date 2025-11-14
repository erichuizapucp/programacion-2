#ifndef PEDIDO_H
#define PEDIDO_H

#include "Registro.h"
#include "PedidoPrioridad.h"
#include <iostream>
#include <fstream>
#include <iomanip>


class Pedido : public Registro {
    char* codigo;
    int clienteDni;
    char* plato;
protected:
    istream& leer(istream&) override;
    ostream& imprimir(ostream&) const override;
public:
    Pedido();
    Pedido(const char*, int, const char*);
    Pedido(const Pedido& orig);
    
    int getClienteDni() const;
    void setClienteDni(int);
    char* getCodigo() const;
    void setCodigo(const char*);
    char* getPlato() const;
    void setPlato(const char*);

    Pedido& operator=(const Pedido&);
    
    virtual PedidoPrioridad getPrioridad() const = 0;
    virtual Pedido* clonar() const = 0;
    
    virtual ~Pedido();
};

#endif /* PEDIDO_H */

