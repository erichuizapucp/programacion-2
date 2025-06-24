/* 
 * File:   AutoridadTransporte.h
 * Author: erichuiza
 *
 * Created on June 23, 2025, 11:22 AM
 */

#ifndef AUTORIDADTRANSPORTE_H
#define AUTORIDADTRANSPORTE_H

#include <map>
#include "Conductor.h"
#include "Vehiculo.h"
#include "Infraccion.h"


class AutoridadTransporte {
private:
    vector<Licencia> licencias;
    vector<Conductor> conductores;
    vector<Infraccion> infracciones;
    vector<Vehiculo> vehiculos;
    
    map<Conductor, vector<Vehiculo>> mapConductorVehiculo;
    map<Conductor, vector<Infraccion>> mapConductorInfraccion;
    map<Vehiculo, vector<Infraccion>> mapVehiculoInfraccion;
    
    void cargarLicencias(const string);
    void cargarConductores(const string);
    void cargarInfracciones(const string);
    void cargarVechiculos(const string);
    
    template<typename T>
    T* buscarPorCodigo(vector<T>&, int);
    
    template<typename T>
    void cargar(const string, vector<T>&);
public:
    AutoridadTransporte() = default;
    
    void cargarDatos(
        const string, 
        const string, 
        const string, 
        const string
    );
    void cargarVehiculosPorConductor(
        const string nombreArchivo
    );
    void reporteVehiculosPorConductor(
        const string nombreArchivo
    );
//    void cargarInfraccionesPorConductor();
//    void cargarInfraccionesPorVehiculo();
    
    virtual ~AutoridadTransporte() = default;
};

template<typename T>
T* AutoridadTransporte::buscarPorCodigo(vector<T>& v, int codigo) {
    auto it = find_if(v.begin(), v.end(), [codigo](T& item) {
        return item.getCodigo() == codigo;
    });

    if (it != v.end()) {
        return &(*it);
    }

    return nullptr;
}

template<typename T>
void AutoridadTransporte::cargar(
    const string nombreArchivo, 
    vector<T>& v
) {
    ifstream archivo(nombreArchivo, ios::in);
    
    T registro;
    while (archivo >> registro) {
        v.push_back(registro);
    }
}

#endif /* AUTORIDADTRANSPORTE_H */

