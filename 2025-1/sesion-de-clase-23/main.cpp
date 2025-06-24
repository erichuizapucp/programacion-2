/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on June 23, 2025, 10:08 AM
 */

#include <cstdlib>

#include "AutoridadTransporte.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    AutoridadTransporte atu;
    
    atu.cargarDatos(
        "licencia.csv", 
        "conductor.csv", 
        "infraccion.csv", 
        "vehiculos.csv"
    );
    atu.cargarVehiculosPorConductor(
        "vehiculo_conductor.csv"
    );
    atu.reporteVehiculosPorConductor(
        "reporte-conductor-vehiculos.txt"
    );
    
    return 0;
}

