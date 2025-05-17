/* 
 * File:   Restaurante.cpp
 * Author: erichuiza
 * 
 * Created on May 2, 2025, 5:21 PM
 */

#include "Restaurante.h"

Restaurante::Restaurante() {
}

Restaurante::Restaurante(const Restaurante& orig) {
}

void Restaurante::cargarMeseros(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    
    this->meseros = nullptr;
    int cap = 0, num = 0;
    Mesero mesero;
    
    while (archivo >> mesero) {
        if (num == cap) {
            this->incrementar(num, cap);
        }
        
        this->meseros[num] = new Mesero();
        *this->meseros[num] = mesero;
        
        num++;
    }
    this->meseros[num] = nullptr;
}

bool operator>>(ifstream& archivo, Mesero& mesero) {
    int dni;
    if (!archivo.eof() && archivo >> dni) {
        double sueldo;
        int experiencia;
        archivo.ignore();
        char *nombre = leerCadena(archivo);
        archivo >> sueldo;
        archivo.ignore();
        archivo >> experiencia;
        archivo.ignore();
        
        Mesero temp(dni, nombre, sueldo, experiencia);
        mesero = temp;
        
        return true;
    }

    return false;
}

void Restaurante::incrementar(int& num, int& cap) {
    cap += 5;
    if (num == 0 && this->meseros == nullptr) {
        this->meseros = new Mesero*[cap + 1] {};
    }
    else {
        Mesero** aux = new Mesero*[cap + 1] {};

        for (int i = 0; i < num; i++) {
            aux[i] = new Mesero();
            *aux[i] = *this->meseros[i];
        }

        delete[] this->meseros;
        this->meseros = aux;
    }
}

ostream& operator<<(ostream& os, const Mesero& mesero) {
    os << left << setw(15) << mesero.getDni()
        << setw(50) << mesero.getNombre()
        << right << setw(15) << fixed 
            << setprecision(2) << mesero.getSueldo()
        << setw(15) << mesero.getExperiencia()
        << endl;

    return os;
}

void Restaurante::mostrarMeseros() {
    cout << left << setw(15) << "DNI"
        << setw(50) << "NOMBRE"
        << setw(15) << "SUELDO"
        << setw(15) << "EXPERIENCIA"
        << endl;

    for (int i = 0; this->meseros[i]; i++) {
        Mesero* mesero = this->meseros[i];
        cout << *mesero;
    }
}

char* leerCadena(ifstream& archivo, char delimitador) {
    char buffer[100];
    archivo.getline(buffer, 100, delimitador);

    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);

    return cadena;
}

Restaurante::~Restaurante() {
    for (int i = 0; this->meseros[i]; i++) {
        delete this->meseros[i];
    }
    
    delete[] this->meseros;
}
