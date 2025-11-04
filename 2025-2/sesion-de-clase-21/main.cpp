#include <iostream>

#include "Pila.h"
#include "Restaurante.h"

using namespace std;

int main() {
    Restaurante restaurante;

    restaurante.cargarMeseros("meseros.csv");
    restaurante.reporteMeseros("reporteMeseros.txt");

    restaurante.cargarClientes("clientes.csv");
    restaurante.reporteClientes("reporteClientes.txt");

    restaurante.cargarPedidos("pedidos.csv");
    restaurante.reportePedidos("pedidos.txt");

    // Pila<int> pila;
    // pila.apilar(new int(4));
    // pila.apilar(new int(5));
    // pila.apilar(new int (6));
    //
    // pila.imprimir(cout);

    return 0;
}