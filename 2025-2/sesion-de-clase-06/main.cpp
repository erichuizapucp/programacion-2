#include "funciones.h"

using namespace std;

int main() {
    char*** usuarios;
    int** fechasEdades;
    cargarUsuarios("usuarios.csv", usuarios, fechasEdades);

    int** idsFechas;
    char*** publicaciones;
    char*** menciones;
    cargarPublicaciones("publicaciones.csv", idsFechas,
        publicaciones, menciones);

    imprimirReporte("reporte.txt",
                    (const char***)usuarios,
                    (const int**)fechasEdades,
                    (const int**)idsFechas,
                    (const char***)publicaciones,
                    (const char***)menciones);

    return 0;
}