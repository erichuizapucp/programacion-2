#include "Cola.h"

void Cola::encolar(Pedido* pedido) {
    this->lista.insertarUltimo(pedido);
}

Pedido* Cola::desencolar() {
    Pedido* primero;
    if (this->lista.removerPrimero(primero)) {
        return primero;
    }

    return nullptr;
}

void Cola::imprimir(ostream& os) {
    this->lista.imprimir(os);
}

bool Cola::estaVacia() const {
    return this->lista.estaVacia();
}
