#include "includes/funciones.h"

using namespace std;

int main() {
    void *usuarios, *publicaciones, *likes, *solicitudes;
    cargarDatos("usuarios.csv", usuarios,
        leerUsuario, ordenarUsuarioPorFecha);
    cargarDatos("publicaciones.csv", publicaciones,
        leerPublicacion, ordenarPublicacionPorFecha);
    cargarDatos("likes.csv", likes, leerLike, ordenarLikePorFechaHora);
    cargarDatos("solicitudes.csv", solicitudes,
        leerSolicitud, ordenarSolicitudPorFecha);

    procesarDatos(usuarios, publicaciones, likes, solicitudes);
    imprimirReporte("reporte.txt", usuarios);

    return 0;
}