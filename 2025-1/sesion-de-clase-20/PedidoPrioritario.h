/* 
 * File:   PedidoPrioritario.h
 * Author: erichuiza
 *
 * Created on June 2, 2025, 1:59 PM
 */

#ifndef PEDIDOPRIORITARIO_H
#define PEDIDOPRIORITARIO_H

#include "Pedido.h"
#include "PedidoPrioridad.h"

class PedidoPrioritario : public Pedido {
public:
    PedidoPrioridad getPrioridad() const;
    Pedido* clonar() const;
    
    virtual ~PedidoPrioritario() = default;
};

#endif /* PEDIDOPRIORITARIO_H */

