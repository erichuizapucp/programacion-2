#include "Novela.h"
#include <cstring>

Novela::Novela() : Libro() {
    tipo = nullptr;
}

Novela::Novela(const Novela& otra) : Libro(otra) {
    tipo = nullptr;
    *this = otra;
}

Novela& Novela::operator=(const Novela& otra) {
    if (this == &otra) {
        return *this;
    }
    Libro::operator=(otra);
    setTipo(otra.tipo);
    return *this;
}

char* Novela::getTipo() const {
    return tipo;
}

void Novela::setTipo(const char* nuevo) {
    delete[] tipo;
    if (nuevo == nullptr) {
        tipo = nullptr;
        return;
    }
    tipo = new char[strlen(nuevo) + 1];
    strcpy(tipo, nuevo);
}

Novela::~Novela() {
    delete[] tipo;
}
