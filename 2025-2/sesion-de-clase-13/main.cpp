#include <iostream>

#include "RedSocial.h"
#include "Usuario.h"

using namespace std;

int main() {
    // Usuario u1("@jperez",
    //            "Juan Perez",
    //            "jperez@gmail.com",
    //            "FCI",
    //            20200318,
    //            20);
    // u1.setCuenta("@jperez");
    // u1.setCorreo("jperez@gmail.com");
    // u1.setNombre("Juan Perez");
    // u1.setFacultad("FCI");
    // u1.setFechaRegistro(20200318);
    // u1.setEdad(20);
    // Usuario u2 = u1;
    // cout << u2;

    RedSocial redSocial;
    redSocial.cargarUsuarios("usuarios.csv");
    redSocial.generarReporteUsuarios("reporteUsuarios.txt");

    // RedSocial* p = new RedSocial();
    // delete p;
    //
    // cout << "Otro mensaje" << endl;

    return 0;
}