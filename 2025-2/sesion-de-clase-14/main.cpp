#include <iostream>

#include "RedSocial.h"
#include "Usuario.h"

int main() {
    // Usuario u1("@jperez",
    //            "Juan Perez",
    //            "jperez@gmail.com",
    //            "FCI",
    //            20200318,
    //            20);
    // Usuario u2 = u1;
    // if (u1 == u2) {
    //     cout << "Son iguales" << endl;
    // }
    // u2.setEdad(40);
    //
    // if (u2 > u1) {
    //     cout << "U2 es mayor que U1" << endl;
    // }


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

    Usuario u5 = redSocial[4];
    // cout << u5 << endl;

    int edad = u5;
    char* nombre = u5;

    cout << "Edad: " << edad << endl;
    cout << "Nombre: " << nombre << endl;

    redSocial.generarReporteUsuarios("reporteUsuarios.txt");

    // RedSocial* p = new RedSocial();
    // delete p;
    //
    // cout << "Otro mensaje" << endl;

    return 0;
}

using namespace std;