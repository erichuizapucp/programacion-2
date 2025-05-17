/* 
 * File:   Restaurante.cpp
 * Author: erichuiza
 * 
 * Created on May 2, 2025, 5:21 PM
 */

#include "Restaurante.h"

Restaurante::Restaurante() {
//    cout << "El restaurante se instancia." << endl;
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
        
        this->meseros[num].setDni(mesero.getDni());
        this->meseros[num].setNombre(mesero.getNombre());
        this->meseros[num].setSueldo(mesero.getSueldo());
        this->meseros[num].setExperiencia(mesero.getExperiencia());
        num++;
    }
    this->meseros[num].setDni(-1);
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

//        Mesero* m1 = new Mesero(dni, nombre, sueldo, experiencia);
        
        mesero.setDni(dni);
        mesero.setNombre(nombre);
        mesero.setSueldo(sueldo);
        mesero.setExperiencia(experiencia);        
//        delete[] nombre;
        
        return true;
    }

    return false;
}

void Restaurante::incrementar(int& num, int& cap) {
    cap += 5;
    if (num == 0 && this->meseros == nullptr) {
        this->meseros = new Mesero[cap + 1] {};
    }
    else {
        Mesero* aux = new Mesero[cap + 1] {};

        for (int i = 0; i < num; i++) {
            aux[i].setDni(this->meseros[i].getDni());
            aux[i].setNombre(this->meseros[i].getNombre());
            aux[i].setSueldo(this->meseros[i].getSueldo());
            aux[i].setExperiencia(this->meseros[i].getExperiencia());            
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

    for (int i = 0; this->meseros[i].getDni() != -1; i++) {
        Mesero mesero = this->meseros[i];
        cout << mesero;
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
    for (int i = 0; this->meseros[i].getDni() != -1; i++) {
        delete this->meseros[i];
    }
//    cout << "El restaurante se destruye." << endl;
}

