/*
 * File:   AutoridadTransporte.cpp
 * Author: erichuiza
 *
 * Created on June 23, 2025, 11:22 AM
 */

#include "AutoridadTransporte.h"

void AutoridadTransporte::cargarDatos(const string nombArchLicencia, const string nombArchConductores, const string nombArchInfraccion, const string nombArchVehiculos) {
    this->cargar(nombArchLicencia, licencias);
    this->cargar(nombArchConductores, conductores);
    this->cargar(nombArchInfraccion, infracciones);
    this->cargar(nombArchVehiculos, vehiculos);
}

void AutoridadTransporte::cargarLicencias(const string nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);

    Licencia licencia;
    while (archivo >> licencia) {
        licencias.push_back(licencia);
    }
}

void AutoridadTransporte::cargarConductores(const string nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);

    Conductor conductor;
    while (archivo >> conductor) {
        conductores.push_back(conductor);
    }
}

void AutoridadTransporte::cargarInfracciones(const string nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);

    Infraccion infraccion;
    while (archivo >> infraccion) {
        infracciones.push_back(infraccion);
    }
}

void AutoridadTransporte::cargarVechiculos(const string nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::in);

    Vehiculo vehiculo;
    while (archivo >> vehiculo) {
        vehiculos.push_back(vehiculo);
    }
}

void AutoridadTransporte::cargarVehiculosPorConductor(
    const string nombreArchivo
) {
    ifstream archivo(nombreArchivo, ios::in);

    int codigoVehiculo, codigoConductor;
    while (!archivo.eof() && archivo >> codigoVehiculo) {
        archivo.ignore();
        archivo >> codigoConductor;
        archivo.ignore();

        Vehiculo* vehiculoPtr =
                this->buscarPorCodigo(vehiculos, codigoVehiculo);
        Conductor* conductorPtr =
                this->buscarPorCodigo(conductores, codigoConductor);

        if (vehiculoPtr == nullptr || conductorPtr == nullptr) {
            cout
                    << "Vehiculo o Conductor no encontrado. "
                    << ", Cod. Vehiculo: " << codigoVehiculo
                    << ", Cod. Conductor" << codigoConductor
                    << endl;

            continue;
        }

        Vehiculo vehiculo = *vehiculoPtr;
        Conductor conductor = *conductorPtr;

        mapConductorVehiculo[conductor].push_back(vehiculo);
    }
}

void AutoridadTransporte::reporteVehiculosPorConductor(
    const string nombreArchivo
) {
    ofstream archivo(nombreArchivo, ios::out);

    // map<Conductor, vector<vehiculos>::iterator
    auto it = mapConductorVehiculo.begin();
    while (it != mapConductorVehiculo.end()) {
        Conductor conductor = it->first;
        vector<Vehiculo> vehiculos = it->second;

        archivo << conductor << endl;
        archivo << endl << "** Lista de vehiculos del conductor **" << endl << endl;

        auto itv = vehiculos.begin();
        while (itv != vehiculos.end()) {
            archivo << *itv << endl;
            ++itv;
        }
        ++it;
    }
}