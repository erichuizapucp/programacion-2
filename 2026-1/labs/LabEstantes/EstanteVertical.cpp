#include "EstanteVertical.h"

EstanteVertical::EstanteVertical() : Estante() {
    cantidadEnciclopedias = 0;
}

Enciclopedia* EstanteVertical::getEnciclopedias() { return enciclopedias; }
int EstanteVertical::getCantidadEnciclopedias() const { return cantidadEnciclopedias; }
void EstanteVertical::setCantidadEnciclopedias(int valor) { cantidadEnciclopedias = valor; }

bool EstanteVertical::insertarEnciclopedia(const Enciclopedia& enciclopedia) {
    int ancho = enciclopedia.getAlto();
    int alto = enciclopedia.getAncho();
    int posx, posy;
    int area = ancho * alto;

    if (cantidadEnciclopedias >= 100) {
        return false;
    }
    if (area > obtenerEspaciosRestantes()) {
        return false;
    }
    if (getPesoActual() + enciclopedia.getPeso() > getPesoSoportado()) {
        return false;
    }
    if (not encontrarPosicion(ancho, alto, posx, posy)) {
        return false;
    }

    marcarRectangulo(posx, posy, ancho, alto, '*');
    enciclopedias[cantidadEnciclopedias++] = enciclopedia;
    setPesoActual(getPesoActual() + enciclopedia.getPeso());
    return true;
}
