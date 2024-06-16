#include <cstdlib>

#include "Arbol.h"

using namespace std;

int main(int argc, char** argv) {
    Arbol arbol;
    
    arbol.crear("personalLL.csv");
    arbol.mostrarEnOrden();
    Persona p;
    p = arbol.buscar(250612);
    
    if (p.GetDni() != -1) {
        cout << "Dato buscado: " << p << endl;
    }
    else {
        cout << "No se encontró" << endl;
    }
    
    return 0;
}

