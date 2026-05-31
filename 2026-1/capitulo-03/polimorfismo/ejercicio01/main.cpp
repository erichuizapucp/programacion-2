#include <iostream>

#include "Alumno.h"
#include "AlumnoIntercambio.h"
#include "AlumnoRegular.h"
#include "Persona.h"
#include "Profesor.h"
#include "funciones.h"

using namespace std;

int main() {
    // Persona p(12345678, 25);
    // p.imprimir();
    //
    // cout << endl;
    //
    // Alumno a(12345678, 25, 20225678, 5);
    // a.imprimir();

    // Persona* persona = new Persona();
    // cout << *persona;
    // delete persona;

    cout << endl;

    // persona = new Alumno();
    // cout << *persona;
    // delete persona;
    //
    // cout << endl;
    Persona* persona = new Profesor();
    cout << *persona;
    delete persona;

    cout << endl;

    persona = new AlumnoRegular();
    cout << *persona;
    delete persona;

    cout << endl;

    persona = new AlumnoIntercambio();
    cout << *persona;
    delete persona;

    return 0;
}
