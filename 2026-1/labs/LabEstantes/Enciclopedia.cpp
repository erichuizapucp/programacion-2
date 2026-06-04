#include "Enciclopedia.h"

Enciclopedia::Enciclopedia() : Libro() {
    volumen = 0;
}

Enciclopedia::Enciclopedia(const Enciclopedia& otro) : Libro(otro) {
    volumen = otro.volumen;
}

Enciclopedia& Enciclopedia::operator=(const Enciclopedia& otro) {
    if (this == &otro) {
        return *this;
    }
    Libro::operator=(otro);
    volumen = otro.volumen;
    return *this;
}

int Enciclopedia::getVolumen() const { return volumen; }

void Enciclopedia::setVolumen(int valor) { volumen = valor; }
