#include "funciones.h"

//void cargarNumeros(const char* nombreArchivo, int*& numeros, int& numDatos) {
//    int cap = 0;
//    numDatos = 0;
//    numeros = nullptr;
//    
//    ifstream archivo(nombreArchivo, ios::in);
//    
//    int dato;
//    while (archivo >> dato) {
//        if (numDatos == cap) {
//            incrementarEspacios(numeros, numDatos, cap);
//        }
//        
//        numeros[numDatos] = dato;
//        numDatos++;
//    }
//}
//
//void cargarNumeros(const char* nombreArchivo, int*& numeros) {
//    int numDatos = 0;
//    
//    cargarNumeros(nombreArchivo, numeros, numDatos);
//    numeros[numDatos] = -1;
//}



char* leerCadena(ifstream& archivo, char delimitador) {
    char buffer[1000];
    archivo.getline(buffer, 1000, delimitador);
    
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    
    return cadena;
}

//void cargarEmpleados(const char* nombreArchivo, Empleado*& empleados, int& numDatos) {
//    int cap = 0;
//    numDatos = 0;
//    empleados = nullptr;
//    Empleado dato;
//    
//    ifstream archivo(nombreArchivo, ios::in);
//    while (archivo >> dato) {
//        if (cap == numDatos) {
//            incrementarEspacios(empleados, numDatos, cap);
//        }
//        empleados[numDatos] = dato;
//        numDatos++;
//    }
//}
//
//void cargarEmpleados(const char* nombreArchivo, Empleado*& empleados) {
//    int numDatos = 0;
//    
//    cargarEmpleados(nombreArchivo, empleados, numDatos);
//    empleados[numDatos].dni = -1;
//}

//void incrementarEspacios(int*& datos, int& numDatos, int& cap) {
//    cap += INCREMENTO;
//    
//    if (datos == nullptr) {
//        datos = new int[cap];
//    }
//    else {
//        int* aux = new int[cap];
//        for (int i = 0; i < numDatos; i++) {
//            aux[i] = datos[i];
//        }
//        delete[] datos;
//        datos = aux;
//    }
//}
//
//void incrementarEspacios(Empleado*& datos, int& numDatos, int& cap) {
//    cap += INCREMENTO;
//    
//    if (datos == nullptr) {
//        datos = new Empleado[cap];
//    }
//    else {
//        Empleado* aux = new Empleado[cap];
//        for (int i = 0; i < numDatos; i++) {
//            aux[i] = datos[i];
//        }
//        delete[] datos;
//        datos = aux;
//    }
//}

void asignarValorDeCorte(int& numero) {
    numero = -1;
}

void asignarValorDeCorte(Empleado& empleado) {
    empleado.dni = -1;
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

bool operator<=(const Empleado& e1, const Empleado& e2) {
    return strcmp(e1.nombre, e2.nombre) <= 0;
}

bool operator>=(const Empleado& e1, const Empleado& e2) {
    return strcmp(e1.nombre, e2.nombre) >= 0;
}