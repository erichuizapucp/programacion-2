//
// Created by Eric Huiza on 9/4/25.
//
#include "funciones.h"

void cargarUsuarios(const char* nombreArchivo,
                    char***& usuarios, int**& fechasEdades) {
    int num = 0, capacidad = 0;

    usuarios = nullptr;
    fechasEdades = nullptr;

    char** usuario;
    int* fechaEdad;

    ifstream archivo(nombreArchivo, ios::in);
    while (leerUsuario(archivo, usuario) &&
           leerFechaEdad(archivo, fechaEdad)) {
        if (num == capacidad) {
            capacidad += 5;
            incrementarUsuarios(usuarios, num, capacidad);
            incrementarFechasEdades(fechasEdades, num, capacidad);
        }

        insertarOrdenado(usuarios, fechasEdades,
                         usuario, fechaEdad, num);
        num++;
    }
}

void cargarPublicaciones(const char* nombreArchivo, int**& idsFechas,
                         char***& publicaciones, char***& menciones) {
    int num = 0, capacidad = 0;

    idsFechas = nullptr;
    publicaciones = nullptr;
    menciones = nullptr;

    int* idFecha;
    char** publicacion;
    char** mencionesPub;

    ifstream archivo(nombreArchivo, ios::in);
    while (leerIdFecha(archivo, idFecha) &&
           leerPublicacion(archivo, publicacion, mencionesPub)) {
        if (num == capacidad) {
            capacidad += 5;
            incrementarIdsFechas(idsFechas, num, capacidad);
            incrementarPublicaciones(publicaciones, num, capacidad);
            incrementarMenciones(menciones, num, capacidad);
        }

        insertarOrdenado(idsFechas, publicaciones, menciones,
                         idFecha, publicacion, mencionesPub, num);
        num++;
    }
}

// Cargar menciones de forma exacta
void cargarMenciones(ifstream& archivo, char**& menciones) {
    char* buffer[10]; // máximo 10 menciones por publicación
    int num = 0;
    char* mencion;

    while (leerMencion(archivo, mencion)) {
        buffer[num++] = mencion;
    }

    menciones = new char*[num + 1] {}; // agregamos un NULL al final
    for (int i = 0; i < num; i++) {
        menciones[i] = buffer[i];
    }
}

void incrementarUsuarios(char***& usuarios, int num, int capacidad) {
    if (usuarios == nullptr) {
        usuarios = new char**[capacidad + 1] {};
    }
    else {
        char*** aux = new char**[capacidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = usuarios[i];
        }
        delete[] usuarios;
        usuarios = aux;
    }
}

void incrementarFechasEdades(int**& fechasEdades, int num, int capacidad) {
    if (fechasEdades == nullptr) {
        fechasEdades = new int*[capacidad + 1] {};
    }
    else {
        int** aux = new int*[capacidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = fechasEdades[i];
        }
        delete[] fechasEdades;
        fechasEdades = aux;
    }
}

void incrementarIdsFechas(int**& idsFechas, int num, int capacidad) {
    if (idsFechas == nullptr) {
        idsFechas = new int*[capacidad + 1] {};
    }
    else {
        int** aux = new int*[capacidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = idsFechas[i];
        }
        delete[] idsFechas;
        idsFechas = aux;
    }
}

void incrementarPublicaciones(char***& publicaciones, int num, int capacidad) {
    if (publicaciones == nullptr) {
        publicaciones = new char**[capacidad + 1] {};
    }
    else {
        char*** aux = new char**[capacidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = publicaciones[i];
        }
        delete[] publicaciones;
        publicaciones = aux;
    }
}

void incrementarMenciones(char***& menciones, int num, int capacidad) {
    if (menciones == nullptr) {
        menciones = new char**[capacidad + 1] {};
    }
    else {
        char*** aux = new char**[capacidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = menciones[i];
        }
        delete[] menciones;
        menciones = aux;
    }
}

bool leerUsuario(ifstream& archivo, char**& usuario) {
    char* cuenta = leerCadena(archivo);
    if (!archivo || cuenta[0] == '\0') {
        return false;
    }

    char* nombre   = leerCadena(archivo);
    char* correo   = leerCadena(archivo);
    char* facultad = leerCadena(archivo);

    usuario = new char*[4] { cuenta, nombre, correo, facultad };

    return true;
}

