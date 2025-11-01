#include <iostream>

#include "MatriculaAlumno.h"
#include "Persona.h"

using namespace std;

int main() {

    Persona persona("Juan Perez", 12345678);
    cout << persona;

    cout << endl;
    MatriculaAlumno ma(persona);
    cout << ma;

    return 0;
}