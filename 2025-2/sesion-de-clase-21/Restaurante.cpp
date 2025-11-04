#include "Restaurante.h"
#include "Cliente.h"
#include "PedidoRegular.h"
#include "PedidoPrioritario.h"

Restaurante::Restaurante() {
    this->meseros = nullptr;
    this->clientes = nullptr;
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

void Restaurante::cargarPedidos(const char* nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);
    
    int prioridad;
    while (!archivo.eof() && archivo >> prioridad) {
        archivo.ignore();
        
        Pedido *pedido;
        switch (prioridad) {
            case 0:
                pedido = new PedidoRegular();
                break;
            case 1:
                pedido = new PedidoPrioritario();
                break;
            default:
                pedido = new PedidoRegular();
                break;
        }
        
        if (archivo >> *pedido) {
            this->colaPedidos.encolar(pedido);
        }
    }
}

void Restaurante::reportePedidos(const char* nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::out);
    
    archivo 
        << left << setw(10) << "PRIORITARIO"
        << left << setw(15) << "CODIGO"
        << setw(15) << "DNI"
        << setw(50) << "PLATO"
        << endl;
    
    this->colaPedidos.imprimir(archivo);
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

void Restaurante::reporteMeseros(const char* nombreArchivo) const {
    ofstream os(nombreArchivo, ios::out);
    
    os 
        << left << setw(15) << "DNI"
        << setw(50) << "NOMBRE"
        << setw(15) << "SUELDO"
        << setw(15) << "EXPERIENCIA"
        << endl;

    for (int i = 0; this->meseros[i]; i++) {
        Mesero* mesero = this->meseros[i];
        os << *mesero;
    }
}

void Restaurante::reporteClientes(const char* nombreArchivo) const {
    ofstream os(nombreArchivo, ios::out);
    
    os 
        << left << setw(15) << "DNI"
        << setw(50) << "NOMBRE"
        << setw(20) << "TELEFONO"
        << setw(20) << "CORREO"
        << endl;

    for (int i = 0; this->clientes[i]; i++) {
        const Cliente* cliente = this->clientes[i];
        os << *cliente;
    }
}

Restaurante::~Restaurante() {
    if (this->meseros) {
        for (int i = 0; this->meseros[i]; i++) {
            delete this->meseros[i];
        }

        delete[] this->meseros;
    }

    if (this->clientes) {
        for (int i = 0; this->clientes[i]; i++) {
            delete this->clientes[i];
        }

        delete[] this->clientes;
    }
}