bool leerFechaEdad(ifstream &archivo, int*& fechaEdad) {
    int anho;
    if (archivo >> anho) {
        int mes, dia, edad;
        archivo.ignore();
        archivo >> mes;
        archivo.ignore();
        archivo >> dia;
        archivo.ignore();
        archivo >> edad;
        archivo.ignore();

        int fecha = anho * 10000 + mes * 100 + dia;
        fechaEdad = new int[2] { fecha, edad };

        return true;
    }

    return false;
}

bool leerIdFecha(ifstream& archivo, int*& idFecha) {
    int id;
    if (archivo >> id) {
        archivo.ignore();

        int anho, mes, dia;
        archivo >> anho;
        archivo.ignore();
        archivo >> mes;
        archivo.ignore();
        archivo >> dia;
        archivo.ignore();

        int fecha = anho * 10000 + mes * 100 + dia;
        idFecha = new int[2] { id, fecha };
        return true;
    }

    return false;
}

bool leerPublicacion(ifstream& archivo, char**& publicacion, char**& mencionesPub) {
    char* cuenta = leerCadena(archivo);
    if (!archivo || cuenta[0] == '\0') {
        return false;
    }

    // si aún hay datos y se puede seguir leyendo
    archivo.ignore(); // ignorar el [
    cargarMenciones(archivo, mencionesPub);
    archivo.ignore(); // ignorar el espacio
    char* texto = leerCadena(archivo, '\n');

    publicacion = new char*[2] { cuenta, texto };

    return true;
}

bool leerMencion(ifstream& archivo, char*& mencion) {
    char buffer[20];
    int num = 0;

    // si siguiente es ']', no hay más menciones
    if (archivo.peek() == ']') {
        archivo.get(); // consumir ']'
        return false;
    }

    while (archivo.peek() != ' ' && archivo.peek() != ']') {
        buffer[num++] = archivo.get();
    }

    buffer[num] = '\0';

    mencion = new char[num + 1];
    strcpy(mencion, buffer);

    // consumir espacio
    if (archivo.peek() == ' ')
        archivo.get();

    return true;
}

void insertarOrdenado(char***& usuarios, int**& fechasEdades, char** usuario,
                      int* fechaEdad, int num) {
    int i;
    int nuevaFechaRegistro = fechaEdad[0];


    for (i = num - 1; i >= 0; i--) {
        int fechaRegistroActual = fechaRegistro(fechasEdades[i]);
        if (fechaRegistroActual <= nuevaFechaRegistro) {
            break;
        }

        usuarios[i + 1] = usuarios[i];
        fechasEdades[i + 1] = fechasEdades[i];
    }

    usuarios[i + 1] = usuario;
    fechasEdades[i + 1] = fechaEdad;
}

void insertarOrdenado(int**& idsFecha, char***& publicaciones, char***& menciones,
                      int* idFecha, char** publicacion, char** mencionesPub,
                      int num) {
    int i;
    int nuevaFechaPublicacion = idFecha[1];

    for (i = num - 1; i >= 0; i--) {
        int fechaPublicacionActual = fechaPublicacion(idsFecha[i]);

        if (fechaPublicacionActual <= nuevaFechaPublicacion) {
            break;
        }

        publicaciones[i + 1] = publicaciones[i];
        idsFecha[i + 1] = idsFecha[i];
        menciones[i + 1] = menciones[i];
    }

    publicaciones[i + 1] = publicacion;
    idsFecha[i + 1] = idFecha;
    menciones[i + 1] = mencionesPub;
}

void imprimirReporte(const char* nombreArchivo, const char*** usuarios,
                     const int** fechasEdades,
                     const int** idsFechas, const char*** publicaciones,
                     const char*** menciones) {
    ofstream archivo(nombreArchivo, ios::out);

    for (int i = 0; usuarios[i]; i++) {
        const char** usuario = usuarios[i];
        const int* fechasEdad = fechasEdades[i];
        const char* cuentaUsuario = usuario[0];

        imprimirUsuario(archivo, usuario, fechasEdad);
        imprimirPubsUsuario(archivo, cuentaUsuario, idsFechas, publicaciones);
        imprimirMencionesUsuario(archivo, cuentaUsuario, idsFechas, publicaciones, menciones);
        archivo << endl << endl;
    }
}

