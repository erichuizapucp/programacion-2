#include <iostream>

#include "Alumno.h"
#include "AlumnoIntercambio.h"
#include "AlumnoRegular.h"

using namespace std;

int main() {
    Alumno* a = new AlumnoIntercambio(
        2022785634,
        "Jonh Smith",
        22.5,
        "EEUU",
        6
    );
    cout << *a;

    delete a;

    return 0;
}