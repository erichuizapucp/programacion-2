/* 
 * File:   PedidoPrioritario.cpp
 * Author: erichuiza
 * 
 * Created on June 2, 2025, 1:59 PM
 */

#include "PedidoPrioritario.h"

PedidoPrioritario::PedidoPrioritario() : Pedido() {
}

PedidoPrioritario::PedidoPrioritario(const PedidoPrioritario& orig) : Pedido(orig) {
    *this = orig;
}

PedidoPrioritario& PedidoPrioritario::operator=(const PedidoPrioritario& orig) {
    Pedido::operator=(orig);
    return *this;
}

PedidoPrioridad PedidoPrioritario::getPrioridad() const {
    return PedidoPrioridad::ALTA;
}

Pedido* PedidoPrioritario::clonar() const {
    return new PedidoPrioritario(*this);
}

PedidoPrioritario::~PedidoPrioritario() {
}
