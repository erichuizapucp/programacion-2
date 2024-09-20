#include <stdlib.h>

#include "funciones.h"
#include "enums.h"

void cargarDatos(const char* nombreArchivo, void*& datos) {
    ifstream archivo(nombreArchivo, ios::in);
    cargarDatos(archivo, datos);
}

void cargarDatos(ifstream& archivo, void*& datos) {
    int cap = 0, num = 0;
    void* dato = new void*[4];
    void** vv;

    while (archivo >> dato) {
        if (num == cap) {
            incrementar(vv, num, cap);
        }
        vv[num - 1] = dato;
        vv[num++] = nullptr;
    }
    
    // ordernar (en este caso por DNI)
    // usamos num - 1 porque no podemos incluir al último elemento `nullptr`
    // en el ordenamiento
    qsort(vv, num - 1, sizeof(void*), compararDni);
    
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
        mesero[Mesero::DNI] = new int(dni);
        mesero[Mesero::NOMBRE] = nombre;
        mesero[Mesero::SUELDO] = new double(sueldo);
        mesero[Mesero::EXPERIENCA] = new int(experiencia);
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
    os << left << setw(15) << *(int*)dato[Mesero::DNI]
        << setw(50) << (char*)dato[Mesero::NOMBRE]
        << right << setw(15) << fixed << setprecision(2) << *(double*)dato[Mesero::SUELDO]
        << setw(15) << *(int*)dato[Mesero::EXPERIENCA]
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

int compararDni(const void* a, const void* b) {
    const void** pa = (const void**)a;
    const void** pb = (const void**)b;
    
    const void** meseroa = (const void**)*pa;
    const void** meserob = (const void**)*pb;
    
    const int dnia = *(const int*)meseroa[Mesero::DNI];
    const int dnib = *(const int*)meserob[Mesero::DNI];
    
    return dnia - dnib;
}

int compararNombre(const void* a, const void* b) {
    const void** pa = (const void**)a;
    const void** pb = (const void**)b;
    
    const void** meseroa = (const void**)*pa;
    const void** meserob = (const void**)*pb;
    
    const char* nombrea = (const char*)meseroa[Mesero::NOMBRE];
    const char* nombreb = (const char*)meserob[Mesero::NOMBRE];
    
    return strcmp(nombrea, nombreb);
}

int compararSueldo(const void* a, const void* b) {
    const void** pa = (const void**)a;
    const void** pb = (const void**)b;
    
    const void** meseroa = (const void**)*pa;
    const void** meserob = (const void**)*pb;
    
    const double sueldoa = *(const double*)meseroa[Mesero::SUELDO];
    const double sueldob = *(const double*)meserob[Mesero::SUELDO];
    
    return sueldoa - sueldob;
}

int compararExperiencia(const void* a, const void* b) {
    const void** pa = (const void**)a;
    const void** pb = (const void**)b;
    
    const void** meseroa = (const void**)*pa;
    const void** meserob = (const void**)*pb;
    
    const int experienciaa = *(const int*)meseroa[Mesero::EXPERIENCA];
    const int experienciab = *(const int*)meserob[Mesero::EXPERIENCA];
    
    return experienciaa - experienciab;
}

bool buscar(const int dni, const void* datos, void*& mesero) {
    // la llave tiene que ser void** porque es el tipo de dato de los elementos
    // solo asignamos memoria para el DNI `new void*[1]` ya que solo estamos buscando por DNI
    void** llave = new void*[1];
    llave[Mesero::DNI] = new int(dni);
    
    int num = numeroElementos(datos);
    
    // recibe un puntero al elemento que se va a buscar.
    // el elemento que se buscará es un void**, entonces &llave
    void* res = bsearch(&llave, datos, num, sizeof(void*), compararDni);
    if (res != nullptr) {
        // retorna un puntero al elemento encontrado
        // como el elemento es un void** un puntero a un void** es un void***
        // al dereferenciar *void*** obtenemos un void**
        // ese void** se asigna de regreso al puntero void*& de salida.
        mesero = *(void***)res;
        
        return true;
    }
    
    delete (int*)llave[Mesero::DNI];
    delete[] llave;
    
    return false;
}

int numeroElementos(const void* datos) {
    int i = 0;
    
    const void** vv = (const void**)datos;
    for (;vv[i];i++);
    
    return i;
}

void liberarMemoria(void* meseros) {
    void** vv = (void**)meseros;
    for (int i = 0; vv[i]; i++) {
        void** mesero = (void**)vv[i];
        delete (int*)mesero[Mesero::DNI];
        delete[] (char*)mesero[Mesero::NOMBRE];
        delete (double*)mesero[Mesero::SUELDO];
        delete (int*)mesero[Mesero::EXPERIENCA];
        delete[] mesero;
    }
    delete[] (void**)meseros;
}