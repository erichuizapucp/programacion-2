#include "funciones.h"

void cargarDatos(
    const char* nombreArchivo, 
    Lista& datos, 
    bool(*cargar)(ifstream& archivo, void*& dato)
) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarDatos(archivo, datos, cargar);
}

void cargarDatos(
    ifstream& archivo, 
    Lista& datos, 
    bool(*cargar)(ifstream& archivo, void*& dato)
) {
    void* dato;
    while (cargar(archivo, dato)) {
        insertar(datos, datos.cabeza, dato);
    }
}

bool cargarMesero(ifstream& archivo, void*& dato) {
    dato = new void*[4];
    
    int dni;
    if (archivo >> dni) {
        double sueldo;
        int experiencia;
        archivo.ignore();
        char *nombre = leerCadena(archivo);
        archivo >> sueldo;
        archivo.ignore();
        archivo >> experiencia;
        archivo.ignore();

        void **mesero = new void *[4];
        mesero[0] = new int(dni);
        mesero[1] = nombre;
        mesero[2] = new double(sueldo);
        mesero[3] = new int(experiencia);
        dato = mesero;

        return true;
    }

    return false;
}

void mostrarDatos(
    const char* nombreArchivo, 
    const Lista& datos, 
    void(*cabecera)(ofstream& archivo), 
    void(*mostrar)(ofstream& archivo, const void* datos)
) {
    ofstream archivo(nombreArchivo, ios::out);
    mostrarDatos(archivo, datos, cabecera, mostrar);
}

void mostrarDatos(
    ofstream& archivo, 
    const Lista& datos, 
    void(*cabecera)(ofstream& archivo), 
    void(*mostrar)(ofstream& archivo, const void* datos)
) {
    cabecera(archivo);
    recorrer(datos, archivo, mostrar);
}

void mostrarMesero(ofstream& archivo, const void* dato) {
    const void** vv = (const void**)dato;
    
    archivo << left << setw(15) << *(const int*)vv[0]
            << setw(50) << (const char*)vv[1]
            << right << setw(15) << fixed << setprecision(2) << *(const double*)vv[2]
            << setw(15) << *(const int*)vv[3]
            << endl;
}

void mostrarCabeceraMeseros(ofstream& os) {
    os << left << setw(15) << "DNI"
        << setw(50) << "NOMBRE"
        << setw(15) << "SUELDO"
        << setw(15) << "EXPERIENCIA"
        << endl;
}

void mostrarEntero(const void* dato) {
    cout << *(int*)dato << endl;
}

void destruirEntero(void* datos) {
    delete (int*)datos;
}

void destruirMesero(void* datos) {
    void** mesero = (void**)datos;
    
    delete (int*)mesero[0];
    delete (char*)mesero[1];
    delete (double*)mesero[2];
    delete (int*)mesero[3];
}

char* leerCadena(ifstream& archivo, char delimitador) {
    char buffer[100];
    archivo.getline(buffer, 100, delimitador);

    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);

    return cadena;
}