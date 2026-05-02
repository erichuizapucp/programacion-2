#include <iostream>

#include "Alumno.h"

using namespace std;

int main() {
    Alumno* a = new Alumno();
    a->imprimir();
    delete a;

    return 0;
}
