//
// Created by Eric Huiza on 8/29/25.
//
#include "funciones.h"


void cargarUsuarios(const char* nombreArchivo, Usuario*& usuarios) {
    Usuario buffer[50];
    int num = 0;

    ifstream archivo(nombreArchivo, ios::in);

    while (archivo >> buffer[num]) {
        num++;
    }

    usuarios = new Usuario[num + 1];
    for (int i = 0; i < num; i++) {
        usuarios[i] = buffer[i];
    }
    usuarios[num].dni = -1;
}

void imprimirUsuarios(const char* nombreArchivo,
    const Usuario* usuarios) {

    ofstream archivo(nombreArchivo, ios::out);
    for (int i = 0; usuarios[i].dni != -1; i++) {
        archivo << usuarios[i] << endl;
    }
}

bool operator>>(istream& archivo, Usuario& usuario) {
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

ostream& operator<<(ostream& os, const Usuario& usuario) {
    os << left << setw(10) << usuario.dni
         << setw(20) << usuario.nombre
         << setw(20) << usuario.correo
         << setw(5) << usuario.membresia;
    return os;
}

char* leerCadena(istream& archivo, char delimitador) {
    char buffer[100];
    archivo.getline(buffer, 100, delimitador);

    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);

    return cadena;
}