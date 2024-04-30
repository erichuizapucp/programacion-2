#include "ControladorRRHH.h"
#include "Estudiante.h"


ControladorRRHH::ControladorRRHH() {
    cout << "Constructor por defecto de ControladorRRHH" << endl;
    
    this->personas = new Persona*[] { };
    this->archivoSalida.open("Reporte.csv", ios::out);
}

ControladorRRHH::ControladorRRHH(
    const char* nombreArchivo, 
    const char* nombreArchivoEstudiantes) {
    cout << "Constructor sobrecargado de ControladorRRHH #1" << endl;
    
    this->personas = nullptr;
    
    this->archivoEstudiantes.open(nombreArchivoEstudiantes, ios::in);
    cargaEstudiantes(this->personas);
    
    this->archivoSalida.open(nombreArchivo, ios::out);
}

ControladorRRHH::ControladorRRHH(
    const char* nombreArchivo, 
    Persona** &personas
) : personas(personas) {
    cout << "Constructor sobrecargado de ControladorRRHH #2" << endl;
    this->archivoSalida.open(nombreArchivo, ios::out);
}

void ControladorRRHH::cargaEstudiantes(Persona** &personas) {
    Estudiante* estudiante;
    int num = 0;
    int capacidad = 0;
    
    while (!this->archivoEstudiantes.eof()) {
        estudiante = new Estudiante();
        estudiante->cargar(this->archivoEstudiantes);
        
        if (num == capacidad) {
            incrementMemorySpaces(personas, num, capacidad);
        }
        
        personas[num] = estudiante;
        num++;
    }
}

void ControladorRRHH::imprimir() {
    for (int i = 0; personas[i] != nullptr; i++) {
        personas[i]->imprimir();
        cout << endl;
    }
}

void ControladorRRHH::grabar() {
    for (int i = 0; personas[i] != nullptr; i++) {
        personas[i]->grabar(this->archivoSalida);
    }
}

ControladorRRHH::~ControladorRRHH() {
    for (int i = 0; personas[i] != nullptr; i++) {
        delete personas[i];
    }
    
    delete[] personas;
    this->archivoEstudiantes.close();
    this->archivoSalida.close();
    
    cout << "Destructor de ControladorRRHH" << endl;
}