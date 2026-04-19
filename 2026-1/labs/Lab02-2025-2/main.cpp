#include "funciones.h"

using namespace std;

int main() {
    char*** categorias;
    cargarCategorias("categorias.csv",
                     categorias);

    char*** streamers;
    int** fechasPromedios;
    long long** tiempoRepSegidores;
    cargarStreamers("streamers.csv",
                 streamers,
                 fechasPromedios,
                 tiempoRepSegidores);

    char*** comentarios;
    char*** etiquetas;
    cargarComentarios("comentarios.csv",
                    comentarios,
                    etiquetas);

    imprimirReporte("reporte.txt",
                    (const char***)categorias,
                    (const char***)streamers,
                    (const int**)fechasPromedios,
                    (const long long**)tiempoRepSegidores,
                    (const char***)comentarios,
                    (const char***)etiquetas);

    return 0;
}