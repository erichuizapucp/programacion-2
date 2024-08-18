#include "fichaa.h"

FichaA::FichaA(int codigo) : Ficha(codigo) {
}

void FichaA::mover(int fila, int columna) {
    this->setFila(fila);
    this->setColumna(columna);
    
    cout << "La ficha A: " << getCodigo() << ", se movió a las posiciones (" << getFila() << ", " << getColumna() << ")." << endl;
}

void FichaA::imprimir() {
    cout << "Ficha A: " << "Código: " << getCodigo() << ", posición (" << getFila() << ", " << getColumna() << ")." << endl;
}

FichaA::~FichaA() {
    cout << "Se destruye la Ficha A: " << getCodigo() << endl;
}