/* 
 * File:   PedidoRegular.h
 * Author: erichuiza
 *
 * Created on June 2, 2025, 1:59 PM
 */

#ifndef PEDIDOREGULAR_H
#define PEDIDOREGULAR_H

#include "Pedido.h"
#include "PedidoPrioridad.h"

class PedidoRegular : public Pedido {
public:
    PedidoRegular& operator=(const PedidoRegular&);
    PedidoPrioridad getPrioridad() const;
    Pedido* clonar() const;
    
    virtual ~PedidoRegular() = default;
};

#endif /* PEDIDOREGULAR_H */

