#include <iostream>

#include "Cadena.h"
#include "ManejadorCadenas.h"

using namespace std;

int main() {
    Cadena cad1;
    cad1 = "01: Starwars";
    Cadena cad2("may the force be with you.");
    Cadena cad3 = ", ";
    cad2.swap(cad3);

    Cadena cad4 = cad1 + cad2 + cad3;

    cout << cad4 << endl;

    Cadena cad5 = "02: Starwars, may the force be with you.";
    if (cad4 == cad5) {
        cout << "Las cadenas son iguales." << endl;
    } else {
        cout << "Las cadenas son diferentes." << endl;
    }

    if (cad4 > cad5) {
        cout << "Cad4 es alfabeticamente mayor que cad5" << endl;
    }
    else {
        cout << "Cad5 es alfabeticamente mayor que cad4" << endl;
    }

    ManejadorCadenas manejador;
    manejador.cargarCadenas("cadenas.txt");
    manejador.imprimirCadenas();

    return 0;
}
