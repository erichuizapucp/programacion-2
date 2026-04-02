#include <iostream>

#include "estructuras.h"
#include "funciones.h"

using namespace std;

int main() {
    Clinica clinica;
    cargarPacientes("pacientes.csv",
        clinica.pacientes);

    for (int i = 0; clinica.pacientes[i].dni != -1; i++) {
        cout << clinica.pacientes[i] << endl;
    }

    delete[] clinica.pacientes;

    // cargarDoctores(clinica);
    // cargarCitas(clinica);
    //
    // !clinica.citas[0];
    //
    // cout << clinica << endl;
    //
    // delete[] clinica.pacientes;
    // delete[] clinica.doctores;
    // delete[] clinica.citas;

    return 0;
}
