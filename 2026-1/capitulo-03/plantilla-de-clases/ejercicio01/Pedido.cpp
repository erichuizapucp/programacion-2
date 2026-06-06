#include "Pedido.h"

Pedido::Pedido() : Registro() {
    this->clienteDni = 0;
    this->codigo = nullptr;
    this->plato = nullptr;
}

Pedido::Pedido(const char* codigo, int clienteDni, const char* plato) : Pedido() {
    this->setCodigo(codigo);
    this->setClienteDni(clienteDni);
    this->setPlato(plato);
} 

Pedido::Pedido(const Pedido& orig) : Pedido() {
    *this = orig;
}

int Pedido::getClienteDni() const {
    return clienteDni;
}

void Pedido::setClienteDni(int clienteDni) {
    this->clienteDni = clienteDni;
}

char* Pedido::getCodigo() const {
    return codigo;
}

void Pedido::setCodigo(const char* codigo) {
    if (this->codigo) {
        delete[] this->codigo;
    }
    
    this->codigo = new char[strlen(codigo) + 1];
    strcpy(this->codigo, codigo);
}

char* Pedido::getPlato() const {
    return plato;
}

void Pedido::setPlato(const char* plato) {
    setCadena(this->plato, plato);
}

istream& Pedido::leer(istream& archivo) {
    char* codigo = leerCadena(archivo);
    if (!archivo || codigo[0] == '\0') {
        delete[] codigo;
        archivo.setstate(ios::failbit);
        return archivo;
    }

    int clienteDni;
    archivo >> clienteDni;
    archivo.ignore();

    char* plato = leerCadena(archivo, '\n');

    this->setCodigo(codigo);
    this->setClienteDni(clienteDni);
    this->setPlato(plato);

    delete[] codigo;
    delete[] plato;

    return archivo;
}

Pedido& Pedido::operator=(const Pedido& pedido) {
    if (this == &pedido) {
        return *this;
    }

    this->setCodigo(pedido.getCodigo());
    this->setClienteDni(pedido.getClienteDni());
    this->setPlato(pedido.getPlato());
    
    return *this;
}

ostream& Pedido::imprimir(ostream& os) const {
    os 
        << left << setw(10) << (this->getPrioridad() == ALTA ? "Si" : "No")
        << setw(15) << this->codigo
        << setw(15) << this->clienteDni
        << setw(50) << this->plato
        << endl;

    return os;
}

Pedido::~Pedido() {
    delete[] codigo;
    delete[] plato;
}
