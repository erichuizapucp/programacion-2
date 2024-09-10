#include "funciones.h"

void cargarMesasExactas(const char* nombreArchivo, int**& mesas) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarMesasExactas(archivo, mesas);
}

void cargarMesasExactas(ifstream& archivo, int**& mesas) {
    int numMesas = 0;
    
    int buffer[BUFFER_CAP][2];
    
    int codigo;
    int capacidad;
    while (!archivo.eof() && archivo >> codigo) {
        archivo.ignore();
        archivo >> capacidad;
        archivo.ignore();
        
        buffer[numMesas][MESAS_POS::CODIGO] = codigo;
        buffer[numMesas][MESAS_POS::CAPACIDAD] = capacidad;
        
        numMesas++;
    }
    
    mesas = new int*[2];
    int* codigos = mesas[MESAS_POS::CODIGO] = new int[numMesas + 1];
    int* capacidades = mesas[MESAS_POS::CAPACIDAD] = new int[numMesas + 1];
    
    for (int i = 0; i < numMesas; i++) {
        codigos[i] = buffer[i][MESAS_POS::CODIGO];
        capacidades[i] = buffer[i][MESAS_POS::CAPACIDAD];
    }
    
    codigos[numMesas] = -1;
    capacidades[numMesas] = -1;
}

void cargarReservasIncremento(const char* nombreArchivo, int**& reservas, char**& nombres) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarReservasIncremento(archivo, reservas, nombres);
}

void cargarReservasIncremento(ifstream& archivo, int**& reservas, char**& nombres) {
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
        asignarValores(dnis, noPersonasPtr, nombres, numReservas, -1, -1, nullptr);
        asignarValores(dnis, noPersonasPtr, nombres, numReservas - 1, dni, noPersonas, nombre);
        
        numReservas++;
    }
    reservas = new int*[2];
    reservas[RESERVAS_POS::DNI] = dnis;
    reservas[RESERVAS_POS::NO_PERSONAS] = noPersonasPtr;
}

void cargarPropinasExactas(const char* nombreArchivo, double***& propinas) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarPropinasExactas(archivo, propinas);
}

void cargarPropinasExactas(ifstream& archivo, double***& propinas) {
    int numMesero, numDia = 0;
    int numDias[BUFFER_CAP] { 0 }, numPropinas[BUFFER_CAP][BUFFER_CAP] { 0 };
    double buffer[BUFFER_CAP][BUFFER_CAP][BUFFER_CAP], propina;    
    char c;
    
    while (!archivo.eof() && archivo >> propina) {
        if (propina > 0.00) { // cuando se dejó propina
            int numPropina = numPropinas[numMesero][numDia]++;
            buffer[numMesero][numDia][numPropina] = propina;
        }
        
        c = archivo.get(); // Leer el siguiente carácter        
        if (c == ',') {
            // Si es una coma, pasa al siguiente conjunto de propinas (día)
            numDia = ++numDias[numMesero];
        }
        else if (c == '\n') { 
            // Si es un salto de línea, cambia al siguiente mesero
            numDia = 0;
            numMesero++;
        }
    }
    
    propinas = new double**[numMesero + 1];
    for (int i = 0; i < numMesero; i++) {
        int noDias = numDias[i];
        asignarPropinasMesero(buffer[i], noDias, numPropinas[i], propinas[i]);
    }
    propinas[numMesero] = nullptr;
}

void asignarPropinasMesero(const double buffPropMesero[][BUFFER_CAP], const int numDias, const int* numPropinas, double**& propinasMesero) {
    propinasMesero = new double*[numDias + 1];
    
    for (int i = 0; i < numDias; i++) {
        asignarPropinasDiarias(buffPropMesero[i], numPropinas[i], propinasMesero[i]);
    }
    
    propinasMesero[numDias] = nullptr;
}

void asignarPropinasDiarias(const double buffPropDiarias[BUFFER_CAP], const int num, double*& propDiarias) {
    propDiarias = new double[num + 1];
    
    for (int i = 0; i < num; i++) {
        propDiarias[i] = buffPropDiarias[i];
    }
    
    propDiarias[num] = -1.00;
}

void mostrarPropinas(const char* nombreArchivo, const double*** propinas) {
    ofstream archivo(nombreArchivo, ios::out);
    mostrarPropinas(archivo, propinas);
}

void mostrarPropinas(ofstream& archivo, const double*** propinas) {
    for (int i = 0; propinas[i]; i++) {
        const double** propinasMesero = propinas[i];
        archivo << "Mesero: " << i + 1 << endl;
        archivo << propinasMesero << endl;
    }
}

ofstream& operator<<(ofstream& archivo, const double** propinasMesero) {
    for (int i = 0; propinasMesero[i]; i++) {
        const double* propinasDiarias = propinasMesero[i];
        archivo << "Día: " << i + 1 << endl; 
        archivo << propinasDiarias << endl;
    }
    
    return archivo;
}

ofstream& operator<<(ofstream& archivo, const double* propinasDiarias) {
    for (int i = 0; propinasDiarias[i] != -1.00; i++) {
        double propina = propinasDiarias[i];
        archivo << setw(6) << fixed << setprecision(2) << propina;
    }
    
    return archivo;
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