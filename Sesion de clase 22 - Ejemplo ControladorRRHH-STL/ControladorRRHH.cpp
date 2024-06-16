#include "ControladorRRHH.h"
#include "Estudiante.h"


ControladorRRHH::ControladorRRHH() {
    cout << "Constructor por defecto de ControladorRRHH" << endl;
    this->archivoSalida.open("Reporte.csv", ios::out);
}

ControladorRRHH::ControladorRRHH(
    const char* nombreArchivo, 
    const char* nombreArchivoEstudiantes) {
    cout << "Constructor sobrecargado de ControladorRRHH #1" << endl;
    
    this->archivoEstudiantes.open(nombreArchivoEstudiantes, ios::in);
    cargaDatos(this->estudiantes);
    
    this->archivoSalida.open(nombreArchivo, ios::out);
}

ControladorRRHH::ControladorRRHH(
    const char* nombreArchivo, 
    vector<Estudiante> &estudiantes
) : estudiantes(estudiantes) {
    cout << "Constructor sobrecargado de ControladorRRHH #2" << endl;
    this->archivoSalida.open(nombreArchivo, ios::out);
}

void ControladorRRHH::cargaDatos(vector<Estudiante> &estudiantes) {
    Estudiante estudiante;
//    int num = 0;
//    int capacidad = 0;
    
    while (!archivoEstudiantes.eof()) {
        estudiante.cargar(archivoEstudiantes);
        estudiantes.push_back(estudiante);
    }
    
    sort(estudiantes.begin(), estudiantes.end());
}

void ControladorRRHH::imprimir() {
    for (Estudiante e : estudiantes) {
        e.imprimir(cout);
    }
}

void ControladorRRHH::grabar() {
    for (Estudiante e : estudiantes) {
        e.grabar(archivoSalida);
    }
}

ControladorRRHH::~ControladorRRHH() {
    this->archivoEstudiantes.close();
    this->archivoSalida.close();
    
    cout << "Destructor de ControladorRRHH" << endl;
}

//bool operator>> (ifstream& archivo, Estudiante* &estudiante) {
//    if (!archivo.eof()) {
//        estudiante = new Estudiante();
//        estudiante->cargar(archivo);
//        
//        return true;
//    }
//    
//    return false;
//}
//
//ostream& operator<< (ostream& os, Estudiante* estudiante) {
//    estudiante->imprimir(os);
//    return os;
//}