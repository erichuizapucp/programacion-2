#include <iostream>

#include "RedSocial.h"
#include "Usuario.h"

using namespace std;

int main() {
    RedSocial redSocial;
    redSocial.cargarUsuarios("usuarios.csv");
    redSocial.generarReporteUsuarios("reporteUsuarios.txt");

    // Usuario david;
    // david.setEdad(20);
    // david.setCuenta("@dperez");
    // david.setNombre("David Perez");
    // david.setFacultad("FCI");
    // david.setFechaRegistro(20230922);
    // david.setCorreo("david.perez@pucp.edu.pe");
    //
    // cout << david;

    return 0;
}