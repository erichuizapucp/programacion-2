#include "funciones.h"

Cliente& operator+=(Cliente& cliente, Pedido& pedido) {
    cliente.pedidos[cliente.cantPedidos++] = pedido;
    return cliente;
}

Pedido& operator+=(Pedido& pedido, Producto& producto) {
    pedido.productos[pedido.cantProductos++] = producto;
    return pedido;
}

ostream& operator<<(ostream& os, Cliente& cliente) {
    os << "CLIENTE (Código: " << cliente.codigo << ")" << endl;
    os << "NOMBRE: " << cliente.nombre << endl;
    os << "PEDIDOS (" << cliente.cantPedidos << ")" << endl;
    os << "=======================================" << endl;
    for (int i = 0; i < cliente.cantPedidos; i++) {
        Pedido pedido = cliente.pedidos[i];
        
        os << "CODIGO DE PEDIDO: " << pedido.codigo << endl;
        os << "-----------------------------------" << endl;
        
        os << left 
           << setw(15) << "Código" 
           << setw(30) <<"Nombre" 
           << setw(10) << "Precio" << endl;
        
        for (int j = 0; j < pedido.cantProductos; j++) {
            Producto producto = pedido.productos[j];
            
            os << left
               << setw(15) << producto.codigo
               << setw(30) << producto.nombre
               << setw(10) << right << fixed << setprecision(2) 
                    << producto.precio << endl;
        }
    }
    
    return os;
}
