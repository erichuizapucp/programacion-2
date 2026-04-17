#include "funciones.h"
#include <fstream>

using namespace std;

int main() {
    void* clinica;

    cargarDatos(clinica,
            "pacientes.csv",
            "doctores.csv",
            "citas.csv",
            "cancelaciones.csv");

    cancelarCitas(clinica);

    ofstream reporte("reporte-clinica.txt", ios::out);
    imprimirReporte(reporte, clinica);

    liberarClinica(clinica);

    return 0;
}
