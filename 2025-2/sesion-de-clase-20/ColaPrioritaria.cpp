#include "ColaPrioritaria.h"


ColaPrioritaria::ColaPrioritaria(const ColaPrioritaria& orig) : Cola(orig) {
}

void ColaPrioritaria::encolar(Pedido* pedido) {
    if (this->estaVacia() || 
            pedido->getPrioridad() == 
            PedidoPrioridad::REGULAR) {
        this->lista.insertarUltimo(pedido);
        return;
    }

    Nodo* actual = this->lista.cabeza;
    Nodo* anterior = nullptr;

    while (actual != nullptr && 
            actual->getPedido()->getPrioridad() == 
            PedidoPrioridad::ALTA) {
        anterior = actual;
        actual = actual->getSiguiente();
    }

    this->lista.insertar(anterior, pedido);
}
