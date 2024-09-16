#include "funciones.h"

void cargarDatos(const char* nombreArchivo, void*& datos) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarDatos(archivo, datos);
}

void cargarDatos(ifstream& archivo, void*& datos) {
    int cap = 0, num = 0;
    void* dato = new void*[4];
    void** vv = (void**)datos;

    while (archivo >> dato) {
        if (num == cap) {
            incrementar(vv, num, cap);
        }
        vv[num - 1] = dato;
        vv[num++] = nullptr;
    }
    datos = vv;
}

void incrementar(void**& datos, int& num, int& cap) {
    cap += 5;
    if (num == 0 && datos == nullptr) {
        datos = new void*[cap] {};
        num++;
        
    }
    else {
        void** aux = new void*[cap];

        for (int i = 0; i < num; i++) {
            aux[i] = datos[i];
        }
        delete[] datos;
        datos = aux;
    }
}

bool operator>>(ifstream& archivo, void*& registro) {
    return cargarMesero(archivo, registro);
}

bool cargarMesero(ifstream& archivo, void*& registro) {
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
        registro = mesero;

        return true;
    }

    return false;
}

void mostrarDatos(const void* datos) {
    cout << left << setw(15) << "DNI"
        << setw(50) << "NOMBRE"
        << setw(15) << "SUELDO"
        << setw(15) << "EXPERIENCIA"
        << endl;

    const void** vv = (const void**)datos;
    for (int i = 0; vv[i]; i++) {
        cout << (const void**)vv[i];
    }
}

ostream& operator<<(ostream& os, const void** dato) {
    os << left << setw(15) << *(int*)dato[0]
        << setw(50) << (char*)dato[1]
        << right << setw(15) << fixed << setprecision(2) << *(double*)dato[2]
        << setw(15) << *(int*)dato[3]
        << endl;

    return os;
}

char* leerCadena(ifstream& archivo, char delimitador) {
    char buffer[100];
    archivo.getline(buffer, 100, delimitador);

    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);

    return cadena;
}