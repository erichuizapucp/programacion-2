//
// Created by Eric Huiza on 10/6/25.
//

#include "Publicacion.h"

Publicacion::Publicacion() {
    id = 0;
    fecha = 0;
    cuenta = nullptr;
    menciones = nullptr;
    texto = nullptr;
}

Publicacion::Publicacion(const Publicacion& origen) : Publicacion() {
    *this = origen;
}

int Publicacion::getId() const {
    return id;
}

void Publicacion::setId(int id) {
    this->id = id;
}

int Publicacion::getFecha() const {
    return fecha;
}

void Publicacion::setFecha(int fecha) {
    this->fecha = fecha;
}

char* Publicacion::getCuenta() const {
    return cuenta;
}

void Publicacion::setCuenta(char* cuenta) {
    delete[] this->cuenta;
    if (cuenta) {
        this->cuenta = new char[strlen(cuenta) + 1];
        strcpy(this->cuenta, cuenta);
    }
    else {
        this->cuenta = nullptr;
    }
}

char** Publicacion::getMenciones() const {
    return menciones;
}

void Publicacion::setMenciones(char** menciones) {
    if (this->menciones) {
        for (int i = 0; this->menciones[i] != nullptr; ++i) {
            delete[] this->menciones[i];
        }
        delete[] this->menciones;
    }

    if (menciones) {
        int count = 0;
        while (menciones[count] != nullptr) ++count;

        this->menciones = new char*[count + 1];

        for (int i = 0; menciones[i]; ++i) {
            this->menciones[i] = new char[strlen(menciones[i]) + 1];
            strcpy(this->menciones[i], menciones[i]);
        }

        this->menciones[count] = nullptr;
    } else {
        this->menciones = nullptr;
    }
}

char* Publicacion::getTexto() const {
    return texto;
}

void Publicacion::setTexto(char* texto) {
    delete[] this->texto;
    if (texto) {
        this->texto = new char[strlen(texto) + 1];
        strcpy(this->texto, texto);
    }
    else {
        this->texto = nullptr;
    }
}

Publicacion& Publicacion::operator=(const Publicacion& origen) {
    if (this == &origen) {
        return *this;
    }
    this->setId(origen.getId());
    this->setFecha(origen.getFecha());
    this->setCuenta(origen.getCuenta());
    this->setMenciones(origen.getMenciones());
    this->setTexto(origen.getTexto());
    return *this;
}

void Publicacion::cargarMenciones(istream& archivo, char**& menciones) {
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

bool Publicacion::leerMencion(istream& archivo, char*& mencion) {
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

istream& operator>>(istream& archivo, Publicacion& publicacion) {
    if (int id; archivo >> id) {
        archivo.ignore();

        int anho, mes, dia;
        archivo >> anho;
        archivo.ignore();
        archivo >> mes;
        archivo.ignore();
        archivo >> dia;
        archivo.ignore();
        int fecha = anho * 10000 + mes * 100 + dia;

        char* cuenta = publicacion.leerCadena(archivo);

        archivo.ignore(); // ignorar el [
        char** menciones;
        publicacion.cargarMenciones(archivo, menciones);

        archivo.ignore(); // ignorar el espacio después del ']'
        char* texto = publicacion.leerCadena (archivo, '\n');

        publicacion.setId(id);
        publicacion.setFecha(fecha);
        publicacion.setCuenta(cuenta);
        publicacion.setTexto(texto);
        publicacion.setMenciones(menciones);

        delete[] cuenta;
        delete[] texto;
        delete[] menciones;

        return archivo;
    }

    return archivo;
}

ostream& operator<<(ostream& archivo, const Publicacion& publicacion) {
    int fecha = publicacion.getFecha();
    const char* texto = publicacion.getTexto();

    archivo << "[";
    publicacion.imprimirFecha(archivo);
    archivo << "]" << " " << texto << endl;

    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;
    archivo << "CUENTAS MENCIONADAS" << endl;
    archivo << setfill('-') << setw(40) << "" << setfill(' ') << endl;

    for (int i = 0; publicacion.getMenciones()[i]; i++) {
        archivo << publicacion.getMenciones()[i] << endl;
    }

    return archivo;
}

void Publicacion::imprimirFecha(ostream& archivo) const {
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

char* Publicacion::leerCadena(istream& archivo, char delim) {
    char buffer[100];
    archivo.getline(buffer, 100, delim);
    char* cadena = new char[strlen(buffer) + 1];
    strcpy(cadena, buffer);
    return cadena;
}

Publicacion::~Publicacion() {
    delete[] cuenta;
    delete[] texto;
    delete[] menciones;
}