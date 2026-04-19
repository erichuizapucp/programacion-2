//
// Created by Eric Huiza on 9/10/25.
//
#include "funciones.h"

void cargarCategorias(const char* nombreArchivo, char***& categorias) {
    int num = 0, capacidad = 0;

    categorias = nullptr;
    char** categoria;

    ifstream archivo(nombreArchivo, ios::in);
    while (leerCategoria(archivo, categoria)) {
        if (num == capacidad) {
            incrementarCategorias(categorias, num, capacidad);
        }

        categorias[num++] = categoria;
    }
}

void cargarStreamers(const char* nombreArchivo, char***& streamers,
                     int**& fechasPromedios, long long**& tiempoRepSegidores) {
    int num = 0, capacidad = 0;

    streamers = nullptr;
    fechasPromedios = nullptr;
    tiempoRepSegidores = nullptr;

    char** streamer;
    int* fechaPromedio;
    long long* tiempoRepSeguidor;

    ifstream archivo(nombreArchivo, ios::in);
    while (leerStreamer(archivo, streamer, fechaPromedio, tiempoRepSeguidor)) {
        if (num == capacidad) {
            capacidad += 5;
            incrementarStreamers(streamers, num, capacidad);
            incrementarFechasPromedios(fechasPromedios, num, capacidad);
            incrementarTiemposRepSegidores(tiempoRepSegidores, num, capacidad);
        }

        insertarOrdenado(streamers, fechasPromedios, tiempoRepSegidores,
                         streamer, fechaPromedio, tiempoRepSeguidor, num);
        num++;
    }
}

void cargarComentarios(const char* nombreArchivo, char***& comentarios, char***& etiquetas) {
    int num = 0, capacidad = 0;

    comentarios = nullptr;
    etiquetas = nullptr;

    char** comentario;
    char** etiquetasComentario;

    ifstream archivo(nombreArchivo, ios::in);
    while (leerComentario(archivo, comentario, etiquetasComentario)) {
        if (num == capacidad) {
            capacidad += 5;
            incrementarComentarios(comentarios, num, capacidad);
            incrementarEtiquetas(etiquetas, num, capacidad);
        }

        comentarios[num] = comentario;
        etiquetas[num] = etiquetasComentario;

        num++;
    }
}

void cargarEtiquetas(ifstream& archivo, char**& etiquetasComentario) {
    char* buffer[10];
    int num = 0;
    char* etiqueta;

    while (leerEtiqueta(archivo, etiqueta)) {
        buffer[num++] = etiqueta;
    }

    etiquetasComentario = new char*[num + 1] {};
    for (int i = 0; i < num; i++) {
        etiquetasComentario[i] = buffer[i];
    }
}

void incrementarCategorias(char***& categorias, int num, int& capacidad) {
    capacidad += 5;

    if (categorias == nullptr) {
        categorias = new char**[capacidad + 1] {};
    }
    else {
        char*** aux = new char**[capacidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = categorias[i];
        }
        delete[] categorias;
        categorias = aux;
    }
}

void incrementarStreamers(char***& streamers, int num, int cantidad) {
    if (streamers == nullptr) {
        streamers = new char**[cantidad + 1] {};
    }
    else {
        char*** aux = new char**[cantidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = streamers[i];
        }
        delete[] streamers;
        streamers = aux;
    }
}

void incrementarFechasPromedios(int**& fechasPromedios, int num, int cantidad) {
    if (fechasPromedios == nullptr) {
        fechasPromedios = new int*[cantidad + 1] {};
    }
    else {
        int** aux = new int*[cantidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = fechasPromedios[i];
        }
        delete[] fechasPromedios;
        fechasPromedios = aux;
    }
}

void incrementarTiemposRepSegidores(long long**& tiempoRepSeguidores, int num, int cantidad) {
    if (tiempoRepSeguidores == nullptr) {
        tiempoRepSeguidores = new long long*[cantidad + 1] {};
    }
    else {
        long long** aux = new long long*[cantidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = tiempoRepSeguidores[i];
        }
        delete[] tiempoRepSeguidores;
        tiempoRepSeguidores = aux;
    }
}

void incrementarComentarios(char***& comentarios, int num, int cantidad) {
    if (comentarios == nullptr) {
        comentarios = new char**[cantidad + 1] {};
    }
    else {
        char*** aux = new char**[cantidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = comentarios[i];
        }
        delete[] comentarios;
        comentarios = aux;
    }
}

