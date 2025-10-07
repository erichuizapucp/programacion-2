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

void RedSocial::cargarUsuarios(const char* nombreArchivo) {
    Usuario usuario;
    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> usuario) {
        *this += usuario;
    }

    // qsort(usuarios, cantUsuarios, sizeof(Usuario),
    //     [](const void* a, const void* b) {
    //         Usuario usuarioA = *(Usuario*)a;
    //         Usuario usuarioB = *(Usuario*)b;
    //
    //         return usuarioA.getEdad() - usuarioB.getEdad();
    //     });
    // qsort(usuarios, cantUsuarios, sizeof(Usuario), CompararEdad::descendente);
    qsort(usuarios, cantUsuarios, sizeof(Usuario), compararUsuarios);
}

void RedSocial::cargarPublicaciones(const char* nombreArchivo) {
    Publicacion publicacion;
    ifstream archivo(nombreArchivo, ios::in);
    while (archivo >> publicacion) {
        const char* cuenta = publicacion.getCuenta();
        Usuario& usuario = (*this)[cuenta];
        usuario += publicacion;
    }
}


Usuario& RedSocial::operator[](int indice) const {
    if (indice > cantUsuarios) {
        exit(1);
    }
    return usuarios[indice];
}

Usuario& RedSocial::operator[](const char* cuenta) const {
    for (int i = 0; i < cantUsuarios; i++) {
        if (strcmp(usuarios[i].getCuenta(), cuenta) == 0) {
            return usuarios[i];
        }
    }

    cerr << "No existe el usuario con cuenta: " << cuenta << endl;
    exit(1);
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

void RedSocial::generarReporte(const char* nombreArchivo) const {
    ofstream archivo(nombreArchivo, ios::out);
    for (int i = 0; i < cantUsuarios; i++) {
        archivo << at(i) << endl;
        archivo << endl << endl;
    }
}

RedSocial::~RedSocial() {
    delete[] usuarios;
}

int compararUsuarios(const void* a, const void* b) {
    Usuario usuarioA = *(Usuario*)a;
    Usuario usuarioB = *(Usuario*)b;

    return usuarioA.getEdad() - usuarioB.getEdad();
}