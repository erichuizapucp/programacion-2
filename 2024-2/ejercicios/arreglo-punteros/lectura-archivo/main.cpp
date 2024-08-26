/* 
 * File:   main.cpp
 * Author: erichuiza
 *
 * Created on August 22, 2024, 10:59 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

#include "estructuras.h"
#include "funciones.h"

/*
 * 
 */
int main(int argc, char** argv) {
    // Clientes
    ifstream archivoClientes("clientes.csv");
    if (!archivoClientes.is_open()) {
        cerr << "El archivo clientes.csv no se pudo abrir" << endl;
        exit(1);
    } 
    
    Cliente* clientes;
    archivoClientes >> clientes;
    archivoClientes.close();
    
    calcularTotales(clientes);
    
    ofstream reporteClientes("clientes.txt");
    reporteClientes << clientes;
    reporteClientes.close();
    
    delete[] clientes;
    
    // Empleados
    ifstream archivoEmpleados("empleados.csv");
    if (!archivoEmpleados.is_open()) {
        cerr << "El archivo empleados.csv no se pudo abrir" << endl;
    }
    
    Empleado* empleados;
    archivoEmpleados >> empleados;
    archivoEmpleados.close();
    
    calcularTotales(empleados);
    
    ofstream reporteEmpleados("empleados.txt");
    reporteEmpleados << empleados;
    reporteEmpleados.close();
    
    delete[] empleados;
    
    return 0;
}
