#include "archivos.h"

void abrirArchivo(const char* nombre, ifstream& archivo) {
    archivo.open(nombre, ios::in);
    
    if (!archivo.is_open()) {
        cerr << "El archivo " << nombre << ", no pudo ser abierto.";
        exit(1);
    }
}

void abrirArchivo(const char* nombre, ofstream& archivo) {
    archivo.open(nombre, ios::out);
    
    if (!archivo.is_open()) {
        cerr << "El archivo " << nombre << ", no pudo ser abierto.";
        exit(1);
    }
}