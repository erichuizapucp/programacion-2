#include <iostream>
#include <iomanip>
#include <cstring>

#include "funciones.h"
#include "enums.h"

void cargarMesasExactas(const char* nombreArchivo, int**& mesas) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarMesasExactas(archivo, mesas);
}

void cargarMesasExactas(ifstream& archivo, int**& mesas) {
    int numMesas = 0;
    
    int buffer[BUFFER_CAP][2];
    
    int codigo;
    int capacidad;
    while (archivo >> codigo) {
        if (archivo.eof()) {
            break;
        }

        archivo.ignore();
        archivo >> capacidad;
        archivo.ignore();
        
        buffer[numMesas][CODIGO] = codigo;
        buffer[numMesas][CAPACIDAD] = capacidad;
        
        numMesas++;
    }
    
    mesas = new int*[2];
    int* codigos = mesas[CODIGO] = new int[numMesas + 1];
    int* capacidades = mesas[CAPACIDAD] = new int[numMesas + 1];
    
    for (int i = 0; i < numMesas; i++) {
        codigos[i] = buffer[i][CODIGO];
        capacidades[i] = buffer[i][CAPACIDAD];
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
    int* dnis = nullptr;
    int* noPersonasPtr = nullptr;
    
    while (archivo >> dni) {
        if (archivo.eof()) {
            break;
        }

        archivo.ignore();
        char *nombre = leerCadena(archivo);
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
    reservas[DNI] = dnis;
    reservas[NO_PERSONAS] = noPersonasPtr;
}

void cargarPropinasIncremento(const char *nombreArchivo, double***& propinas) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarPropinasIncremento(archivo, propinas);
}

void cargarPropinasIncremento(ifstream& archivo, double***& propinas) {
    int numMesero = 0, capMeseros = 0, numDia = 0;
    int numPropinasMesero[MAX_MESEROS] {}, 
        capPropinasMesero[MAX_MESEROS] {};
    int numPropinasDia[MAX_MESEROS * NUM_DIAS] {}, 
        capPropinasDia[MAX_MESEROS * NUM_DIAS] {};

    propinas = nullptr;
    double* propinasPorDia = nullptr;
    double** propinasPorMesero = nullptr;

    double propina;
    while (archivo >> propina) {
        if (archivo.eof()) break;
        if (propina > 0.00) {
            incrementarPropinasPorDia(propinasPorDia, numMesero, numDia, propina, numPropinasDia, capPropinasDia);
        }

        const char c = archivo.get();
        if (c == ',') {
            numDia++;
            incrementarPropinasPorMesero(propinasPorMesero, propinasPorDia, numMesero, numDia, numPropinasMesero, capPropinasMesero);
        }
        else if (c == '\n') {
            // Si es un salto de línea, cambia al siguiente mesero
            if (numMesero == capMeseros) {
                incrementar(propinas, numMesero, capMeseros);
            }
            propinas[numMesero - 1] = propinasPorMesero;
            numDia = 0;
            numMesero++;
        }
    }
}

void incrementarPropinasPorDia(double*& propinasPorDia, const int numMesero, const int numDia, 
        const double propina, int* numPropinasDia, int* capPropinasDia) {
    const int indice = numMesero * NUM_DIAS + numDia;
    int num = numPropinasDia[indice];
    int cap = capPropinasDia[indice]; 

    if (num == cap) {
        incrementar(propinasPorDia, num, cap);
    }

    propinasPorDia[num - 1] = propina;
    propinasPorDia[num] = -1.0;

    numPropinasDia[indice] = ++num;
    capPropinasDia[indice] = cap;
}

void incrementarPropinasPorMesero(double**& propinasPorMesero, const double* propinasPorDia, 
        const int numMesero, const int numDia, int* numPropinasMesero, int* capPropinasMesero) {
    int num = numPropinasMesero[numMesero];
    int cap = capPropinasMesero[numMesero];

    if (num == cap) {
        incrementar(propinasPorMesero, num, cap);
    }
    propinasPorMesero[num - 1] = (double*)propinasPorDia;
    // no se realiza propinasPorMesero[num] = nullptr porque
    // durante el incremento ya es nulo al iniciar el arreglo con {}.

    numPropinasMesero[numMesero] = ++num;
    capPropinasMesero[numMesero] = cap;
}

void cargarPropinasExactas(const char* nombreArchivo, double***& propinas) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarPropinasExactas(archivo, propinas);
}

void cargarPropinasExactas(ifstream& archivo, double***& propinas) {
    int numMesero = 0, numDia = 0;
    int numDias[MAX_MESEROS] {}, numPropinas[MAX_MESEROS * NUM_DIAS] {};
    double buffer[MAX_MESEROS * NUM_DIAS * NUM_MESAS], propina;

    while (!archivo.eof() && archivo >> propina) {
        if (propina > 0.00) { // cuando se dejó propina
            const int indicePropinas = numMesero * NUM_DIAS + numDia;
            const int numPropina = numPropinas[indicePropinas]++;
            
            int posMesero = numMesero * (NUM_DIAS * NUM_MESAS);
            int posDia = numDia * NUM_MESAS;
            int indiceBuffer = posMesero + posDia + numPropina;
            
            buffer[indiceBuffer] = propina;
        }

        const char c = archivo.get();
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
    
    propinas = new double**[numMesero + 1] {};
    for (int i = 0; i < numMesero; i++) {
        const int noDias = numDias[i];
        asignarPropinasMesero(buffer, i, noDias, numPropinas, propinas[i]);
    }
}

void asignarPropinasMesero(const double* buffPropMesero, const int indiceMesero, const int numDias, const int* numPropinas, double**& propinasMesero) {
    propinasMesero = new double*[numDias + 1];
    
    int pos = indiceMesero * (NUM_DIAS * NUM_MESAS);
    for (int i = 0; i < numDias; i++) {
        int indicePropinaDia = indiceMesero * NUM_DIAS + i;
        int numPropina = numPropinas[indicePropinaDia];
        
        asignarPropinasDiarias(&buffPropMesero[pos], numPropina, propinasMesero[i]);
        pos += numPropina;
    }
    
    propinasMesero[numDias] = nullptr;
}

void asignarPropinasDiarias(const double* buffPropDiarias, const int num, double*& propDiarias) {
    propDiarias = new double[num + 1];
    
    for (int i = 0; i < num; i++) {
        propDiarias[i] = buffPropDiarias[i];
    }
    
    propDiarias[num] = -1.00;
}

void cargarMeseros(const char* nombreArchivo, Mesero*& meseros, const double*** propinas) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarMeseros(archivo, meseros, propinas);
}

