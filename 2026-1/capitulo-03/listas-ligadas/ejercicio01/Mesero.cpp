#include "Mesero.h"

Mesero::Mesero() {
    this->sueldo = 0.0;
    this->experiencia = 0;
}

Mesero::Mesero(
    int dni, 
    const char* nombre, 
    double sueldo, 
    int experiencia
) : Persona(dni, nombre) {
    this->sueldo = sueldo;
    this->experiencia = experiencia;
}

Mesero::Mesero(const Mesero& orig) : Persona(orig) {
    this->sueldo = 0.0;
    this->experiencia = 0;

    *this=orig;
}

double Mesero::getSueldo() const {
    return sueldo;
}

void Mesero::setSueldo(double sueldo) {
    this->sueldo = sueldo;
}

int Mesero::getExperiencia() const {
    return experiencia;
}

void Mesero::setExperiencia(int experiencia) {
    this->experiencia = experiencia;
}

istream& Mesero::leer(istream& archivo) {
    if (!Persona::leer(archivo)) {
        archivo.setstate(ios::failbit);
        return archivo;
    }

    double sueldo;
    int experiencia;

    archivo >> sueldo;
    archivo.ignore();

    archivo >> experiencia;
    archivo.ignore();

    this->setSueldo(sueldo);
    this->setExperiencia(experiencia);

    return archivo;
}


Mesero& Mesero::operator=(const Mesero& mesero) {
    Persona::operator=(mesero);
    this->setSueldo(mesero.getSueldo());
    this->setExperiencia(mesero.getExperiencia());
    
    return *this;
}

ostream& Mesero::imprimir(ostream& os) const {
    Persona::imprimir(os);
    os 
        << right << setw(15) << fixed << setprecision(2) << this->sueldo
        << setw(15) << this->experiencia
        << endl;

    return os;
}
