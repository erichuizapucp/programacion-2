//
// Created by Eric Huiza on 9/4/25.
//
#include "funciones.h"

void cargarUsuarios(const char* nombreArchivo, void*& usuarios) {
    int num = 0, capacidad = 0;

    void** registros = nullptr;
    void** usuario;

    ifstream archivo(nombreArchivo, ios::in);
    while (leerUsuario(archivo, usuario)) {
        if (num == capacidad) {
            incrementarUsuarios(registros, num, capacidad);
        }
        insertarUsuarioOrdenado(registros, usuario, num);
        num++;
    }

    usuarios = registros;
}

void cargarPublicaciones(const char* nombreArchivo, void*& publicaciones) {
    int num = 0, capacidad = 0;

    void** registros = nullptr;
    void** publicacion;

    ifstream archivo(nombreArchivo, ios::in);
    while (leerPublicacion(archivo, publicacion)) {
        if (num == capacidad) {
            incrementarPublicaciones(registros, num, capacidad);
        }
        insertarPublicacionOrdenado(registros, publicacion, num);
        num++;
    }

    publicaciones = registros;
}

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

void incrementarUsuarios(void**& usuarios, int num, int& capacidad) {
    capacidad += 5;
    if (usuarios == nullptr) {
        usuarios = new void*[capacidad + 1] {};
    }
    else {
        void** aux = new void*[capacidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = usuarios[i];
        }
        delete[] usuarios;
        usuarios = aux;
    }
}

void incrementarPublicaciones(void**& publicaciones, int num, int& capacidad) {
    capacidad += 5;
    if (publicaciones == nullptr) {
        publicaciones = new void*[capacidad + 1] {};
    }
    else {
        void** aux = new void*[capacidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = publicaciones[i];
        }
        delete[] publicaciones;
        publicaciones = aux;
    }
}

bool leerUsuario(ifstream& archivo, void**& usuario) {
    char* cuenta = leerCadena(archivo);
    if (!archivo || cuenta[0] == '\0') {
        return false;
    }

    char* nombre = leerCadena(archivo);
    char* correo = leerCadena(archivo);
    char* facultad = leerCadena(archivo);

    int anho, mes, dia, edad;
    archivo >> anho;
    archivo.ignore();
    archivo >> mes;
    archivo.ignore();
    archivo >> dia;
    archivo.ignore();
    archivo >> edad;
    archivo.ignore();
    int fecha = anho * 10000 + mes * 100 + dia;

    usuario = new void*[8];
    usuario[0] = cuenta;
    usuario[1] = nombre;
    usuario[2] = correo;
    usuario[3] = facultad;
    usuario[4] = new int(fecha);
    usuario[5] = new int(edad);
    usuario[6] = nullptr; // aquí se referencia a las publicaciones del usuario.
    usuario[7] = nullptr; // aqui se referencia las publicaciones donde fue mencionado

    return true;
}

bool leerPublicacion(ifstream& archivo, void**& publicacion) {
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

        char* cuenta = leerCadena(archivo);

        archivo.ignore(); // ignorar el [
        char** menciones;
        cargarMenciones(archivo, menciones);

        archivo.ignore(); // ignorar el espacio después del ']'
        char* texto = leerCadena(archivo, '\n');

        publicacion = new void*[5];
        publicacion[0] = new int(id);
        publicacion[1] = new int(fecha);
        publicacion[2] = cuenta;
        publicacion[3] = menciones;
        publicacion[4] = texto;

        return true;
    }

    return false;
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

void insertarUsuarioOrdenado(void**& usuarios, void** usuario, int num) {
    int i;
    for (i = num - 1; i >= 0 && fechaRegistro(usuarios[i]) > fechaRegistro(usuario); i--) {
        usuarios[i + 1] = usuarios[i];
    }
    usuarios[i + 1] = usuario;
}

void insertarPublicacionOrdenado(void**& publicaciones, void** publicacion, int num) {
    int i;
    for (i = num - 1; i >= 0 && fechaPublicacion(publicaciones[i]) > fechaRegistro(publicacion); i--) {
        publicaciones[i + 1] = publicaciones[i];
    }
    publicaciones[i + 1] = publicacion;
}

void procesarPublicaciones(void*& usuarios, const void* publicaciones) {
    void** regUsuarios = (void**)usuarios;

    for (int i = 0; regUsuarios[i]; i++) {
        void** regUsuario = (void**)regUsuarios[i];
        asignarPublicaciones(regUsuario, publicaciones);
        asignarMenciones(regUsuario, publicaciones);
    }
}

