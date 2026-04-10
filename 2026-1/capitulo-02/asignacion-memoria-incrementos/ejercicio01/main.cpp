#include "estructuras.h"
#include "funciones.h"
#include <fstream>

using namespace std;

int main() {
    Clinica clinica;
    cargarPacientes("pacientes.csv",clinica.pacientes);
    cargarDoctores("doctores.csv",clinica.doctores);
    cargarCitas("citas.csv",clinica.citas);

    procesarCitas(clinica);

    !clinica.citas[0];

    ofstream reporte("reporte-clinica.txt", ios::out);
    reporte << clinica << endl;

    delete[] clinica.pacientes;
    delete[] clinica.doctores;
    delete[] clinica.citas;

    return 0;
}
