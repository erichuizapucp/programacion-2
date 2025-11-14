#include <cstdlib>

#include "AutoridadTransporte.h"

using namespace std;

/*
 * 
 */
int main() {
    AutoridadTransporte atu;
    
    atu.cargarDatos("licencia.csv", "conductor.csv", "infraccion.csv", "vehiculos.csv");
    atu.cargarVehiculosPorConductor("vehiculo_conductor.csv");
    atu.reporteVehiculosPorConductor("reporte-conductor-vehiculos.txt");
    
    return 0;
}