void asignarPublicaciones(void**& usuario, const void* publicaciones) {
    const void** buffer[20]; // máximo 20 publicaciones por usuario
    int num = 0;
    void** regPublicaciones = (void**)publicaciones;
    const char* cuentaUsuario = (const char*)usuario[0];

    for (int i = 0; regPublicaciones[i]; i++) {
        const void** regPublicacion = (const void**)regPublicaciones[i];
        const char* cuentaPublicacion = (const char*)regPublicacion[2];

        if (strcmp(cuentaUsuario, cuentaPublicacion) == 0) {
            buffer[num++] = regPublicacion;
        }
    }

    usuario[6] = new void*[num + 1] {};
    void** pubs = (void**)usuario[6];
    for (int i = 0; i < num; i++) {
        pubs[i] = buffer[i];
    }
}

void asignarMenciones(void**& usuario, const void* publicaciones) {
    const void** buffer[10];
    int num = 0;

    void** regPublicaciones = (void**)publicaciones;
    const char* cuentaUsuario = (const char*)usuario[0];

    for (int i = 0; regPublicaciones[i]; i++) {
        const void** regPublicacion = (const void**)regPublicaciones[i];
        const char** mencionesPub = (const char**)regPublicacion[3];

        if (mencionadoEnPublicacion(cuentaUsuario, mencionesPub)) {
            buffer[num++] = regPublicacion;
        }
    }

    usuario[7] = new void*[num + 1] {};
    void** menciones = (void**)usuario[7];
    for (int i = 0; i < num; i++) {
        menciones[i] = buffer[i];
    }
}

void imprimirReporte(const char* nombreArchivo, const void* usuarios) {
    ofstream archivo(nombreArchivo, ios::out);

    const void** regUsuarios = (const void**)usuarios;

    for (int i = 0; regUsuarios[i]; i++) {
        const void** usuario = (const void**)regUsuarios[i];
        const void** pubsUsuario = (const void**)usuario[6];
        const void** pubsMencionan = (const void**)usuario[7];

        imprimirUsuario(archivo, usuario);
        imprimirPubsUsuario(archivo, pubsUsuario);
        imprimirMencionesUsuario(archivo, pubsMencionan);
        archivo << endl << endl;
    }
}

void imprimirUsuario(ofstream& archivo, const void** usuario) {
    const char* cuenta = (const char*)usuario[0];
    const char* nombre = (const char*)usuario[1];
    const char* correo = (const char*)usuario[2];
    const char* facultad = (const char*)usuario[3];
    const int fecha = *(const int*)usuario[4];
    const int edad = *(const int*)usuario[5];

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

void imprimirPubsUsuario(ofstream& archivo, const void** pubsUsuario) {
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    archivo << "PUBLICACIONES REALIZADAS" << endl;
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    for (int i = 0; pubsUsuario[i]; i++) {
        const void** regPubUsuario = (const void**)pubsUsuario[i];
        imprimirPubUsuario(archivo, regPubUsuario);
    }
}

void imprimirPubUsuario(ofstream& archivo, const void** pubUsuario) {
    int fecha = *(const int*)pubUsuario[1];
    const char* texto = (const char*)pubUsuario[4];

    archivo << "[";
    imprimirFecha(archivo, fecha);
    archivo << "]" << " " << texto << endl;
}

void imprimirMencionesUsuario(ofstream& archivo, const void** pubsMencionan) {
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    archivo << "PUBLICACIONES DONDE FUE MENCIONADO" << endl;
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    for (int i = 0; pubsMencionan[i]; i++) {
        const void** regPub = (const void**)pubsMencionan[i];
        const char* cuentaUsuario = (const char*)regPub[2];

        imprimirMencion(archivo, regPub, cuentaUsuario);
    }
}

void imprimirMencion(ofstream& archivo, const void** pub, const char* cuentaUsuario) {
    int fecha = *(const int*)pub[1];
    const char* cuentaPub = (const char*)pub[2];
    const char* textoPublicacion  = (const char*)pub[4];

    archivo << "En [";
    imprimirFecha(archivo, fecha);
    archivo << "], " << cuentaPub << " publicó \"" << textoPublicacion << "\"";
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

int fechaRegistro(void* usuario) {
    return *(int*)((void**)usuario)[4];
}

int fechaPublicacion(void* publicacion) {
    return *(int*)((void**)publicacion)[1];
}