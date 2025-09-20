//
// Created by Eric Huiza on 9/4/25.
//
#include "../includes/funciones.h"
#include "../tads/includes/pila.h"
#include "../tads/includes/cola.h"

void cargarDatos(const char* nombreArchivo,
                void*& datos,
                bool (*leer)(ifstream& archivo, void**& dato),
                int (*ordenar)(const void* a, const void* b)) {

    int num = 0, capacidad = 0;

    void** registros = nullptr;
    void** dato;

    ifstream archivo(nombreArchivo, ios::in);
    while (leer(archivo, dato)) {
        if (num == capacidad) {
            incrementarCapacidad(registros, num, capacidad);
        }
        registros[num++] = dato;
    }

    qsort(registros, num, sizeof(int*), ordenar);
    datos = registros;
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

    if (num > 1) qsort(menciones, num, sizeof(int*), ordenarMenciones);
}

void incrementarCapacidad(void**& datos, int num, int& capacidad) {
    capacidad += 5;
    if (datos == nullptr) {
        datos = new void*[capacidad + 1] {};
    }
    else {
        void** aux = new void*[capacidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = datos[i];
        }
        delete[] datos;
        datos = aux;
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

    usuario = new void*[9];
    usuario[0] = cuenta;
    usuario[1] = nombre;
    usuario[2] = correo;
    usuario[3] = facultad;
    usuario[4] = new int(fecha);
    usuario[5] = new int(edad);
    usuario[6] = nullptr; // aquí se referencia a las publicaciones del usuario.
    usuario[7] = nullptr; // aqui se referencia las publicaciones donde fue mencionado
    usuario[8] = crearCola();

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

        publicacion = new void*[6];
        publicacion[0] = new int(id);
        publicacion[1] = new int(fecha);
        publicacion[2] = cuenta;
        publicacion[3] = menciones;
        publicacion[4] = texto;
        publicacion[5] = crearPila(); // aquí se referencia a los likes de la publicación.

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

bool leerLike(ifstream& archivo, void**& like) {
    int publicationId;
    while (archivo >> publicationId) {
        archivo.ignore();
        char* cuenta = leerCadena(archivo);
        int anho, mes, dia, hora, minuto, segundo;
        archivo >> dia;
        archivo.ignore();
        archivo >> mes;
        archivo.ignore();
        archivo >> anho;
        archivo.ignore();
        archivo >> hora;
        archivo.ignore();
        archivo >> minuto;
        archivo.ignore();
        archivo >> segundo;
        archivo.ignore();
        long long fechaHora = anho * 10000000000LL  // mueve 10 posiciones
                    + mes * 100000000LL             // mueve 8 posiciones
                    + dia * 1000000LL               // mueve 6 posiciones
                    + hora * 10000LL                // mueve 4 posiciones
                    + minuto * 100LL                // mueve 2 posiciones
                    + segundo;

        like = new void*[3];
        like[0] = new int(publicationId);
        like[1] = cuenta;
        like[2] = new long long(fechaHora);

        return true;
    }
    return false;
}

bool leerSolicitud(ifstream& archivo, void**& solicitud) {
    char* cuentaSolicita = leerCadena(archivo);
    if (!archivo || cuentaSolicita[0] == '\0') {
        return false;
    }

    char* cuentaDestino = leerCadena(archivo);

    int anho, mes, dia;
    archivo >> anho;
    archivo.ignore();
    archivo >> mes;
    archivo.ignore();
    archivo >> dia;
    archivo.ignore();
    int fecha = anho * 10000 + mes * 100 + dia;

    solicitud = new void*[3];
    solicitud[0] = cuentaSolicita;
    solicitud[1] = cuentaDestino;
    solicitud[2] = new int(fecha);

    return true;
}

void procesarDatos(void* usuarios, void* publicaciones, void* likes, void* solicitudes) {
    void** regUsuarios = (void**)usuarios;

    for (int i = 0; regUsuarios[i]; i++) {
        void** regUsuario = (void**)regUsuarios[i];
        asignarPublicaciones(regUsuario, publicaciones);
        asignarMenciones(regUsuario, publicaciones);
        asignarSolicitud(regUsuario, solicitudes);
    }

    void** regPublicaciones = (void**)publicaciones;
    for (int i = 0; regPublicaciones[i]; i++) {
        void** regPublicacion = (void**)regPublicaciones[i];
        asignarLikes(regPublicacion, likes);
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

void asignarLikes(void** publicacion, const void* likes) {
    int* idPublicacion = (int*)publicacion[0];
    void** pilaLikes = (void**)publicacion[5];

    void** regLikes = (void**)likes;
    for (int i = 0; regLikes[i]; i++) {
        void** regLike = (void**)regLikes[i];
        int* idPubLike = (int*)regLike[0];

        if (*idPublicacion == *idPubLike) {
            apilar(pilaLikes, regLike);
        }
    }
}

void asignarSolicitud(void** usuario, const void* solicitudes) {
    char* cuenta = (char*)usuario[0];
    void** colaSolicitudes = (void**)usuario[8];

    void** regSolicitudes = (void**)solicitudes;
    for (int i = 0; regSolicitudes[i]; i++) {
        void** regSolicitud = (void**)regSolicitudes[i];
        char* cuentaDestino = (char*)regSolicitud[1];
        if (strcmp(cuenta, cuentaDestino) == 0) {
            encolar(colaSolicitudes, regSolicitud);
        }
    }
}

int ordenarUsuarioPorFecha(const void* a, const void* b) {
    const void** usuarioPtr1 = (const void**)a; // casteamos el puntero al elemento
    const void** usuarioPtr2 = (const void**)b; // casteamos el puntero al elemento

    const void** usuario1 = (const void**)*usuarioPtr1; // obtenemos el puntero al registro
    const void** usuario2 = (const void**)*usuarioPtr2; // obtenemos el puntero al registro

    const int* fechaRegistro1 = (const int*)usuario1[4];
    const int* fechaRegistro2 = (const int*)usuario2[4];

    return (*fechaRegistro1) - (*fechaRegistro2);
}

int ordenarSolicitudPorFecha(const void* a, const void* b) {
    const void** solicitudPtr1 = (const void**)a; // casteamos el puntero al elemento
    const void** solicitudPtr2 = (const void**)b; // casteamos el puntero al elemento

    const void** solicitud1 = (const void**)*solicitudPtr1; // obtenemos el puntero al registro
    const void** solicitud2 = (const void**)*solicitudPtr2; // obtenemos el puntero al registro

    const int* fechaSolicitud1 = (const int*)solicitud1[2];
    const int* fechaSolicitud2 = (const int*)solicitud2[2];

    return (*fechaSolicitud1) - (*fechaSolicitud2);
}

int ordenarUsuarioPorNombre(const void* a, const void* b) {
    const void** usuarioPtr1 = (const void**)a; // casteamos el puntero al elemento
    const void** usuarioPtr2 = (const void**)b; // casteamos el puntero al elemento

    const void** usuario1 = (const void**)*usuarioPtr1;
    const void** usuario2 = (const void**)*usuarioPtr2;

    const char* nombre1 = (const char*)usuario1[1];
    const char* nombre2 = (const char*)usuario2[1];

    return strcmp(nombre1, nombre2);
}

int ordenarUsuarioPorEdad(const void* a, const void* b) {
    const void** usuarioPtr1 = (const void**)a; // casteamos el puntero al elemento
    const void** usuarioPtr2 = (const void**)b; // casteamos el puntero al elemento

    const void** usuario1 = (const void**)*usuarioPtr1;
    const void** usuario2 = (const void**)*usuarioPtr2;

    const int* edad1 = (const int*)usuario1[5];
    const int* edad2 = (const int*)usuario2[5];

    return (*edad1) - (*edad2);
}

int ordenarPublicacionPorFecha(const void* a, const void* b) {
    const void** pubPtr1 = (const void**)a; // casteamos el puntero al elemento
    const void** pubPtr2 = (const void**)b; // casteamos el puntero al elemento

    const void** pub1 = (const void**)*pubPtr1;
    const void** pub2 = (const void**)*pubPtr2;

    const int* fecha1 = (const int*)pub1[1];
    const int* fecha2 = (const int*)pub2[1];

    return (*fecha1) - (*fecha2);
}

int ordenarPublicacionPorContenido(const void* a, const void* b) {
    const void** pubPtr1 = (const void**)a; // casteamos el puntero al elemento
    const void** pubPtr2 = (const void**)b; // casteamos el puntero al elemento

    const void** pub1 = (const void**)*pubPtr1;
    const void** pub2 = (const void**)*pubPtr2;

    const char* texto1 = (const char*)pub1[4];
    const char* texto2 = (const char*)pub2[4];

    return strcmp(texto1, texto2);
}

int ordenarMenciones(const void* a, const void* b) {
    const char** menPtr1 = (const char**)a; // casteamos el puntero al elemento
    const char** menPtr2 = (const char**)b; // casteamos el puntero al elemento

    const char* men1 = *menPtr1;
    const char* men2 = *menPtr2;

    return strcmp(men1, men2);
}

int ordenarLikePorFechaHora(const void* a, const void* b) {
    const void** likePtr1 = (const void**)a; // casteamos el puntero al elemento
    const void** likePtr2 = (const void**)b; // casteamos el puntero al elemento

    const void** like1 = (const void**)*likePtr1;
    const void** like2 = (const void**)*likePtr2;

    const long long* fechaHora1 = (const long long*)like1[2];
    const long long* fechaHora2 = (const long long*)like2[2];

    return (*fechaHora1) - (*fechaHora2);
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
        imprimirSolicitudedUsuario(archivo, (void**)usuario);

        archivo << endl << endl;
    }
}

void imprimirUsuario(ostream& archivo, const void** usuario) {
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

void imprimirPubsUsuario(ostream& archivo, const void** pubsUsuario) {
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    archivo << "PUBLICACIONES REALIZADAS" << endl;
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    for (int i = 0; pubsUsuario[i]; i++) {
        const void** regPubUsuario = (const void**)pubsUsuario[i];
        imprimirPubUsuario(archivo, regPubUsuario);
    }
}

void imprimirSolicitudedUsuario(ostream& archivo, void** usuario) {
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    archivo << "SOLICITUDES DE AMISTAD" << endl;
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    void** regUsuario = (void**)usuario;
    const void** colaSolicitudes = (const void**)regUsuario[8];
    imprimirCola(archivo, colaSolicitudes, imprimirSolicitud);
}

void imprimirPubUsuario(ostream& archivo, const void** pubUsuario) {
    const int fecha = *(const int*)pubUsuario[1];
    const char* texto = (const char*)pubUsuario[4];
    const void** likesPubUsuario = (const void**)pubUsuario[5];

    archivo << "[";
    imprimirFecha(archivo, fecha);
    archivo << "]" << " " << texto << endl;

    archivo << "[LIKES]" << " ";
    imprimirPila(archivo, likesPubUsuario, imprimirLike);
    archivo << endl;
}

void imprimirMencionesUsuario(ostream& archivo, const void** pubsMencionan) {
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    archivo << "PUBLICACIONES DONDE FUE MENCIONADO" << endl;
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    for (int i = 0; pubsMencionan[i]; i++) {
        const void** regPub = (const void**)pubsMencionan[i];
        const char* cuentaUsuario = (const char*)regPub[2];

        imprimirMencion(archivo, regPub, cuentaUsuario);
    }
}

void imprimirMencion(ostream& archivo, const void** pub, const char* cuentaUsuario) {
    int fecha = *(const int*)pub[1];
    const char* cuentaPub = (const char*)pub[2];
    const char* textoPublicacion  = (const char*)pub[4];

    archivo << "En [";
    imprimirFecha(archivo, fecha);
    archivo << "], " << cuentaPub << " publicó \"" << textoPublicacion << "\"";
    archivo << " y mencionó a " << cuentaUsuario << endl;
}

void imprimirLike(ostream& archivo, void* like) {
    void** regLike = (void**)like;
    const char* cuenta = (const char*)regLike[1];
    long long fechaHora = *(const long long*)regLike[2];
    archivo << cuenta << " (";
    imprimirFechaHora(archivo, fechaHora);
    archivo << ") ";
}

void imprimirSolicitud(ostream& archivo, void* solicitud) {
    void** regSolicitud = (void**)solicitud;
    char* cuentaSolicita = (char*)regSolicitud[0];
    char* cuentaDestino = (char*)regSolicitud[1];
    int fecha = *(int*)regSolicitud[2];

    archivo << cuentaSolicita << " solicitó amistad a " << cuentaDestino << " el ";
    imprimirFecha(archivo, fecha);
    archivo << endl;
}

bool mencionadoEnPublicacion(const char* cuentaUsuario, const char** mencionesPub) {
    int num = 0;
    for (int i = 0; mencionesPub[i]; i++) num++;

    void* res = bsearch(&cuentaUsuario, mencionesPub, num, sizeof(char*), ordenarMenciones);
    return res != nullptr;
}

char* leerCadena(ifstream& archivo, char separador) {
    char buffer[1024];
    archivo.getline(buffer, 1024, separador);
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);

    return cadena;
}

void imprimirFecha(ostream& archivo, int fecha) {
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

void imprimirFechaHora(std::ostream& archivo, long long fechaHora) {
    const int anho = fechaHora / 10000000000LL;
    const int mes = (fechaHora / 100000000LL) % 100;
    const int dia = (fechaHora / 1000000LL) % 100;
    const int hora = (fechaHora / 10000LL) % 100;
    const int minuto = (fechaHora / 100LL) % 100;
    const int segundo = fechaHora % 100;

    archivo << (dia / 10) << (dia % 10) << "-"
            << (mes / 10) << (mes % 10) << "-"
            << (anho / 1000) % 10
            << (anho / 100) % 10
            << (anho / 10) % 10
            << (anho % 10) << " "
            << (hora / 10) << (hora % 10) << ":"
            << (minuto / 10) << (minuto % 10) << ":"
            << (segundo / 10) << (segundo % 10);
}

int fechaRegistro(void* usuario) {
    const int* fechaRegistro = (const int*)((void**)usuario)[4];
    return *fechaRegistro;
}

int fechaPublicacion(void* publicacion) {
    const int* fechaPublicacion = (const int*)((void**)publicacion)[1];
    return *fechaPublicacion;
}