#include "funciones.h"

using namespace std;

int main() {
    void *usuarios, *publicaciones;
    cargarDatos("usuarios.csv", usuarios, leerUsuario, ordenarUsuarioPorFecha);
    cargarDatos("publicaciones.csv", publicaciones, leerPublicacion, ordenarPublicacionPorFecha);

    procesarPublicaciones(usuarios, publicaciones);
    imprimirReporte("reporte.txt", usuarios);

    return 0;
}
