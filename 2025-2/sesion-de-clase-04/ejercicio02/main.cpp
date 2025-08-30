#include <iostream>

#include "estructuras.h"
#include "funciones.h"

using namespace std;

int main() {
    Usuario* usuarios;
    cargarUsuarios("usuarios.csv", usuarios);
    imprimirUsuarios("usuarios.txt", usuarios);

    return 0;
}