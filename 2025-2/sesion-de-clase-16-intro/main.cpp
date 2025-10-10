#include <iostream>

#include "Alumno.h"
#include "AlumnoUniversitario.h"

using namespace std;

int main() {
    AlumnoUniversitario a("Juan", "12345678", 202045678, "FCI", 5);
    AlumnoUniversitario b = a;

    b.imprimir();

    return 0;
}