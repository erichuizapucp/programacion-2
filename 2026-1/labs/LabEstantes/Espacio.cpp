#include "Espacio.h"

Espacio::Espacio() {
    contenido = ' ';
    posx = 0;
    posy = 0;
}

char Espacio::getContenido() const {
    return contenido;
}

int Espacio::getPosx() const {
    return posx;
}

int Espacio::getPosy() const {
    return posy;
}

void Espacio::setContenido(char contenido) {
    this->contenido = contenido;
}

void Espacio::setPosx(int posx) {
    this->posx = posx;
}

void Espacio::setPosy(int posy) {
    this->posy = posy;
}

