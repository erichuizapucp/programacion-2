//
// Created by Eric Huiza on 9/26/25.
//

#include "RedSocial.h"

void RedSocial::cargarUsuarios(const char* nombreArchivo) {
    Usuario buffer[100];
    Usuario usuario;

    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> usuario) {
        buffer[cantidad++] = usuario;
    }

    this->usuarios = new Usuario[this->cantidad];
    for (int i = 0; i < this->cantidad; i++) {
        usuarios[i] = buffer[i];
    }
}

void RedSocial::generarReporteUsuarios(const char* nombreArchivo) const {
    ofstream archivo(nombreArchivo, ios::out);

    for (int i = 0; i < this->cantidad; i++) {
        archivo << this->usuarios[i] << endl;
    }
}
