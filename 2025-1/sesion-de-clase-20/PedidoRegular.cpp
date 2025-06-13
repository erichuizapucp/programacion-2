/* 
 * File:   PedidoRegular.cpp
 * Author: erichuiza
 * 
 * Created on June 2, 2025, 1:59 PM
 */

#include "PedidoRegular.h"


PedidoPrioridad PedidoRegular::getPrioridad() const {
    return PedidoPrioridad::REGULAR;
}

Pedido* PedidoRegular::clonar() const {
    return new PedidoRegular(*this);
}
