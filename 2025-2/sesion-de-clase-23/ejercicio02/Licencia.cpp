#include "Licencia.h"

bool Licencia::cargarDatos(ifstream& archivo) {
    if (!archivo.eof() && archivo >> codigo) {
        archivo.ignore();
        getline(archivo, nombre, ',');
        getline(archivo, descripcion, '\n');
        
        return true;
    }
    return false;
}

void Licencia::imprimir(ostream& archivo) const {
    archivo 
            << setw(5) << codigo 
            << setw(20) << nombre 
            << setw(100) << descripcion 
            << endl;
}

int Licencia::getCodigo() const {
    return codigo;
}

void Licencia::setCodigo(int codigo) {
    this->codigo = codigo;
}

string Licencia::getDescripcion() const {
    return descripcion;
}

void Licencia::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

string Licencia::getNombre() const {
    return nombre;
}

void Licencia::setNombre(string nombre) {
    this->nombre = nombre;
}
