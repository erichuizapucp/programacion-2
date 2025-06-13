#include "Registro.h"

bool operator>>(ifstream& archivo, Registro& registro) {
    return registro.cargarDatos(archivo);
}

ostream& operator<<(ostream& os, const Registro& registro) {
    registro.imprimir(os);
    return os;
}