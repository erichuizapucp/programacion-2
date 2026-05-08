#include <iostream>

#include "Alumno.h"

using namespace std;

int main() {
    Alumno* a = new Alumno(12345, 678910);
    Alumno b = *a;

    a -> imprimir();
    delete a;

    return 0;
}
