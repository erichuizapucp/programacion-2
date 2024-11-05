#include "Bebida.h"

Bebida::Bebida() : Producto() {
}

Bebida::Bebida(const Bebida& orig) : Producto(orig) {
    *this = orig;
}

Bebida::~Bebida() {
}
