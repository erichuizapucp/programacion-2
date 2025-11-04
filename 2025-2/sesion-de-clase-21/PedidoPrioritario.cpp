#include "PedidoPrioritario.h"

PedidoPrioritario::PedidoPrioritario(const PedidoPrioritario& orig) : Pedido(orig) {
    *this = orig;
}

PedidoPrioritario& PedidoPrioritario::operator=(const PedidoPrioritario& orig) {
    Pedido::operator=(orig);
    return *this;
}

PedidoPrioridad PedidoPrioritario::getPrioridad() const {
    return ALTA;
}

Pedido* PedidoPrioritario::clonar() const {
    return new PedidoPrioritario(*this);
}
