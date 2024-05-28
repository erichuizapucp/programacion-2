#include "fichac.h"

FichaC::FichaC(int codigo) : Ficha(codigo) {
}

void FichaC::mover(int fila, int columna) {
    this->setFila(fila);
    this->setColumna(columna);
    
    cout << "La ficha C: " << getCodigo() << ", se movió a las posiciones (" << getFila() << ", " << getColumna() << ")." << endl;
}

void FichaC::imprimir() {
    cout << "Ficha C: " << "Código: " << getCodigo() << ", posición (" << getFila() << ", " << getColumna() << ")." << endl;
}

FichaC::~FichaC() {
    cout << "Se destruye la Ficha C: " << getCodigo() << endl;
}