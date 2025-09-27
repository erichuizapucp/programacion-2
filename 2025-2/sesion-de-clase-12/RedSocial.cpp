//
// Created by Eric Huiza on 9/26/25.
//

#include "RedSocial.h"

RedSocial::RedSocial() {
    this->usuarios = nullptr;
    this->cantUsuarios = 0;
}

void RedSocial::cargarUsuarios(const char* nombreArchivo) {
    Usuario buffer[20];
    Usuario usuario;

    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> usuario) {
        buffer[cantUsuarios++] = usuario;
    }

    this->usuarios = new Usuario[this->cantUsuarios];
    for (int i = 0; i < this->cantUsuarios; i++) {
        this->usuarios[i] = buffer[i];
    }
}

void RedSocial::generarReporteUsuarios(const char* nombreArchivo) const {
    ofstream archivo(nombreArchivo, ios::out);
    archivo << left << setw(15) << "CUENTA"
            << left << setw(25) << "NOMBRE"
            << left << setw(30) << "CORREO"
            << left << setw(20) << "FACULTAD"
            << left << setw(15) << "F. REGISTRO"
            << left << setw(5) << "EDAD" << endl;

    for (int i = 0; i < this->cantUsuarios; i++) {
        Usuario usuario = this->usuarios[i];
        archivo << left << setw(15) << usuario.getCuenta()
                << left << setw(25) << usuario.getNombre()
                << left << setw(30) << usuario.getCorreo()
                << left << setw(20) << usuario.getFacultad()
                << left << setw(15) << usuario.getFechaRegistro()
                << left << setw(5) << usuario.getEdad() << endl;
    }
}