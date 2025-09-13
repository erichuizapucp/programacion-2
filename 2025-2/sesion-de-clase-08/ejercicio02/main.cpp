#include "funciones.h"

using namespace std;

int main() {
    void *usuarios, *publicaciones;
    cargarDatos("usuarios.csv", usuarios,
                leerUsuario, cmpUsuariosPorNombre);
    cargarDatos("publicaciones.csv", publicaciones,
                leerPublicacion, cmpPubsPorFecha);

    procesarPublicaciones(usuarios, publicaciones);
    imprimirReporte("reporte.txt", usuarios);

    return 0;
}
