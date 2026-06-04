#include "EstanteHorizontal.h"

EstanteHorizontal::EstanteHorizontal() : Estante() {
    cantidadNovelas = 0;
}

Novela* EstanteHorizontal::getNovelas() {
    return novelas;
}

int EstanteHorizontal::getCantidadNovelas() const {
    return cantidadNovelas;
}

void EstanteHorizontal::setCantidadNovelas(int cantidadNovelas) {
    this->cantidadNovelas = cantidadNovelas;
}

bool EstanteHorizontal::insertarNovela(const Novela& novela) {
    int ancho = novela.getAncho();
    int alto = novela.getAlto();
    int posx, posy;
    int area = ancho * alto;

    if (cantidadNovelas >= 100) {
        return false;
    }
    if (area > obtenerEspaciosRestantes()) {
        return false;
    }
    if (getPesoActual() + novela.getPeso() > getPesoSoportado()) {
        return false;
    }
    if (not encontrarPosicion(ancho, alto, posx, posy)) {
        return false;
    }

    marcarRectangulo(posx, posy, ancho, alto, '*');
    novelas[cantidadNovelas++] = novela;
    setPesoActual(getPesoActual() + novela.getPeso());
    return true;
}
