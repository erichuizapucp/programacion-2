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
private:
public:
    PedidoPrioritario();
    PedidoPrioritario(const PedidoPrioritario& orig);
    
    PedidoPrioritario& operator=(const PedidoPrioritario&);
    PedidoPrioridad getPrioridad() const;
    Pedido* clonar() const;
    
    virtual ~PedidoPrioritario();
};

#endif /* PEDIDOPRIORITARIO_H */

