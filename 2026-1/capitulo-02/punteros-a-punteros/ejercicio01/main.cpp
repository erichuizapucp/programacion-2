#include "funciones.h"
#include <fstream>

using namespace std;

int main() {
    int** pacientes;
    char** nombresPacientes;
    int** doctores;
    char** nombresDoctores;
    int*** citas;

    cargarPacientes("pacientes.csv", pacientes, nombresPacientes);
    cargarDoctores("doctores.csv", doctores, nombresDoctores);
    cargarCitas("citas.csv", citas);

    int*** cancelaciones;
    cargarCancelaciones("cancelaciones.csv", cancelaciones);
    cancelarCitas(cancelaciones, citas);

    ofstream reporte("reporte-clinica.txt", ios::out);
    imprimirReporte(reporte, citas, pacientes, nombresPacientes, doctores, nombresDoctores);

    liberarPacientes(pacientes, nombresPacientes);
    liberarDoctores(doctores, nombresDoctores);
    liberarCancelaciones(cancelaciones);
    liberarCitas(citas);

    return 0;
}
