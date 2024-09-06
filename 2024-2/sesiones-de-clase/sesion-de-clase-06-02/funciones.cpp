#include "funciones.h"

void cargarMesas(const char* nombreArchivo, int**& mesas) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarMesas(archivo, mesas);
}

void cargarMesas(ifstream& archivo, int**& mesas) {
    int numMesas = 0;
    int bufferCodigos[1000];
    int bufferCapacidades[1000];
    
    mesas = new int*[2];
    
    int codigo;
    int capacidad;
    while (!archivo.eof() && archivo >> codigo) {
        archivo.ignore();
        archivo >> capacidad;
        archivo.ignore();
        
        bufferCodigos[numMesas] = codigo;
        bufferCapacidades[numMesas] = capacidad;
        
        numMesas++;
    }
    
    mesas[0] = new int[numMesas + 1];
    mesas[1] = new int[numMesas + 1];
    
    for (int i = 0; i < numMesas; i++) {
        mesas[0][i] = bufferCodigos[i];
        mesas[1][i] = bufferCapacidades[i];
    }
    
    mesas[0][numMesas] = -1;
    mesas[1][numMesas] = -1;
}

void cargarReservas(const char* nombreArchivo, int**& reservas, char**& nombres) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarReservas(archivo, reservas, nombres);
}

void cargarReservas(ifstream& archivo, int**& reservas, char**& nombres) {
    int numReservas = 0;
    int capReservas = 0;
    
    reservas = new int*[2];
    
    int dni;
    int noPersonas;
    char* nombre;
    while (!archivo.eof() && archivo >> dni) {
        archivo.ignore();
        nombre = leerCadena(archivo);
        archivo >> noPersonas;
        archivo.ignore();
        
        if (numReservas == capReservas) {
            capReservas += INCREMENTO;
            incrementar(reservas[0], reservas[1], numReservas, capReservas);
            incrementar(nombres, numReservas, capReservas);
        }
        
        reservas[0][numReservas] = dni;
        reservas[1][numReservas] = noPersonas;
        nombres[numReservas] = nombre;
        
        numReservas++;
    }
    
    reservas[0][numReservas] = -1;
    reservas[1][numReservas] = -1;
    nombres[numReservas] = nullptr;
}

void incrementar(int*& datos1, int*& datos2, int numDatos, int cap) {
    if (numDatos == 0) {
        datos1 = new int[cap];
        datos2 = new int[cap];
    }
    else {
        int* aux1 = new int[cap];
        int* aux2 = new int[cap];
        
        for (int i = 0; i < numDatos; i++) {
            aux1[i] = datos1[i];
            aux2[i] = datos2[i];
        }
        
        delete[] datos1;
        delete[] datos2;
        
        datos1 = aux1;
        datos2 = aux2;
    }
}

void incrementar(char**& datos, int numDatos, int cap) {
    if (numDatos == 0) {
        datos = new char*[cap];
    }
    else {
        char** aux = new char*[cap];
        
        for (int i = 0; i < numDatos; i++) {
            aux[i] = new char[strlen(datos[i]) + 1];
            strcpy(aux[i], datos[i]);
            delete[] datos[i];
        }
        
        delete[] datos;
        datos = aux;
    }
}

char* leerCadena(ifstream& archivo, char delimitador) {
    char buffer[1000];
    archivo.getline(buffer, 1000, delimitador);
    
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    
    return cadena;
}