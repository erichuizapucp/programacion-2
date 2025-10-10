#include <iostream>

#include "RedSocial.h"
#include "Usuario.h"
#include "UsuarioEstandard.h"

using namespace std;

int main() {
    RedSocial redSocial;
    redSocial.cargarUsuarios("usuarios.csv");
    redSocial.cargarPublicaciones("publicaciones.csv");
    redSocial.generarReporte("reporte.txt");

    return 0;
}