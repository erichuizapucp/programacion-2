#include "Estante.h"
#include <cstring>

int Estante::totalCeldas() const {
    return anchura * altura;
}

int Estante::indiceDesdeXY(int x, int y) const {
    return x * anchura + y;
}

Estante::Estante() {
    codigo = nullptr;
    anchura = 0;
    altura = 0;
    espacios = nullptr;
    pesoSoportado = 0;
    pesoActual = 0;
}

Estante::Estante(const Estante& otro) : Estante() {
    espacios = nullptr;
    *this = otro;
}

Estante& Estante::operator=(const Estante& otro) {
    if (this == &otro) {
        return *this;
    }
    setCodigo(otro.codigo);
    anchura = otro.anchura;
    altura = otro.altura;
    pesoSoportado = otro.pesoSoportado;
    pesoActual = otro.pesoActual;

    delete[] espacios;
    espacios = nullptr;
    if (otro.espacios != nullptr and anchura > 0 and altura > 0) {
        espacios = new Espacio[totalCeldas()];
        for (int i = 0; i < totalCeldas(); i++) {
            espacios[i] = otro.espacios[i];
        }
    }
    return *this;
}

char* Estante::getCodigo() const {
    return codigo;
}

int Estante::getAnchura() const {
    return anchura;
}

int Estante::getAltura() const {
    return altura;
}

Espacio* Estante::getEspacios() const {
    return espacios;
}

double Estante::getPesoSoportado() const {
    return pesoSoportado;
}

double Estante::getPesoActual() const {
    return pesoActual;
}

void Estante::setCodigo(const char* nuevo) {
    delete[] codigo;
    if (nuevo == nullptr) {
        codigo = nullptr;
        return;
    }
    codigo = new char[strlen(nuevo) + 1];
    strcpy(codigo, nuevo);
}

void Estante::setAnchura(int anchura) {
    this->anchura = anchura;
}

void Estante::setAltura(int altura) {
    this->altura = altura;
}

void Estante::setPesoSoportado(double pesoSoportado) {
    this->pesoSoportado = pesoSoportado;
}

void Estante::setPesoActual(double pesoActual) {
    this->pesoActual = pesoActual;
}

void Estante::crearMatriz() {
    delete[] espacios;
    espacios = new Espacio[totalCeldas()];
    for (int i = 0; i < totalCeldas(); i++) {
        int x = i / anchura;
        int y = i % anchura;
        espacios[i].setPosx(x);
        espacios[i].setPosy(y);
        espacios[i].setContenido(' ');
    }
}

int Estante::obtenerEspaciosRestantes() const {
    int libres = 0;
    for (int i = 0; i < totalCeldas(); i++) {
        if (espacios[i].getContenido() == ' ') {
            libres++;
        }
    }
    return libres;
}

bool Estante::puedeInsertarRectangulo(int x0, int y0, int ancho, int alto) const {
    if (x0 + alto > altura || y0 + ancho > anchura) {
        return false;
    }
    for (int i = 0; i < ancho * alto; i++) {
        int dx = i / ancho;
        int dy = i % ancho;
        int idx = indiceDesdeXY(x0 + dx, y0 + dy);
        if (espacios[idx].getContenido() != ' ') {
            return false;
        }
    }
    return true;
}

bool Estante::encontrarPosicion(int ancho, int alto, int& px, int& py) const {
    for (int x = altura - alto; x >= 0; x--) {
        for (int y = 0; y <= anchura - ancho; y++) {
            if (puedeInsertarRectangulo(x, y, ancho, alto)) {
                px = x;
                py = y;
                return true;
            }
        }
    }
    return false;
}

void Estante::marcarRectangulo(int x0, int y0, int ancho, int alto, char marca) {
    for (int i = 0; i < ancho * alto; i++) {
        int dx = i / ancho;
        int dy = i % ancho;
        int idx = indiceDesdeXY(x0 + dx, y0 + dy);
        espacios[idx].setContenido(marca);
    }
}

void Estante::mostrarMatriz(ostream& os) const {
    for (int i = 0; i < totalCeldas(); i++) {
        if (espacios[i].getContenido() == '*') {
            os << "[ * ]";
        }
        else {
            os << "[   ]";
        }
        if ((i + 1) % anchura == 0) {
            os << endl;
        }
    }
}

Estante::~Estante() {
    delete[] codigo;
    delete[] espacios;
}
