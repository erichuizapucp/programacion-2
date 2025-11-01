#include <iostream>

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

    return 0;
}