void incrementarEtiquetas(char***& etiquetas, int num, int cantidad) {
    if (etiquetas == nullptr) {
        etiquetas = new char**[cantidad + 1] {};
    }
    else {
        char*** aux = new char**[cantidad + 1] {};
        for (int i = 0; i < num; i++) {
            aux[i] = etiquetas[i];
        }
        delete[] etiquetas;
        etiquetas = aux;
    }
}

void insertarOrdenado(char***& streamers, int**& fechasPromedios, long long**& tiempoRepSegidores,
                      char**& streamer, int*& fechaPromedio, long long*& tiempoRepSeguidor, int num) {
    int i;
    for (i = num - 1; i >= 0; i--) {
        long long* nuevoTiempoRepSeguidor = tiempoRepSegidores[i];

        long long cantSeguidoresActual = nuevoTiempoRepSeguidor[1];
        long long nuevaCantSeguidores = tiempoRepSeguidor[1];

        if (cantSeguidoresActual > nuevaCantSeguidores) {
            break;
        }

        fechasPromedios[i + 1] = fechasPromedios[i];
        tiempoRepSegidores[i + 1] = tiempoRepSegidores[i];
        streamers[i + 1] = streamers[i];
    }

    fechasPromedios[i + 1] = fechaPromedio;
    streamers[i + 1] = streamer;
    tiempoRepSegidores[i + 1] = tiempoRepSeguidor;
}

bool leerCategoria(ifstream& archivo, char**& categoria) {
    char* codigo = leerCadena(archivo);
    if (!archivo || codigo[0] == '\0') {
        return false;
    }

    char* nombre = leerCadena(archivo);
    char* descripcion = leerCadena(archivo, '\n');

    categoria = new char*[3] { codigo, nombre, descripcion };

    return true;
}

bool leerStreamer(ifstream& archivo, char**& streamer, int*& fechaPromedio, long long*& tiempoRepSeguidor) {
    char* cuenta = leerCadena(archivo);
    if (!archivo || cuenta[0] == '\0') {
        return false;
    }

    int fechaCreacion = leerFecha(archivo);
    archivo.ignore();
    int fechaUltimaTransmision = leerFecha(archivo);
    archivo.ignore();

    int promedioEspectadores;
    long long tiempoReproducido, seguidores;
    archivo >> tiempoReproducido;
    archivo.ignore();
    archivo >> promedioEspectadores;
    archivo.ignore();
    archivo >> seguidores;
    archivo.ignore();
    char* categoria = leerCadena(archivo, '\n');

    fechaPromedio = new int[3] { fechaCreacion, fechaUltimaTransmision, promedioEspectadores };
    tiempoRepSeguidor = new long long[2] { tiempoReproducido, seguidores };

    streamer = new char*[2] { cuenta, categoria };

    return true;
}

bool leerComentario(ifstream& archivo, char**& comentario, char**& etiquetasComentario) {
    char* cuenta = leerCadena(archivo);
    if (!archivo || cuenta[0] == '\n') {
        return false;
    }

    char* texto = leerCadena(archivo, '[');
    cargarEtiquetas(archivo, etiquetasComentario);
    if (archivo.peek() != '\n') {
        char* textoParte2 = leerCadena(archivo, '\n');
        int tamanoTotal = strlen(texto) + strlen(textoParte2) + 1;

        char* textoCompleto = new char[tamanoTotal];
        strcpy(textoCompleto, texto);
        strcat(textoCompleto, textoParte2);

        delete[] texto;
        delete[] textoParte2;

        texto = textoCompleto;
    }

    comentario = new char*[2] { cuenta, texto };

    return true;
}

bool leerEtiqueta(ifstream& archivo, char*& etiqueta) {
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

    etiqueta = new char[num + 1];
    strcpy(etiqueta, buffer);

    // consumir espacio
    if (archivo.peek() == ' ')
        archivo.get();

    return true;
}

int leerFecha(ifstream& archivo) {
    int dia, mes, anio;
    char sep;
    archivo >> dia >> sep >> mes >> sep >> anio;
    return anio * 10000 + mes * 100 + dia;
}

char* leerCadena(ifstream& archivo, char separador) {
    char buffer[1024];
    archivo.getline(buffer, 1024, separador);
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);

    return cadena;
}

