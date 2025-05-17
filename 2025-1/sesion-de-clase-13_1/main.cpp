#include <cstdlib>

//#include "funciones.h"
#include "Restaurante.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Restaurante rosaNautica;
    rosaNautica.cargarMeseros("meseros.csv");
    rosaNautica.mostrarMeseros();
    
//    void* meseros;
//    cargarDatos("meseros.csv", meseros);
//    mostrarDatos(meseros);
//
//    //TODO: liberar memoria de los punteros interiores
//    delete[] (void**)meseros;
    
    return 0;
}

