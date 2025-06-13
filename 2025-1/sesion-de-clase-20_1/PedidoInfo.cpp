/* 
 * File:   PedidoInfo.cpp
 * Author: erichuiza
 * 
 * Created on June 9, 2025, 11:54 AM
 */

#include "PedidoInfo.h"
#include "Pedido.h"


PedidoInfo::PedidoInfo(unique_ptr<Pedido> pedido) {
    this->pedido = std::move(pedido);
}

PedidoInfo::PedidoInfo(const PedidoInfo& orig) {
    *this = orig;
}

PedidoInfo& PedidoInfo::operator=(const PedidoInfo& orig) {
    this->pedido = std::unique_ptr<Pedido>(orig.getPedido()->clonar());
    return *this;
}

Pedido* PedidoInfo::getPedido() const {
    return pedido.get();
}

void PedidoInfo::setPedido(unique_ptr<Pedido> pedido) {
    this->pedido = std::move(pedido);
}

bool PedidoInfo::operator<(const PedidoInfo& pedido) const {
    return this->pedido->getPrioridad() <= pedido.pedido->getPrioridad();
}
