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
    construirColasDeAtencion(clinica);

    imprimirReporte("reporte-clinica.txt", clinica);
    imprimirReporteAtencionDoctores("reporte-atencion-doctores.txt", clinica);

    liberarClinica(clinica);

    return 0;
}
