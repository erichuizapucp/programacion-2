#include "funciones.h"

void cargarMesas(const char* nombreArchivo, int**& mesas) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarMesas(archivo, mesas);
}

void cargarMesas(ifstream& archivo, int**& mesas) {
    int numMesas = 0;
    
    int buffer[2][BUFFER_CAP];
    int* bufferCodigos = *buffer;
    int* bufferCapacidades = *(buffer + 1);
    
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
    
    mesas = new int*[2];
    int* codigos = mesas[MESAS_POS::CODIGO] = new int[numMesas + 1];
    int* capacidades = mesas[MESAS_POS::CAPACIDAD] = new int[numMesas + 1];
    
//    mesas[0] = new int[numMesas + 1];
//    mesas[1] = new int[numMesas + 1];
    
    for (int i = 0; i < numMesas; i++) {
//        mesas[0][i] = bufferCodigos[i];
//        mesas[1][i] = bufferCapacidades[i];
        codigos[i] = bufferCodigos[i];
        capacidades[i] = bufferCapacidades[i];
    }
    
    codigos[numMesas] = -1;
    capacidades[numMesas] = -1;
}

void cargarReservas(const char* nombreArchivo, int**& reservas, char**& nombres) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarReservas(archivo, reservas, nombres);
}

void cargarReservas(ifstream& archivo, int**& reservas, char**& nombres) {
    int numReservas = 0;
    int cap = 0;
    
    int dni;
    int noPersonas;
    char* nombre;
    int* dnis = nullptr;
    int* noPersonasPtr = nullptr;
    
    while (!archivo.eof() && archivo >> dni) {
        archivo.ignore();
        nombre = leerCadena(archivo);
        archivo >> noPersonas;
        archivo.ignore();
        
        if (numReservas == cap) {
            cap += INCREMENTO;
            incrementar(dnis, numReservas, cap);
            incrementar(noPersonasPtr, numReservas, cap);
            incrementar(nombres, numReservas, cap);
            
            if (numReservas == 0) {
                numReservas++;
            }
        }
        
//        reservas[0][numReservas] = dni;
//        reservas[1][numReservas] = noPersonas;
        
        asignarValores(dnis, noPersonasPtr, nombres, numReservas, -1, -1, nullptr);
        asignarValores(dnis, noPersonasPtr, nombres, numReservas - 1, dni, noPersonas, nombre);
        
//        dnis[numReservas] = -1;
//        capacidades[numReservas] = -1;
//        nombres[numReservas] = nullptr;
//        
//        dnis[numReservas - 1] = dni;
//        capacidades[numReservas - 1] = noPersonas;
//        nombres[numReservas - 1] = nombre;
        
        numReservas++;
    }
    reservas = new int*[2];
    reservas[RESERVAS_POS::DNI] = dnis;
    reservas[RESERVAS_POS::NO_PERSONAS] = noPersonasPtr;
}

void asignarValores(int*& dnis, int*& capacidades, char**& nombres, int numDatos, int dni, int capacidad, char* nombre) {
    dnis[numDatos] = dni;
    capacidades[numDatos] = capacidad;
    nombres[numDatos] = nombre;
}

void incrementar(int*& datos, int numDatos, int cap, bool corte) {
    if (numDatos == 0 || datos == nullptr) {
        datos = new int[cap];
        if (corte) {
            datos[numDatos] = -1;
        }
    }
    else {
        int* aux = new int[cap];
        
        for (int i = 0; i < numDatos; i++) {
            aux[i] = datos[i];
        }
        
        delete[] datos;
        
        datos = aux;
    }
}

void incrementar(char**& datos, int numDatos, int cap, bool corte) {
    if (numDatos == 0) {
        datos = new char*[cap];
        if (corte) {
            datos[numDatos] = nullptr;
        }
    }
    else {
        char** aux = new char*[cap];
        
        for (int i = 0; i < numDatos && datos[i]; i++) {
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

void mostrarMesas(const char* nombreArchivo, const int** mesas) {
    ofstream archivo(nombreArchivo, ios::out);
    
    if (!archivo.is_open()) {
        cerr << "El archivo " << nombreArchivo << ", no se pudo abrir" << endl;
    }
    
    mostrarMesas(archivo, mesas);
}

void mostrarMesas(ofstream& archivo, const int** mesas) {
    const int* codigos = mesas[MESAS_POS::CODIGO];
    const int* capacidades = mesas[MESAS_POS::CAPACIDAD];
    
    archivo << left << setw(10) << "CODIGO" << setw(10) << "CAPACIDAD" << endl;
    
    for (int i = 0; codigos[i] != -1; i++) {
        archivo << left << setw(10) << codigos[i] << setw(10) << capacidades[i] << endl;
    }
    
    archivo.close();
}

void mostrarReservas(const char* nombreArchivo, const int** reservas, const char** nombres) {
    ofstream archivo(nombreArchivo, ios::out);
    
    if (!archivo.is_open()) {
        cerr << "El archivo " << nombreArchivo << ", no se pudo abrir" << endl;
    }
    
    mostrarReservas(archivo, reservas, nombres);
}

void mostrarReservas(ofstream& archivo, const int** reservas, const char** nombres) {
    const int* dnis = reservas[RESERVAS_POS::DNI];
    const int* noPersonas = reservas[RESERVAS_POS::NO_PERSONAS];
    
    archivo << left << setw(8) << "DNI" << setw(40) << "NOMBRE" << setw(8) << "NO" << endl;
    
    for (int i = 0; dnis[i] != -1; i++) {
        archivo << left << setw(8) << dnis[i] << setw(40) << nombres[i] << setw(8) << noPersonas[i] << endl;
    }
}