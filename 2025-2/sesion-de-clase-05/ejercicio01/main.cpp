#include <iostream>
#include "funciones.h"

using namespace std;

int main() {
    Usuario* usuarios;
    Publicacion* publicaciones;

    cargarUsuarios("usuarios.csv", usuarios);
    cargarPublicaciones("publicaciones_usuario.csv", publicaciones);

    // TODO: cargar publicaciones por incrementos
    // TODO: imprimir usuarios y sus publicaciones

    return 0;
}