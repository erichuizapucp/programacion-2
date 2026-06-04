#include "Biblioteca.h"

using namespace std;

int main() {
    Biblioteca biblioteca;
    biblioteca.cargarLibros();
    biblioteca.cargarEstantes();
    biblioteca.posicionarLibros();
    biblioteca.mostrarDatos();
    return 0;
}
