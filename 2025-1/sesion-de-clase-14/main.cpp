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
        
    return 0;
}

