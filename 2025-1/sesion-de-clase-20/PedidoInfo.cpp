/* 
 * File:   PedidoInfo.cpp
 * Author: erichuiza
 * 
 * Created on June 9, 2025, 11:54 AM
 */

#include "PedidoInfo.h"
#include "Pedido.h"

PedidoInfo::PedidoInfo() {
    this->pedido = nullptr;
}

PedidoInfo::PedidoInfo(Pedido* pedido) {
    this->pedido = pedido;
}

PedidoInfo::PedidoInfo(const PedidoInfo& orig) {
    *this = orig;
}

Pedido* PedidoInfo::getPedido() const {
    return pedido;
}

void PedidoInfo::setPedido(Pedido* pedido) {
    this->pedido = pedido;
}

PedidoInfo& PedidoInfo::operator=(const PedidoInfo& orig) {
    this->pedido = orig.pedido->clonar();
    return *this;
}

bool PedidoInfo::operator<(const PedidoInfo& pedido) const {
    return this->pedido->getPrioridad() 
            <= pedido.pedido->getPrioridad();
}

PedidoInfo::~PedidoInfo() {
    delete pedido;
}

