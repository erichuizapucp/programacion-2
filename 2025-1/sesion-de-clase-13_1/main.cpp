#include <cstdlib>

#include "Restaurante.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Restaurante rosaNautica;
    rosaNautica.cargarMeseros("meseros.csv");
    rosaNautica.mostrarMeseros();
    
    Mesero mesero1(12345678, "Juan", 2000.00, 10);
    Mesero mesero2(87654321, "Pedro", 2500.00, 12);
    
    if (mesero2 > mesero1) {
        cout << "El mesero 2 tiene un mayor sueldo que el mesero 1" << endl;
    }
    
    if (mesero1 < mesero2) {
        cout << "El mesero 1 tiene un menor sueldo que el mesero 2" << endl;
    }
    
    return 0;
}

