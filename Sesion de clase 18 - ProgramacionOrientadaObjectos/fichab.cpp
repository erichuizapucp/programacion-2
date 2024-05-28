#include "fichab.h"

FichaB::FichaB(int codigo) : Ficha(codigo) {
}

void FichaB::mover(int fila, int columna) {
    this->setFila(fila);
    this->setColumna(columna);
    
    cout << "La ficha B: " << getCodigo() << ", se movió a las posiciones (" << getFila() << ", " << getColumna() << ")." << endl;
}

void FichaB::imprimir() {
    cout << "Ficha B: " << "Código: " << getCodigo() << ", posición (" << getFila() << ", " << getColumna() << ")." << endl;
}

FichaB::~FichaB() {
    cout << "Se destruye la Ficha B: " << getCodigo() << endl;
}