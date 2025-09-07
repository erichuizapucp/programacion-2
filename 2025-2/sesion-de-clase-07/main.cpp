#include "funciones.h"

using namespace std;

int main() {
    void *usuarios, *publicaciones;
    cargarUsuarios("usuarios.csv", usuarios);
    cargarPublicaciones("publicaciones.csv", publicaciones);

    procesarPublicaciones(usuarios, publicaciones);
    imprimirReporte("reporte.txt", usuarios);

    return 0;
}
