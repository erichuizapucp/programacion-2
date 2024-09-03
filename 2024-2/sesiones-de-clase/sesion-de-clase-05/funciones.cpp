#include "funciones.h"

void cargarNumeros(const char* nombreArchivo, int*& numeros, int& numDatos) {
    int buffer[1000];
    numDatos = 0;
    
    ifstream archivo(nombreArchivo, ios::in);
    
    while (!archivo.eof()) {
        archivo >> buffer[numDatos];
        numDatos++;
    }
    
    numeros = new int[numDatos];
    
    for (int i = 0; i < numDatos; i++) {
        numeros[i] = buffer[i];
    }
}

void cargarNumeros(const char* nombreArchivo, int*& numeros) {
    int buffer[1000];
    int numDatos = 0;
    
    ifstream archivo(nombreArchivo, ios::in);
    
    while (!archivo.eof()) {
        archivo >> buffer[numDatos];
        numDatos++;
    }
    
    numeros = new int[numDatos + 1];
    
    for (int i = 0; i < numDatos; i++) {
        numeros[i] = buffer[i];
    }
    
    numeros[numDatos] = -1;
}

char* leerCadena(ifstream& archivo, char delimitador) {
    char buffer[1000];
    archivo.getline(buffer, 1000, delimitador);
    
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    
    return cadena;
}

void cargarEmpleados(const char* nombreArchivo, Empleado*& empleados, int& numDatos) {
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

void cargarEmpleados(const char* nombreArchivo, Empleado*& empleados) {
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

bool operator>>(ifstream& archivo, Empleado& empleado) {
    if (!archivo.eof() && archivo >> empleado.dni) {
        archivo.ignore(); // ignorar la coma
        empleado.nombre = leerCadena(archivo);
        archivo >> empleado.sueldoBruto;
        archivo.ignore(); // ignorar la coma
        archivo >> empleado.experiencia;
        archivo.ignore(); // ignorar el salto de línea
        
        return true;
    }
    
    return false;
}

ostream& operator<<(ostream& os, const Empleado* empleado) {
    os << left << setw(10) << empleado->dni
            << setw(50) << empleado->nombre
            << right << fixed << setprecision(2) << setw(10) << empleado->sueldoBruto
            << setw(5) << empleado->experiencia
            << endl;
    
    return os;
}