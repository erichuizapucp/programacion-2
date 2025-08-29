#include <iostream>

#include "estructuras.h"
#include "funciones.h"

using namespace std;

int main() {
    CadenaDeCaracteres cad {};
    !cad;

    cad <= "Valentina Gutierrez";
    cad <= 10;

    CadenaDeCaracteres cad2 {};
    cad2 <= "Hola Mundo";
    CadenaDeCaracteres cad3 {};
    cad3 <= cad2;

    cad += " - ";
    cad += cad2;

    return 0;
}