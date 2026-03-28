#include <iostream>

#include "MisBibliotecas/estructuras.h"
#include "MisBibliotecas/funciones.h"

using namespace std;

int main() {
    Clinica clinica {
        new Paciente[100],
        new Doctor[20],
        new Cita[200],
        0,
        0,
        0
    };
    cargarPacientes(clinica);
    cargarDoctores(clinica);
    cargarCitas(clinica);

    !clinica.citas[0];

    cout << clinica << endl;

    delete[] clinica.pacientes;
    delete[] clinica.doctores;
    delete[] clinica.citas;

    return 0;
}
