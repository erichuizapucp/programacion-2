#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "BibliotecaMemoriaExacta.h"

using namespace std;

int main(int argc, char** argv) {    
    int *datos, numDat;
    
    leeDatosExactos(datos, numDat);
    
    imprimeDatos(datos, numDat);
    
    delete[] datos;
    
    return 0;
}

