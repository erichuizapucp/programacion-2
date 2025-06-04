/* 
 * File:   PedidoRegular.cpp
 * Author: erichuiza
 * 
 * Created on June 2, 2025, 1:59 PM
 */

#include "PedidoRegular.h"

PedidoRegular::PedidoRegular() : Pedido() {
}

PedidoRegular::PedidoRegular(const PedidoRegular& orig) : Pedido(orig) {
    *this=orig;
}

PedidoRegular& PedidoRegular::operator=(const PedidoRegular& orig) {
    Pedido::operator=(orig);
    return *this;
}

PedidoPrioridad PedidoRegular::getPrioridad() const {
    return PedidoPrioridad::REGULAR;
}

Pedido* PedidoRegular::clonar() const {
    return new PedidoRegular(*this);
}

PedidoRegular::~PedidoRegular() {
}
