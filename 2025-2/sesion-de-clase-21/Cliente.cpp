#include "Cliente.h"

Cliente::Cliente() {
    this->correo = nullptr;
    this->telefono = nullptr;
}

Cliente::Cliente(
    int dni, 
    const char* nombre, 
    const char* telefono, 
    const char* correo
) : Persona(dni, nombre) {
    this->correo = nullptr;
    this->telefono = nullptr;

    this->setTelefono(telefono);
    this->setCorreo(correo);
}

Cliente::Cliente(const Cliente& orig) : Persona(orig) {
    this->correo = nullptr;
    this->telefono = nullptr;

    *this = orig;
}

char* Cliente::getCorreo() const {
    return correo;
}

void Cliente::setCorreo(const char* correo) {
    setCadena(this->correo, correo);
}

char* Cliente::getTelefono() const {
    return telefono;
}

void Cliente::setTelefono(const char* telefono) {
    setCadena(this->telefono, telefono);
}

Cliente& Cliente::operator=(const Cliente& cliente) {
    if (this == &cliente) {
        return *this;
    }

    Persona::operator=(cliente);
    this->setTelefono(cliente.getTelefono());
    this->setCorreo(cliente.getCorreo());
    
    return *this;
}

istream& Cliente::leer(istream& archivo) {
    if (!Persona::leer(archivo)) {
        archivo.setstate(ios::failbit);
        return archivo;
    }

    char* telefono = leerCadena(archivo);
    char* email = leerCadena(archivo, '\n');

    this->setTelefono(telefono);
    this->setCorreo(email);

    delete[] telefono;
    delete[] email;

    return archivo;
}


ostream& Cliente::imprimir(ostream& os) const {
    Persona::imprimir(os);
    os 
        << setw(20) << this->telefono
        << setw(20) << this->correo
        << endl;

    return os;
}

Cliente::~Cliente() {
    delete[] this->telefono;
    delete[] this->correo;
}
