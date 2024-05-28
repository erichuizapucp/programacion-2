#include "ficha.h"

Ficha::Ficha(int codigo) {
    this->codigo = codigo;
    fila = 0;
    columna = 0;
}

int Ficha::getCodigo() {
    return codigo;
}

int Ficha::getFila() {
    return fila;
}

int Ficha::getColumna() {
    return columna;
}

void Ficha::setFila(int fila) {
    this->fila = fila;
}

void Ficha::setColumna(int columna) {
    this->columna = columna;
}

Ficha::~Ficha() {
}