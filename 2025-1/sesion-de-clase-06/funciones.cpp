#include "estructuras.h"
#include "funciones.h"

void cargarProductos(const char* nombreArchivo, Producto*& productos) {
    Producto buffer[20];
    int numDatos = 0;
    
    ifstream archivo(nombreArchivo, ios::in);
    
    while (archivo >> buffer[numDatos]) {
        numDatos++;
    }
    
    productos = new Producto[numDatos];
    
    for (int i = 0; i < numDatos; i++) {
        productos[i] = buffer[i];
    }
    
    productos[numDatos].codigo = -1;
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

void cargarPedidos(const char* nombreArchivo, Pedido*& pedidos) {
    Pedido buffer[20];
    int numPedidos = 0;
    
    ifstream archivo(nombreArchivo, ios::in);
    
    while (archivo >> buffer[numPedidos]) { 
        numPedidos++;
    }
    
    pedidos = new Pedido[numPedidos];
    
    for (int i = 0; i < numPedidos; i++) {
        pedidos[i] = buffer[i];
    }
    
    pedidos[numPedidos].codigo = -1;
}

bool operator>>(ifstream& archivo, Pedido& pedido) {
    if (!archivo.eof() && archivo >> pedido.codigo) {
        archivo.ignore();
        archivo >> pedido.codigoCliente;
        archivo.ignore();
        pedido.cantProductos = 0;
        pedido.productos = nullptr;
        
        return true;
    }
    
    return false;
}

void cargarDetallePedido(const char* nombreArchivo, DetallePedido*& detallesPedido) {
    DetallePedido buffer[20];
    int numDetallesPedido = 0;
    
    ifstream archivo(nombreArchivo, ios::in);
    
    while (archivo >> buffer[numDetallesPedido]) { 
        numDetallesPedido++;
    }
    
    detallesPedido = new DetallePedido[numDetallesPedido + 1];
    
    for (int i = 0; i < numDetallesPedido; i++) {
        detallesPedido[i] = buffer[i];
    }
    
    detallesPedido[numDetallesPedido].codigoPedido = -1;
}

bool operator>>(ifstream& archivo, DetallePedido& detallePedido) {
    if (!archivo.eof() && archivo >> detallePedido.codigoPedido) {
        archivo.ignore();
        archivo >> detallePedido.codigoProducto;
        archivo.ignore();
        archivo >> detallePedido.cantidad;
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

void asignarPedidosClientes(Pedido*& pedidos, Cliente*& clientes) {
    for (int i = 0; pedidos[i].codigo != -1; i++) {
        Pedido pedido = pedidos[i];
        int codigoCliente = pedido.codigoCliente;
        
        Cliente* cliente = buscarClientePorCodigo(clientes, codigoCliente);
        if (cliente) {
            *cliente += pedido;
        }
    }
}

void asignarProductosPedidos(Pedido*& pedidos, Producto*& productos, DetallePedido*& detallePedidos) {
    for (int i = 0; detallePedidos[i].codigoPedido != -1; i++) {
        int codigoPedido = detallePedidos[i].codigoPedido;
        int codigoProducto = detallePedidos[i].codigoProducto;
        
        Pedido* pedido = buscarPedidoPorCodigo(pedidos, codigoPedido);
        Producto* producto = buscarProductoPorCodigo(productos, codigoProducto);
        
        if (pedido && producto) {
            *pedido += *producto;
        }
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

void incrementarProductos(Producto*& pedidoProductos, int numPedidoProductos, int& capacidad) {
    Producto* aux;
    capacidad += 3;
    
    if (!pedidoProductos) {
        pedidoProductos = new Producto[capacidad];
    }
    else {
        aux = new Producto[capacidad];
        for (int i = 0; i < numPedidoProductos; i++) {
            aux[i] = pedidoProductos[i];
        }
        delete pedidoProductos;
        pedidoProductos = aux;
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

Pedido* buscarPedidoPorCodigo(Pedido* pedidos, int codigoPedido) {
    for (int i = 0; pedidos[i].codigo != -1; i++) {
        if (pedidos[i].codigo == codigoPedido) {
            return &pedidos[i];
        }
    }
    
    return nullptr;
}

Producto* buscarProductoPorCodigo(Producto* productos, int codigoProducto) {
    for (int i = 0; productos[i].codigo != -1; i++) {
        if (productos[i].codigo == codigoProducto) {
            return &productos[i];
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

Pedido& operator+=(Pedido& pedido, Producto& producto) {
    int capacidad = pedido.cantProductos;
    
    if (pedido.cantProductos == capacidad) {
        incrementarProductos(pedido.productos, pedido.cantProductos, capacidad);
    }
    pedido.productos[pedido.cantProductos++] = producto;
    
    return pedido;
}

void imprimirPedidosPorCliente(Cliente*& clientes) {
    for (int i = 0; clientes[i].codigo != -1; i++) {
        cout << clientes[i];
    }
}

ostream& operator<<(ostream& os, Cliente& cliente) {
    os << "CLIENTE: " << cliente.codigo << endl;
    os << "NOMBRE: " << cliente.nombre << " " << cliente.apellido << endl;
    os << "PEDIDOS" << "(" << cliente.cantPedidos << ")"  << endl;
    os << "=======================================" << endl;
    
    for (int i = 0; i < cliente.cantPedidos; i++) {
        Pedido pedido = cliente.pedidos[i];
        os << pedido;
    }
    
    return os;
}

ostream& operator<<(ostream& os, Pedido& pedido) {
    os << "CODIGO DE PEDIDO: " << pedido.codigo << endl;

    os << left 
        << setw(10) << "CODIGO"
        << setw(20) << "NOMBRE"
        << setw(10) << "PRECIO" << endl;

    cout << pedido.cantProductos << endl;
    
    for (int j = 0; j < pedido.cantProductos; j++) {
        Producto producto = pedido.productos[j];
        os << producto;
    }
    os << "------------------------------------" << endl;
    
    return os;
}

ostream& operator<<(ostream& os, Producto& producto) {
    os << left 
        << setw(10) << producto.codigo
        << setw(20) << producto.nombre
        << setw(10) << fixed << setprecision(2) << producto.precio << endl;
    
    return os;
}