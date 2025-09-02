//
// Created by Eric Huiza on 9/1/25.
//

#include "funciones.h"
#include "qsort.h"

void cargarUsuarios(const char* nombreArchivo, Usuario*& usuarios) {
    int capacidad = 0;
    int num = 0;
    Usuario dato;
    usuarios = nullptr;

    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> dato) {
        if (capacidad == num) {
            incrementarCapacidadUsuarios(usuarios,
                num, capacidad);
        }
        usuarios[num] = { -1 };
        usuarios[num - 1] = dato;
        num++;
    }

    qsort(usuarios, 0, num - 2);
}

void cargarPublicaciones(const char* nombreArchivo,
    Publicacion*& publicaciones) {

    int capacidad = 0;
    int num = 0;
    Publicacion dato;
    publicaciones = nullptr;

    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> dato) {
        if (capacidad == num) {
            incrementarCapacidadPublicaciones(
                publicaciones, num, capacidad);
        }
        publicaciones[num] = { -1 };
        publicaciones[num - 1] = dato;
        num++;
    }
}

void incrementarCapacidadUsuarios(Usuario*& usuarios,
    int& num, int& capacidad) {
    capacidad += 5;
    if (usuarios == nullptr) {
        usuarios = new Usuario[capacidad];
        usuarios[num] = { - 1};
        num = 1;
    }
    else {
        Usuario* aux = new Usuario[capacidad];
        for (int i = 0; i < num; i++) {
            aux[i] = usuarios[i];
        }
        delete[] usuarios;
        usuarios = aux;
    }
}

void incrementarCapacidadPublicaciones(Publicacion*& publicaciones,
    int& num, int& capacidad) {
    capacidad += 5;
    if (publicaciones == nullptr) {
        publicaciones = new Publicacion[capacidad];
        publicaciones[num] = { - 1};
        num = 1;
    }
    else {
        Publicacion* aux = new Publicacion[capacidad];
        for (int i = 0; i < num; i++) {
            aux[i] = publicaciones[i];
        }
        delete[] publicaciones;
        publicaciones = aux;
    }
}

bool operator>>(ifstream& archivo, Usuario& usuario) {
    if (archivo >> usuario.dni) {
        archivo.ignore(); // ignorar la coma
        usuario.nombre = leerCadena(archivo);
        usuario.correo = leerCadena(archivo);
        archivo >> usuario.membresia;
        archivo.ignore(); // ignorar el salto de línea

        return true;
    }

    return false;
}

bool operator>>(ifstream& archivo, Publicacion& publicacion) {
    if (archivo >> publicacion.dniUsuario) {
        archivo.ignore(); // ignorar la coma
        archivo >> publicacion.id;
        archivo.ignore(); // ignorar la coma
        archivo >> publicacion.anho;
        archivo.ignore(); // ignorar el guion
        archivo >> publicacion.mes;
        archivo.ignore(); // ignorar el guion
        archivo >> publicacion.dia;
        archivo.ignore(); // ignorar la coma
        publicacion.contenido = leerCadena(archivo, '\n');

        return true;
    }

    return false;
}

ostream& operator<<(ostream& os, const Usuario& usuario) {
    return os;
}


char* leerCadena(istream& archivo, char delimitador) {
    char buffer[200];
    archivo.getline(buffer, 200, delimitador);
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}