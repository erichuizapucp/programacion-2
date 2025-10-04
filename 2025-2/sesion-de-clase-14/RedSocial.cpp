//
// Created by Eric Huiza on 9/26/25.
//

#include "RedSocial.h"

#include "Comparadores/CompararEdad.h"
#include "Filtros/FiltroEdad.h"

RedSocial::RedSocial() {
    this->usuarios = nullptr;
    this->cantUsuarios = 0;
    this->capacidad = 0;
}

int compararUsuarios(const void* a, const void* b) {
    Usuario usuarioA = *(Usuario*)a;
    Usuario usuarioB = *(Usuario*)b;

    return usuarioA.getEdad() - usuarioB.getEdad();
}

void RedSocial::cargarUsuarios(const char* nombreArchivo) {
    Usuario usuario;
    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> usuario) *this += usuario;

    // qsort(usuarios, cantUsuarios, sizeof(Usuario),
    //     [](const void* a, const void* b) {
    //         Usuario usuarioA = *(Usuario*)a;
    //         Usuario usuarioB = *(Usuario*)b;
    //
    //         return usuarioA.getEdad() - usuarioB.getEdad();
    //     });

    // qsort(usuarios, cantUsuarios, sizeof(Usuario),
    //     CompararEdad::descendente);

    qsort(usuarios, cantUsuarios, sizeof(Usuario),
        compararUsuarios);
}

Usuario& RedSocial::operator[](int indice) const {
    if (indice > cantUsuarios) {
        exit(1);
    }
    return usuarios[indice];
}

Usuario& RedSocial::at(int indice) const {
    return (*this)[indice];
}

RedSocial& RedSocial::operator+=(const Usuario& usuario) {
    if (cantUsuarios == capacidad) {
        incrementar();
    }
    usuarios[cantUsuarios++] = usuario;
    return *this;
}

void RedSocial::incrementar() {
    capacidad += 5;
    if (usuarios == nullptr) {
        usuarios = new Usuario[capacidad];
    }
    else {
        Usuario* aux = new Usuario[capacidad];
        for (int i = 0; i < cantUsuarios; i++) {
            aux[i] = usuarios[i];
        }
        delete[] usuarios;
        usuarios = aux;
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

    FiltroEdad filtro(22);

    for (int i = 0; i < this->cantUsuarios; i++) {
        // Usuario usuario = this->usuarios[i];
        Usuario usuario = at(i);
        if (!filtro(usuario.getEdad())) {
            continue;
        }
        archivo << left << setw(15) << usuario.getCuenta()
                << left << setw(25) << usuario.getNombre()
                << left << setw(30) << usuario.getCorreo()
                << left << setw(20) << usuario.getFacultad()
                << left << setw(15) << usuario.getFechaRegistro()
                << left << setw(5) << usuario.getEdad() << endl;
    }
}

RedSocial::~RedSocial() {
    delete[] usuarios;
}