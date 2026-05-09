#include <fstream>

#include "Clinica.h"

using namespace std;

int main() {
    Clinica clinica;
    clinica.cargarPacientes("pacientes.csv");
    clinica.cargarDoctores("doctores.csv");
    clinica.cargarCitas("citas.csv");
    clinica.procesarCitas();
    clinica.cancelarCita(0);
    clinica.generarReporte("reporte-clinica.txt");

    return 0;
}
