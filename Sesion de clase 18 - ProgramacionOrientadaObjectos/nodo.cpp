#include "nodo.h"

Nodo::Nodo(void* dato) : dato(dato), siguiente(nullptr) {
}

//void Nodo::setSiguiente(Nodo* siguiente) {
//    this->siguiente = siguiente;
//}
//
//void* Nodo::getDato() {
//    return dato;
//}
//
//Nodo* Nodo::getSiguiente() {
//    return siguiente;
//}

Nodo::~Nodo() {
    //TODO: revisar durante las plantillas de clase
}