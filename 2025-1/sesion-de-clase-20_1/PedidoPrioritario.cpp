/* 
 * File:   PedidoPrioritario.cpp
 * Author: erichuiza
 * 
 * Created on June 2, 2025, 1:59 PM
 */

#include "PedidoPrioritario.h"


PedidoPrioridad PedidoPrioritario::getPrioridad() const {
    return PedidoPrioridad::ALTA;
}

Pedido* PedidoPrioritario::clonar() const {
    return new PedidoPrioritario(*this);
}