void imprimirReporte(const char* nombreArchivo, const char*** categorias, const char*** streamers,
                     const int** fechasPromedios, const long long** tiempoRepSegidores,
                     const char*** comentarios, const char*** etiquetas) {
    ofstream archivo(nombreArchivo, ios::out);

    for (int i = 0; categorias[i]; i++) {
        const char** categoria = categorias[i];
        imprimirCategoria(archivo, categoria);

        const char* codigoCategoria = categoria[0];
        archivo << left
            << setw(20) << "CUENTA"
            << setw(30) << "FECHA CREACION"
            << setw(30) << "FECHA ULT. STREAM."
            << setw(20) << "TIEMPO REP."
            << setw(25) << "CANT. SEGUID."
            << setw(50) << "ETIQUETAS"
            << endl;
        archivo << setfill('=') << setw(200) << "" << setfill(' ') << endl;
        imprimirStreamersEnCategoria(archivo, streamers, fechasPromedios, tiempoRepSegidores,
                                     comentarios, etiquetas, codigoCategoria);
        archivo << endl << endl;
    }
}

void imprimirCategoria(ofstream& archivo, const char** categoria) {
    const char* nombreCategoria = categoria[1];
    archivo << "/"
        << setw(100) << setfill('*') << right << nombreCategoria
        << setw(100) << setfill('*') << left << ""
        << "/" << endl;
    archivo << setfill(' ');
}

void imprimirStreamersEnCategoria(ofstream& archivo, const char*** streamers, const int** fechasPromedios,
                                  const long long** tiemposRepSegidores, const char*** comentarios,
                                  const char*** etiquetas, const char* codigoCategoria) {
    for (int i = 0; streamers[i]; i++) {
        const char** streamer = streamers[i];
        const char* streamerCategoria = streamer[1];

        if (strcmp(codigoCategoria, streamerCategoria) == 0) {
            const int* fechaPromedio = fechasPromedios[i];
            const long long* tiempoRepSegidor = tiemposRepSegidores[i];

            imprimirStreamer(archivo, streamer, fechaPromedio, tiempoRepSegidor, comentarios, etiquetas);
        }
    }
}

void imprimirStreamer(ofstream& archivo, const char** streamer, const int* fechaPromedio,
                     const long long* tiempoRepSegidor, const char*** comentarios,
                     const char*** etiquetas) {
    const char* cuenta = streamer[0];

    int fechaCreacion = fechaPromedio[0];
    int fechaUltimaReproduccion = fechaPromedio[1];

    long long tiempoReproducido = tiempoRepSegidor[0];
    long long cantSeguidores = tiempoRepSegidor[1];

    double tiempoDias = (1.0 * tiempoReproducido) / (1000 * 60 * 60 * 24);

    archivo << left
            << setw(20) << cuenta;

    imprimirFecha(archivo, fechaCreacion);
    archivo << setw(20) << " ";
    imprimirFecha(archivo, fechaUltimaReproduccion);
    archivo << setw(20) << " ";

    archivo << setw(5) << fixed << setprecision(2) << tiempoDias << " (días)"
            << right << setw(25) << cantSeguidores;

    archivo << setw(5) << " ";
    imprimirEtiquetas(archivo, streamer, comentarios, etiquetas);
    archivo << endl;
}

void imprimirEtiquetas(ofstream& archivo, const char** streamer,
                                    const char*** comentarios, const char*** etiquetas) {
    for (int i = 0; comentarios[i]; i++) {
        const char** comentario = comentarios[i];
        const char* usuario = comentario[0];
        const char* texto = comentario[1];
        const char* cuentaStreamer = streamer[0];
        const char** etiquetasComentario = etiquetas[i];

        if (esEtiquedoEnComentario(etiquetasComentario, cuentaStreamer)) {
            archivo << "[" << usuario << "]" << " '" << texto <<"' ";
        }
    }
}

bool esEtiquedoEnComentario(const char** etiquetasComentario, const char* cuentaStreamer) {
    for (int i = 0; etiquetasComentario[i]; i++) {
        const char* etiqueta = etiquetasComentario[i];
        if (strcmp(etiqueta, cuentaStreamer) == 0) {
            return true;
        }
    }
    return false;
}

void imprimirFecha(ofstream& archivo, int fecha) {
    const int anho = fecha / 10000;
    const int mes  = (fecha / 100) % 100;
    const int dia  = fecha % 100;

    if (dia < 10) {
        archivo << '0';
    }
    archivo << dia << "-";

    if (mes < 10) {
        archivo << '0';
    }
    archivo << mes << "-";
    archivo << anho;
}