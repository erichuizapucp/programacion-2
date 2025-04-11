#include "estructuras.h"
#include "funciones.h"

void cargarProductos(const char* nombreArchivo, Producto*& productos, int& numDatos) {
    Producto buffer[20];
    numDatos = 0;
    
    ifstream archivo(nombreArchivo, ios::in);
    
    while (archivo >> buffer[numDatos]) {
        numDatos++;
    }
    
    productos = new Producto[numDatos];
    
    for (int i = 0; i < numDatos; i++) {
        productos[i] = buffer[i];
    }
}

bool operator>>(ifstream& archivo, Producto& producto) {
    if (!archivo.eof() && archivo >> producto.codigo) {
        archivo.ignore();
        producto.nombre = leerCadena(archivo);
        archivo >> producto.precio;
        archivo.ignore(); // ignorar el salto de línea
        
        return true;
    }
    
    return false;
}

void cargarClientes(const char* nombreArchivo, Cliente*& clientes, int& numDatos) {
    Cliente buffer[20];
    numDatos = 0;
    
    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> buffer[numDatos]) {
        numDatos++;
    }
    
    clientes = new Cliente[numDatos];
    
    for (int i = 0; i < numDatos; i++) {
        clientes[i] = buffer[i];
    }
}

void cargarClientes(const char* nombreArchivo, Cliente*& clientes) {
    Cliente buffer[20];
    int numDatos = 0;
    
    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> buffer[numDatos]) {
        numDatos++;
    }
    
    clientes = new Cliente[numDatos + 1];
    
    for (int i = 0; i < numDatos; i++) {
        clientes[i] = buffer[i];
    }
    
    clientes[numDatos].codigo = -1; // equivalente al final cadena
}

bool operator>>(ifstream& archivo, Cliente& cliente) {
    if (!archivo.eof() && archivo >> cliente.codigo) {
        archivo.ignore();
        cliente.nombre = leerCadena(archivo);
        cliente.apellido = leerCadena(archivo, '\n');
        cliente.cantPedidos = 0;
        cliente.pedidos = nullptr;
        
        return true;
    }
    
    return false;
}

void cargarPedidos(const char* nombreArchivo, Pedido*& pedidos, int& numPedidos) {
    Pedido buffer[20];
    numPedidos = 0;
    
    ifstream archivo(nombreArchivo, ios::in);
    
    while (archivo >> buffer[numPedidos]) { 
        numPedidos++;
    }
    
    pedidos = new Pedido[numPedidos];
    
    for (int i = 0; i < numPedidos; i++) {
        pedidos[i] = buffer[i];
    }
}

bool operator>>(ifstream& archivo, Pedido& pedido) {
    if (!archivo.eof() && archivo >> pedido.codigo) {
        archivo.ignore();
        archivo >> pedido.codigoCliente;
        archivo.ignore();
        
        return true;
    }
    
    return false;
}

char* leerCadena(ifstream& archivo, char delim) {
    char buffer[50];
    archivo.getline(buffer, 50, delim);
    
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    
    return cadena;
}

void asignarPedidosClientes(Pedido*& pedidos, int numPedidos, Cliente*& clientes) {
    for (int i = 0; i < numPedidos; i++) {
        Pedido pedido = pedidos[i];
        int codigoCliente = pedido.codigoCliente;
        
        Cliente* cliente = buscarClientePorCodigo(clientes, codigoCliente);
        if (cliente) *cliente += pedido;
    }
}

void incrementarPedidos(Pedido*& clientePedidos, int numClientePedidos, int& capacidad) {
    Pedido* aux;
    capacidad += 3;
    
    if (!clientePedidos) {
        clientePedidos = new Pedido[capacidad];
    }
    else {
        aux = new Pedido[capacidad];
        for (int i = 0; i < numClientePedidos; i++) {
            aux[i] = clientePedidos[i];
        }
        delete clientePedidos;
        clientePedidos = aux;
    }
}

Cliente* buscarClientePorCodigo(Cliente* clientes, int codigoCliente) {
    for (int i = 0; clientes[i].codigo != -1; i++) {
        if (clientes[i].codigo == codigoCliente) {
            return &clientes[i];
        }
    }
    
    return nullptr;
}

Cliente& operator+=(Cliente& cliente, Pedido& pedido) {
    int capacidad = cliente.cantPedidos;
            
    if (cliente.cantPedidos == capacidad) {
        incrementarPedidos(cliente.pedidos, cliente.cantPedidos, capacidad);
    }

    cliente.pedidos[cliente.cantPedidos++] = pedido;
    
    return cliente;
}

ostream& operator<<(ostream& os, Cliente& cliente) {
    os << "CLIENTE: " << cliente.codigo << endl;
    os << "NOMBRE: " << cliente.nombre << " " << cliente.apellido << endl;
    os << "PEDIDOS" << "(" << cliente.cantPedidos << ")"  << endl;
    os << "=======================================" << endl;
    
    for (int i = 0; i < cliente.cantPedidos; i++) {
        Pedido pedido = cliente.pedidos[i];
        os << "CODIGO DE PEDIDO: " << pedido.codigo << endl;
        
//        os << left 
//            << setw(10) << "CODIGO"
//            << setw(20) << "NOMBRE"
//            << setw(10) << "PRECIO" << endl;
//        
//        for (int j = 0; j < pedido.cantProductos; j++) {
//            Producto producto = pedido.productos[j];
//            
//            os << left 
//                << setw(10) << producto.codigo
//                << setw(20) << producto.nombre
//                << setw(10) << fixed << setprecision(2) << producto.precio << endl;
//        }
        os << "------------------------------------" << endl;
    }
    
    
    return os;
}