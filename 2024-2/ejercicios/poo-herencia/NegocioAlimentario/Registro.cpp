/* 
 * File:   Registro.cpp
 * Author: erichuiza
 * 
 * Created on November 3, 2024, 2:03 PM
 */

#include "Registro.h"

void Registro::copiarCadena(char*& destino, const char* fuente) {
    if (destino != nullptr) {
        delete[] destino;
    }
    destino = new char[strlen(fuente) + 1];
    strcpy(destino, fuente);
}

char* Registro::leeCadena(ifstream& archivo, char delimitador) {
    char buffer[tam::buffer];
    archivo.getline(buffer, tam::buffer, delimitador);
    char* cadena = new char[strlen(buffer) + 1];
    
    strcpy(cadena, buffer);
    
    return cadena;
}

bool operator>>(ifstream& archivo, Registro& registro) {
    return registro.crear(archivo);
}
