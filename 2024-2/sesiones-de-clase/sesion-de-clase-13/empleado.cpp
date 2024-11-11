#include "empleado.h"

void Empleado::cargar(
    const char* nombreArchivo, 
    Empleado*& empleados, 
    int& numDatos
) {
    Empleado buffer[1000];
    
    ifstream archivo(nombreArchivo, ios::in);
    numDatos = 0;
    while (archivo >> buffer[numDatos]) {
        numDatos++;
    }
    
    empleados = new Empleado[numDatos];
    
    for (int i = 0; i < numDatos; i++) {
        empleados[i] = buffer[i];
    }
}

void Empleado::cargar(
    const char* nombreArchivo, 
    Empleado*& empleados) {
    
    Empleado buffer[1000];
    
    ifstream archivo(nombreArchivo, ios::in);
    int numDatos = 0;
    while (archivo >> buffer[numDatos]) {
        numDatos++;
    }
    
    empleados = new Empleado[numDatos + 1];
    
    for (int i = 0; i < numDatos; i++) {
        empleados[i] = buffer[i];
    }
    
    empleados[numDatos].dni = -1;
}

int Empleado::getDni() {
    return this->dni;
}

char* Empleado::getNombre() {
    return this->nombre;
}

double Empleado::getSueldoBruto() {
    return this->sueldoBruto;
}

int Empleado::getExperiencia() {
    return this->experiencia;
}

void Empleado::setDni(int dni) {
    this->dni = dni;
}

void Empleado::setNombre(char* nombre) {
    this->nombre = nombre;
}

void Empleado::setSueldoBruto(double sueldoBruto) {
    this->sueldoBruto = sueldoBruto;
}

void Empleado::setExperiencia(int experiencia) {
    this->experiencia = experiencia;
}

bool operator>>(ifstream& archivo, Empleado& empleado) {
    int dni;
    double sueldoBruto;
    int experiencia;
    if (!archivo.eof() && archivo >> dni) {
        empleado.setDni(dni);
        
        archivo.ignore(); // ignorar la coma
        empleado.setNombre(leerCadena(archivo));
        archivo >> sueldoBruto
        empleado.setSueldoBruto(sueldoBruto);
        archivo.ignore(); // ignorar la coma
        archivo >> experiencia;
        empleado.setExperiencia(experiencia);
        archivo.ignore(); // ignorar el salto de línea
        
        return true;
    }
    
    return false;
}

ostream& operator<<(ostream& os, const Empleado* empleado) {
    os << left << setw(10) << empleado->getDni()
            << setw(50) << empleado->getNombre()
            << right << fixed << setprecision(2) << setw(10) << empleado->getSueldoBruto()
            << setw(5) << empleado->getExperiencia()
            << endl;
    
    return os;
}

char* leerCadena(ifstream& archivo, char delimitador) {
    char buffer[1000];
    archivo.getline(buffer, 1000, delimitador);
    
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    
    return cadena;
}