void imprimirUsuario(ofstream& archivo, const char** usuario, const int* fechaEdad) {
    const char* cuenta = usuario[0];
    const char* nombre = usuario[1];
    const char* correo = usuario[2];
    const char* facultad = usuario[3];
    const int fecha = fechaEdad[0];
    const int edad = fechaEdad[1];

    archivo << setfill('=') << setw(40) << "" << setfill(' ') << endl;
    archivo << "REPORTE DE USUARIO" << endl;
    archivo << setfill('=') << setw(40) << "" << setfill(' ') << endl;

    archivo << left
            << setw(10) << "Cuenta:" << setw(15) << cuenta   << endl
            << setw(10) << "Nombre:" << setw(20) << nombre   << endl
            << setw(10) << "Correo:" << setw(25) << correo   << endl
            << setw(10) << "Facultad:" << setw(15) << facultad << endl
            << setw(10) << "Fecha: ";
    imprimirFecha(archivo, fecha);
    archivo << endl;
    archivo << setw(10) << "Edad:" << setw(3)  << edad
            << endl;
}

void imprimirPubsUsuario(ofstream& archivo, const char* cuentaUsuario,
                         const int** idsFechas,
                         const char*** publicaciones) {
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    archivo << "PUBLICACIONES REALIZADAS" << endl;
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    for (int i = 0; idsFechas[i]; i++) {
        const char** publicacion = publicaciones[i];
        const char* cuenta = publicacion[0];

        if (strcmp(cuenta, cuentaUsuario) == 0) {
            const int* idFecha = idsFechas[i];
            imprimirPubUsuario(archivo, publicacion, idFecha);
        }
    }
}

void imprimirPubUsuario(ofstream& archivo, const char** publicacion, const int* idFecha) {
    int fecha = idFecha[1];
    const char* texto = publicacion[1];

    archivo << "[";
    imprimirFecha(archivo, fecha);
    archivo << "]" << " " << texto << endl;
}

void imprimirMencionesUsuario(ofstream& archivo, const char* cuentaUsuario, const int** idsFechas,
                              const char*** publicaciones, const char*** menciones) {
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    archivo << "PUBLICACIONES DONDE FUE MENCIONADO" << endl;
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    for (int i = 0; publicaciones[i]; i++) {
        const char** mencionesPub = menciones[i];
        if (mencionadoEnPublicacion(cuentaUsuario, mencionesPub)) {
            const int* idFecha = idsFechas[i];
            const char** publicacion = publicaciones[i];
            imprimirMencion(archivo, idFecha, publicacion, cuentaUsuario);
        }
    }
}

void imprimirMencion(ofstream& archivo, const int* idFecha, const char** publicacion, const char* cuentaUsuario) {
    int fecha = idFecha[1];
    const char* cuentaPublicacion = publicacion[0];
    const char* textoPublicacion  = publicacion[1];

    archivo << "En [";
    imprimirFecha(archivo, fecha);
    archivo << "], " << cuentaPublicacion << " publicó \"" << textoPublicacion << "\"";
    archivo << " y mencionó a " << cuentaUsuario << endl;
}

bool mencionadoEnPublicacion(const char* cuentaUsuario, const char** mencionesPub) {
    for (int i = 0; mencionesPub[i]; i++) {
        const char* cuenta = mencionesPub[i];

        if (strcmp(cuenta, cuentaUsuario) == 0) {
            return true;
        }
    }
    return false;
}

char* leerCadena(ifstream& archivo, char separador) {
    char buffer[1024];
    archivo.getline(buffer, 1024, separador);
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);

    return cadena;
}

void imprimirFecha(ofstream& archivo, int fecha) {
    const int anho  = fecha / 10000;
    const int mes   = (fecha / 100) % 100;
    const int dia   = fecha % 100;

    archivo << (dia / 10) << (dia % 10) << "-"
            << (mes / 10) << (mes % 10) << "-"
            << (anho / 1000) % 10
            << (anho / 100) % 10
            << (anho / 10) % 10
            << anho % 10;
}

int fechaRegistro(const int* fechaEdad) {
    return fechaEdad[0];
}

int fechaPublicacion(const int* idFecha) {
    return idFecha[1];
}