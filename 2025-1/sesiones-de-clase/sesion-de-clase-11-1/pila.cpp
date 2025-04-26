#include "pila.h"

void apilar(Pila& pila, const void* data) {
    insertar(pila, pila.cabeza, data);
}

bool desapilar(Pila& pila, void*& data) {
    return remover(pila, pila.cabeza, data);
}