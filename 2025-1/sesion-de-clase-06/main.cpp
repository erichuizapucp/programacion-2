/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on April 7, 2025, 3:29 PM
 */

#include <cstdlib>
#include "estructuras.h"
#include "funciones.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Producto* productos;
    cargarProductos("productos.csv", productos);
    
    Cliente* clientes;
    cargarClientes("clientes.csv", clientes);
    
    Pedido* pedidos;
    cargarPedidos("pedidos.csv", pedidos);
    
    DetallePedido* detallesPedido;
    cargarDetallePedido("detalle-pedido.csv", detallesPedido);
    
    asignarProductosPedidos(pedidos, productos, detallesPedido);
    asignarPedidosClientes(pedidos, clientes);
    
    imprimirPedidosPorCliente(clientes);
    
    return 0;
}

