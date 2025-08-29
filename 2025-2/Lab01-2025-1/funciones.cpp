//
// Created by Eric Huiza on 8/27/25.
//
#include "funciones.h"

void operator!(CadenaDeCaracteres& cad) {
    cad.cadena = nullptr;
    cad.longitud = 0;
    cad.capacidad = 0;
}

void operator<=(CadenaDeCaracteres& cad, int cantidad) {
    !cad;
    cad.cadena = new char[cantidad];
}

void operator<=(CadenaDeCaracteres& cad, const char* cadena) {
    cad <= strlen(cadena) + 1;
    strcpy(cad.cadena, cadena);
}

void operator<=(CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2) {
    cad1 <= cad2.cadena;
}

bool operator+=(CadenaDeCaracteres& cad, const char* cadena) {
    if (!cad.cadena) {
        return false;
    }
    strcat(cad.cadena, cadena);
    return true;
}

bool operator+=(CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2) {
    return cad1 += cad2.cadena;
}

bool operator==(CadenaDeCaracteres& cad, const char* cadena) {
    return strcmp(cad.cadena, cadena) == 0;
}

bool operator==(CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2) {
    return cad1 == cad2.cadena;
}

bool operator<(CadenaDeCaracteres& cad, const char* cadena) {
    return strcmp(cad.cadena, cadena) < 0;
}

bool operator<(CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2) {
    return cad1 < cad2.cadena;
}

bool operator>(CadenaDeCaracteres& cad, const char* cadena) {
    return strcmp(cad.cadena, cadena) > 0;
}

bool operator>(CadenaDeCaracteres& cad1, const CadenaDeCaracteres& cad2) {
    return cad1 > cad2.cadena;
}

bool operator>>(ifstream& archivo, CadenaDeCaracteres& cad) {
    archivo.getline(cad.cadena, cad.capacidad);
    return true;
}

void operator&&(CadenaDeCaracteres& cad1, CadenaDeCaracteres& cad2) {
    CadenaDeCaracteres temp {};
    temp <= cad1;

    cad2 <= cad1;
    cad1 <= temp;
}

ostream& operator<<(ostream& os, const CadenaDeCaracteres& cad) {
    os << cad.cadena << endl;
    return os;
}