#include "PedidoRegular.h"

PedidoRegular::PedidoRegular(const PedidoRegular& orig) : Pedido(orig) {
    *this=orig;
}

PedidoRegular& PedidoRegular::operator=(const PedidoRegular& orig) {
    Pedido::operator=(orig);
    return *this;
}

PedidoPrioridad PedidoRegular::getPrioridad() const {
    return REGULAR;
}

Pedido* PedidoRegular::clonar() const {
    return new PedidoRegular(*this);
}
