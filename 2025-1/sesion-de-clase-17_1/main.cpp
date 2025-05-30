#include <cstdlib>

#include "Restaurante.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Restaurante restaurante;
    
    restaurante.cargarMeseros("meseros.csv");
    restaurante.mostrarMeseros();
    
    cout << endl;
    
    restaurante.cargarClientes("clientes.csv");
    restaurante.mostrarClientes();
    
    return 0;
}

