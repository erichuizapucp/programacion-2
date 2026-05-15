#include <iostream>

#include "Alumno.h"

using namespace std;

int main() {
    Alumno alumno;

    alumno.setDni(12345678);
    alumno.setNombre("Juan Perez");
    alumno.setEdad(20);
    alumno.setCodigo(20210001);
    alumno.setFacultad("Ingeniería de Sistemas");

    cout << alumno << endl;

    return 0;
}