void cargarMeseros(ifstream& archivo, Mesero*& meseros, const double*** propinas) {
    Mesero buffer[MAX_MESEROS] {}, mesero {};
    int num = 0;
    while (archivo >> mesero) {
        mesero *= propinas[num];
        buffer[num] = mesero;
        num++;
    }

    meseros = new Mesero[num + 1] {};
    for (int i = 0; i < num; i++) {
        insertarOrdenado(meseros, buffer[i], num);
    }
    meseros[num].dni = -1;
}

bool operator>>(ifstream& archivo, Mesero& mesero) {
    if (archivo >> mesero.dni) {
        archivo.ignore();
        mesero.nombre = leerCadena(archivo);
        archivo >> mesero.sueldoBruto;
        archivo.ignore();
        archivo >> mesero.experiencia;

        return true;
    }
    return false;
}

void operator*=(Mesero& mesero, const double** propinas) {
    mesero.propinas = 0.0;
    for (int i = 0; propinas[i]; i++) {
        mesero.propinas += sumarPropinas(propinas[i]);
    }
}

void insertarOrdenado(Mesero*& meseros, const Mesero& mesero, const int num) {
    int i = num - 1;

    while (i >=0 && meseros[i].propinas < mesero.propinas) {
        meseros[i + 1] = meseros[i];
        i--;
    }

    meseros[i + 1] = mesero;
}

double sumarPropinas(const double* propinas) {
    double suma = 0.0;
    for (int i = 0; propinas[i] != -1.00; i++) {
        suma += propinas[i];
    }
    return suma;
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

void mostrarMeseros(const char* nombreArchivo, const Mesero* meseros) {
    ofstream archivo(nombreArchivo, ios::out);
    mostrarMeseros(archivo, meseros);
}

void mostrarMeseros(ofstream& archivo, const Mesero* meseros) {
    archivo << left << setw(15) << "DNI"
            << setw(50) << "NOMBRE"
            << setw(20) << "SUELDO"
            << setw(20) << "EXPERIENCIA"
            << setw(15) << "PROPINAS" << endl;

    for (int i = 0; meseros[i].dni != -1; i++) {
        archivo << meseros[i];
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

ofstream& operator<<(ofstream& archivo, const Mesero& mesero) {
    archivo << left << setw(15) << mesero.dni
            << setw(50) << mesero.nombre
            << setw(20) << fixed << setprecision(2) << mesero.sueldoBruto
            << setw(20) << mesero.experiencia
            << right << fixed << setprecision(2) << setw(15) << mesero.propinas
            << endl;

    return archivo;
}

ofstream& operator<<(ofstream& archivo, const double* propinasDiarias) {
    for (int i = 0; propinasDiarias[i] != -1.00; i++) {
        const double propina = propinasDiarias[i];
        archivo << setw(6) << fixed << setprecision(2) << propina;
    }
    
    return archivo;
}

void asignarValores(int*& dnis, int*& capacidades, char**& nombres, const int numDatos, const int dni, const int capacidad, char* nombre) {
    dnis[numDatos] = dni;
    capacidades[numDatos] = capacidad;
    nombres[numDatos] = nombre;
}

void incrementar(int*& datos, const int numDatos, const int cap, const bool corte) {
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

void incrementar(char**& datos, const int numDatos, const int cap, const bool corte) {
    if (numDatos == 0) {
        datos = new char*[cap];
        if (corte) {
            datos[numDatos] = nullptr;
        }
    }
    else {
        char** aux = new char*[cap];
        
        for (int i = 0; i < numDatos && datos[i]; i++) {
            aux[i] = datos[i];
        }
        
        delete[] datos;
        datos = aux;
    }
}

void incrementar(double*& datos, int& numDatos, int& cap) {
    cap += INCREMENTO;
    if (numDatos == 0 || datos == nullptr) {
        datos = new double[cap];
        datos[numDatos] = -1.00;
        numDatos++;
    }
    else {
        double* aux = new double[cap];
        for (int i =0; i < numDatos; i++) {
            aux[i] = datos[i];
        }
        delete[] datos;
        datos = aux;
    }
}

void incrementar(double**& datos, int& numDatos, int& cap) {
    cap += INCREMENTO;
    if (numDatos == 0 || datos == nullptr) {
        datos = new double*[cap] {};
        numDatos++;
    }
    else {
        double** aux = new double*[cap];
        for (int i =0; i < numDatos; i++) {
            aux[i] = datos[i];
        }
        delete[] datos;
        datos = aux;
    }
}

void incrementar(double***& datos, int& numDatos, int& cap) {
    cap += INCREMENTO;
    if (numDatos == 0 || datos == nullptr) {
        datos = new double**[cap] {};
        numDatos++;
    }
    else {
        double*** aux = new double**[cap];
        for (int i =0; i < numDatos; i++) {
            aux[i] = datos[i];
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