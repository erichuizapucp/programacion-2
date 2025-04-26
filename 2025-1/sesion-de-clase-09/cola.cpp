#include "cola.h"

void encolar(Cola& cola, const void* data) {
    insertar(cola, cola.cola, data);
}

bool desencolar(Cola& cola, void*& data) {
    return remover(cola, nullptr, data);
}