#include "estructuras.h"
#include "funciones.h"

Cliente& operator+=(Cliente& cliente, Pedido& pedido) {
    cliente.pedidos[cliente.cantPedidos] = pedido;
    cliente.cantPedidos++;
    return cliente;
}

Pedido& operator+=(Pedido& pedido, Producto& producto) {
    pedido.productos[pedido.cantProductos] = producto;
    pedido.cantProductos++;
    return pedido;
}

ostream& operator<<(ostream& os, Cliente& cliente) {
    os << "CLIENTE: " << cliente.codigo << endl;
    os << "NOMBRE: " << cliente.nombre << " " << cliente.apellido << endl;
    os << "PEDIDOS" << "(" << cliente.cantPedidos << ")"  << endl;
    os << "=======================================" << endl;
    
    for (int i = 0; i < cliente.cantPedidos; i++) {
        Pedido pedido = cliente.pedidos[i];
        os << "CODIGO DE PEDIDO: " << pedido.codigo << endl;
        
        os << left 
            << setw(10) << "CODIGO"
            << setw(20) << "NOMBRE"
            << setw(10) << "PRECIO" << endl;
        
        for (int j = 0; j < pedido.cantProductos; j++) {
            Producto producto = pedido.productos[j];
            
            os << left 
                << setw(10) << producto.codigo
                << setw(20) << producto.nombre
                << setw(10) << fixed << setprecision(2) << producto.precio << endl;
        }
        os << "------------------------------------" << endl;
    }
    
    
    return os;
}