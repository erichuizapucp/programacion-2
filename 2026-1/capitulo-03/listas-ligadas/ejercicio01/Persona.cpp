#include "Persona.h"

Persona::Persona() : Registro() {
    this->dni = 0;
    this->nombre = nullptr;
}

Persona::Persona(int dni, const char* nombre) : Persona() {
    this->dni = dni;
    this->setNombre(nombre);
}

Persona::Persona(const Persona& orig) : Registro(orig) {
    this->dni = 0;
    this->nombre = nullptr;
    *this = orig;
}

int Persona::getDni() const {
    return dni;
}

void Persona::setDni(int dni) {
    this->dni = dni;
}

char* Persona::getNombre() const {
    return this->nombre;
}

void Persona::setNombre(const char* nombre) {
    setCadena(this->nombre, nombre);
}

istream& Persona::leer(istream& archivo) {
    int dni;
    if (!archivo.eof() && archivo >> dni) {
        archivo.ignore();
        char* nombre = leerCadena(archivo);

        this->setDni(dni);
        this->setNombre(nombre);
    } else {
        archivo.setstate(ios::failbit);
    }

    return archivo;
}

Persona& Persona::operator=(const Persona& persona) {
    if (this == &persona) {
        return *this;
    }

    this->setDni(persona.getDni());
    this->setNombre(persona.getNombre());
    
    return *this;
}

ostream& Persona::imprimir(ostream& os) const {
    os << left << setw(15) << this->dni
        << setw(50) << this->nombre;
    return os;
}

Persona::~Persona() {
    delete[] nombre;
}

