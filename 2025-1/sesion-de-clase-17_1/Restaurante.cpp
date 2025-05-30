/* 
 * File:   Restaurante.cpp
 * Author: erichuiza
 * 
 * Created on May 2, 2025, 5:21 PM
 */

#include "Restaurante.h"
#include "Cliente.h"

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
            this->incrementarMeseros(num, cap);
        }
        
        this->meseros[num] = new Mesero();
        *this->meseros[num] = mesero;
        
        num++;
    }
    this->meseros[num] = nullptr;
}

void Restaurante::cargarClientes(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    
    this->clientes = nullptr;
    int cap = 0, num = 0;
    Cliente cliente;
    
    while (archivo >> cliente) {
        if (num == cap) {
            this->incrementarClientes(num, cap);
        }
        
        this->clientes[num] = new Cliente();
        *this->clientes[num] = cliente;
        
        num++;
    }
    this->meseros[num] = nullptr;
}

void Restaurante::incrementarMeseros(int& num, int& cap) {
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

void Restaurante::incrementarClientes(int& num, int& cap) {
    cap += 5;
    if (num == 0 && this->clientes == nullptr) {
        this->clientes = new Cliente*[cap + 1] {};
    }
    else {
        Cliente** aux = new Cliente*[cap + 1] {};

        for (int i = 0; i < num; i++) {
            aux[i] = new Cliente();
            *aux[i] = *this->clientes[i];
        }

        delete[] this->clientes;
        this->clientes = aux;
    }
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

void Restaurante::mostrarClientes() {
    cout << left << setw(15) << "DNI"
        << setw(50) << "NOMBRE"
        << setw(20) << "TELEFONO"
        << setw(20) << "CORREO"
        << endl;

    for (int i = 0; this->clientes[i]; i++) {
        Cliente* cliente = this->clientes[i];
        cout << *cliente;
    }
}

Restaurante::~Restaurante() {
    for (int i = 0; this->meseros[i]; i++) {
        delete this->meseros[i];
    }
    
    delete[] this->meseros;
    
    for (int i = 0; this->clientes[i]; i++) {
        delete this->clientes[i];
    }
    
    delete[] this->clientes;
}
